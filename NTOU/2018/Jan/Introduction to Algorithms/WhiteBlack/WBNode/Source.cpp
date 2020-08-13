#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct nod node;

struct nod {
	int e;//degree�M�s����@��node
	node *cn;
	char t;//���L
	char b;//�¦�
};

int stackP[80000], stackT[80000], top, black[80000], bt;

int decideColor(node * nodesArr, int n, char color, int bCount) {//�¦�s���I�@�w���աA�P�լ۳s���I�i�¥i��
	node * thread = &nodesArr[n];

	if (color) {
		bCount++;
		thread = thread->cn;
		while (thread) {//�DNULL�ӥB�S���L
			thread->t = 0;//��L��t = 0�զ�
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
		node nodes[80000] = { 0 };//�j�A���i�H��l�Ƭ�0
		top = -1;
		bt = -1;
		scanf("%d%d", &n, &k);
		int i;
		for (i = 0; i < k; i++) {
			scanf("%d%d", &n1, &n2);
			thread = &nodes[n1];//�O��thread = nodes[n1].cn�A���Mthread����|�Q�ﱼ
			while(thread->cn) {
				thread = thread->cn;//���U�@�Ө�
			}
			thread->cn = (node *)malloc(sizeof(node));
			thread = thread->cn;
			thread->e = n2;
			thread->cn = NULL;
			nodes[n1].e++;
			thread = &nodes[n2];
			while (thread->cn) {
				thread = thread->cn;//���U�@�Ө�
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
		printf("%d\n", sum);//�q1�}�l
		while (top) {
			top--;
			printf("%d ", stackP[top]);
		}
		printf("\n");
	}
}