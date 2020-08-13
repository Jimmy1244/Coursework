#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define maxVectrice  20

typedef struct vectrix * next;
struct vectrix {
	int data;
	char currentNeb;
	char low;
	char dfn;
	next Neb[maxVectrice];
};

int dfnCount = 0;
void DFS(struct vectrix* a, int last) {
	a->low = a->dfn = dfnCount++;
	char current = 0;
	while (a->Neb[current]) {
		if (!a->Neb[current]->currentNeb) {
			a->Neb[current]->currentNeb = 1;//走過了
			DFS(a->Neb[current], a->data);
			if (a->low > a->Neb[current]->low) a->low = a->Neb[current]->low;
		}
		else if (a->Neb[current]->data != last) {//走過了但不是上一個即為backedge
			a->low = a->Neb[current]->low;
		}
		current++;
	}
}

int main() {
	struct vectrix thread[maxVectrice];
	int a, b;
	char adjacencyMatrix[maxVectrice][maxVectrice] = { 0 };
	for (a = 0; a < maxVectrice; a++) {
		thread[a].data = a;
		thread[a].currentNeb = 0;
	}
	int max = 0;
	while (scanf("%d\t%d", &a, &b) != EOF) {
		if (a > max) max = a;
		if (b > max) max = b;
		thread[a].Neb[thread[a].currentNeb++] = &thread[b];//鄰居
		thread[b].Neb[thread[b].currentNeb++] = &thread[a];
	}
	for (a = 0; a <= max; a++) {
		thread[a].Neb[thread[a].currentNeb] = NULL;
	}
	printf("Adjacency list:\n");
	for (a = 0; a <= max; a++) {//list
		int i = 0;
		printf("%d: ", a);
		while (thread[a].Neb[i]) {
			printf("%d -> ", thread[a].Neb[i++]->data);
		}
		printf("end\n");
		thread[a].currentNeb = 0;//為了之後歸零
	}
	thread[3].currentNeb = 1;//3先走過了
	DFS(&thread[3], 3);//從三開始
	printf("\n   ");
	for (a = 0; a <= max; a++) {
		printf(" %d", a);
	}
	printf("\ndfn");
	for (a = 0; a <= max; a++) {
		printf(" %d", thread[a].dfn);
	}
	printf("\nlow");
	for (a = 0; a <= max; a++) {
		printf(" %d", thread[a].low);
	}
	printf("\n");
}