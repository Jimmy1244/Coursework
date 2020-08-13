#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define maxVectrice  20

typedef struct vectrix * next;
struct vectrix {
	int data;
	char currentNeb;
	next Neb[maxVectrice];
};

void DFS(struct vectrix a) {
	char current = 0;
	while (a.Neb[current]) {
		if (!a.Neb[current]->currentNeb) {
			printf(" %d", a.Neb[current]->data);
			a.Neb[current]->currentNeb = 1;//走過了
			DFS(*a.Neb[current]);
		}
		current++;
	}
}

next queue[20];
int rear = -1, front = -1;

void BFS(struct vectrix a) {
	char current = 0;
	while (a.Neb[current]) {
		if (!a.Neb[current]->currentNeb) {
			a.Neb[current]->currentNeb = 1;//走過了
			queue[++front] = a.Neb[current];
			printf(" %d", a.Neb[current]->data);
		}
		current++;
	}
	if (rear != front) {
		BFS(*queue[++rear]);
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
	while (scanf("%d %d", &a, &b) != EOF) {
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
	}
	for (a = 1; a < maxVectrice; a++) {
		thread[a].currentNeb = 0;
	}
	printf("\nAdjacency list Depth First Search:\n0");
	DFS(thread[0]);
	for (a = 1; a < maxVectrice; a++) {
		thread[a].currentNeb = 0;
	}
	printf("\n\nAdjacency list Breadth First Search:\n0");
	BFS(thread[0]);
	printf("\n");
	return 0;
}