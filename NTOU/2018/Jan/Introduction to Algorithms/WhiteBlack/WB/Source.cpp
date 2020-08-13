#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct nod node;

struct nod {
	int e;//degree和連到哪一個node
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
	if (p == n + 1) {//到最後一個節點
		if (max < sum)
			changeAnswer();
		else if (max == sum && Btable[p] == 2)
			changeAnswer();
		return;
	}
	if (!Btable[p]) {//可填黑
		sum++;
		Btable[p] = 2;//表示該點為黑
		coloringBtable(nodesArr, p, 1);//把Btable填成1表示不能再黑了
		stackT[++top] = p;
		backtracking(nodesArr, p + 1);
		sum--;
		Btable[p] = 0;//表示該點為白
		coloringBtable(nodesArr, p, 0);//還原Btable
		top--;
	}
	backtracking(nodesArr, p + 1);//都可以填白色看看
}

void buildEdge(node * nodesArr, int n1, int n2) {
	node* thread = thread = &nodesArr[n1];//別讓thread = nodes[n1].cn，不然thread之後會被改掉
	while (thread->cn) {
		thread = thread->cn;//往下一個走
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
		node nodes[85000] = { 0 };//大括弧可以初始化為0
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
		printf("%d\n%d", max, stackP[0]);//從1開始
		i = 1;
		while (i < topP + 1) {
			printf(" %d", stackP[i]);
			i++;
		}
		printf("\n");
	}
}