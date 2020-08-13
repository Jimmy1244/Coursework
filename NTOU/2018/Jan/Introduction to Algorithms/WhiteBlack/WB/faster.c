#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct nod node;

struct nod {
	int e;//degree和連到哪一個node
	node *cn;
	char b;//黑色
};

int stackP[2000], stackT[2000], top, n, k, max, sum, topP;

void backtracking(node * nodesArr, int p) {
	if ((n - p + 1) / 2 + sum < max) return;
	if (p == n + 1) {//到最後一個節點
		if (max < sum) {
			topP = top;
			max = sum;
			int i;
			for (i = 0; i < top + 1; i++) {
				stackP[i] = stackT[i];
			}
		}
		else if (max == sum && nodesArr[p].b) {
			topP = top;
			max = sum;
			int i;
			for (i = 0; i < top + 1; i++) {
				stackP[i] = stackT[i];
			}
		}
		return;
	}
	node *thread = nodesArr[p].cn;
	while (thread && p > thread->e) {
		if (nodesArr[thread->e].b) {
			break;
		}
		thread = thread->cn;
	}
	if (!thread || p < thread->e) {//找不到黑的邊//該node填黑
		sum++;
		nodesArr[p].b = 1;
		stackT[++top] = p;
		backtracking(nodesArr, p + 1);
		sum--;
		nodesArr[p].b = 0;
		top--;
	}
	backtracking(nodesArr, p + 1);//都可以填白色看看
}

int main() {
	int g, n1, n2;
	node * thread;
	scanf("%d", &g);
	while (g--) {
		node nodes[85000] = { 0 };//大括弧可以初始化為0
		top = -1;
		scanf("%d%d", &n, &k);
		int i;
		for (i = 0; i < k; i++) {
			scanf("%d%d", &n1, &n2);
			thread = &nodes[n1];//別讓thread = nodes[n1].cn，不然thread之後會被改掉
			while (thread->cn) {
				thread = thread->cn;//往下一個走
			}
			thread->cn = (node *)malloc(sizeof(node));
			thread = thread->cn;
			thread->e = n2;
			thread->cn = NULL;
			thread = &nodes[n2];
			while (thread->cn) {
				thread = thread->cn;//往下一個走
			}
			thread->cn = (node *)malloc(sizeof(node));
			thread = thread->cn;
			thread->e = n1;
			thread->cn = NULL;
		}
		sum = 0;
		max = 0;
		backtracking(nodes, 1);
		printf("%d\n%d", max, stackP[0]);//從1開始
		i = 1;
		while (i < topP + 1) {
			printf(" %d", stackP[i]);
			i++;
		}
		printf("\n");
	}
}