#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct nod node;

struct nod {
	int e;//degree和連到哪一個node
	node *cn;
	char t;//走過
	char b;//黑色
};

int stackP[80000], stackT[80000], top, black[80000], bt;

int decideColor(node * nodesArr, int n, char color, int bCount) {//黑色連的點一定為白，與白相連的點可黑可白
	node * thread = &nodesArr[n];

	if (color) {
		bCount++;
		thread = thread->cn;
		while (thread) {//非NULL而且沒走過
			thread->t = 0;//其他的t = 0白色
			thread = thread->cn;
		}
	}
	return bCount;
}

int main() {
	int g, n, k, n1, n2;
	node * thread;
	scanf("%d", &g);
	while (g--) {
		node nodes[80000] = { 0 };//大括弧可以初始化為0
		top = -1;
		bt = -1;
		scanf("%d%d", &n, &k);
		int i;
		for (i = 0; i < k; i++) {
			scanf("%d%d", &n1, &n2);
			thread = &nodes[n1];//別讓thread = nodes[n1].cn，不然thread之後會被改掉
			while(thread->cn) {
				thread = thread->cn;//往下一個走
			}
			thread->cn = (node *)malloc(sizeof(node));
			thread = thread->cn;
			thread->e = n2;
			thread->cn = NULL;
			nodes[n1].e++;
			thread = &nodes[n2];
			while (thread->cn) {
				thread = thread->cn;//往下一個走
			}
			thread->cn = (node *)malloc(sizeof(node));
			thread = thread->cn;
			thread->e = n1;
			thread->cn = NULL;
			nodes[n2].e++;
		}
		int sum = 0;
		for (i = 1; i < n + 1; i++) {
			if (!nodes[i].t) {
				int a = decideColor(nodes, i, 1, sum), b = decideColor(nodes, i, 0, sum);
				sum = a > b ? a : b;
			}
		}
		printf("%d\n", sum);//從1開始
		while (top) {
			top--;
			printf("%d ", stackP[top]);
		}
		printf("\n");
	}
}