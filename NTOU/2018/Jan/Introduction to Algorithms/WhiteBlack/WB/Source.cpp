#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct nod node;

struct nod {
	int e;//degree�M�s����@��node
	node *cn;
};

int stackP[2000], stackT[2000], top, n, k, max, sum, topP;
char * Btable;

void coloringBtable(node * nodesArr, int p, char b) {
	node *thread = nodesArr[p].cn;
	while (thread && thread->e < p) {
		thread = thread->cn;
	}
	while (thread) {
		Btable[thread->e] = b;
		thread = thread->cn;
	}
}

void changeAnswer() {
	topP = top;
	max = sum;
	int i;
	for (i = 0; i < top + 1; i++) {
		stackP[i] = stackT[i];
	}
}

void backtracking(node * nodesArr, int p) {
	if ((n - p + 1) / 2 + sum < max) return;
	if (p == n + 1) {//��̫�@�Ӹ`�I
		if (max < sum)
			changeAnswer();
		else if (max == sum && Btable[p] == 2)
			changeAnswer();
		return;
	}
	if (!Btable[p]) {//�i���
		sum++;
		Btable[p] = 2;//��ܸ��I����
		coloringBtable(nodesArr, p, 1);//��Btable��1��ܤ���A�¤F
		stackT[++top] = p;
		backtracking(nodesArr, p + 1);
		sum--;
		Btable[p] = 0;//��ܸ��I����
		coloringBtable(nodesArr, p, 0);//�٭�Btable
		top--;
	}
	backtracking(nodesArr, p + 1);//���i�H��զ�ݬ�
}

void buildEdge(node * nodesArr, int n1, int n2) {
	node* thread = thread = &nodesArr[n1];//�O��thread = nodes[n1].cn�A���Mthread����|�Q�ﱼ
	while (thread->cn) {
		thread = thread->cn;//���U�@�Ө�
	}
	thread->cn = (node *)malloc(sizeof(node));
	thread = thread->cn;
	thread->e = n2;
	thread->cn = NULL;
	thread = &nodesArr[n2];
}

int main() {
	int g, n1, n2;
	scanf("%d", &g);
	while (g--) {
		node nodes[85000] = { 0 };//�j�A���i�H��l�Ƭ�0
		top = -1;
		scanf("%d%d", &n, &k);
		Btable = (char *)calloc(n + 1, sizeof(char));
		int i;
		for (i = 0; i < k; i++) {
			scanf("%d%d", &n1, &n2);
			buildEdge(nodes, n1, n2);
			buildEdge(nodes, n2, n1);
		}
		sum = 0;
		max = 0;
		backtracking(nodes, 1);
		printf("%d\n%d", max, stackP[0]);//�q1�}�l
		i = 1;
		while (i < topP + 1) {
			printf(" %d", stackP[i]);
			i++;
		}
		printf("\n");
	}
}