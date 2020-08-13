#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define maxVectrice  20

typedef struct vectrix * next;
struct vectrix {
	int data;
	int currentNeb;
	next Neb[maxVectrice];
};

int main() {
	struct vectrix thread[maxVectrice];
	int a, b;
	char adjacencyMatrix[maxVectrice][maxVectrice] = { 0 };
	for (a = 0; a < maxVectrice; a++){
		thread[a].data = a;
		thread[a].currentNeb = 0;
	}
	int max = 0;
	while (scanf("%d\t%d", &a, &b)!= EOF) {
		if (a > max) max = a;
		if (b > max) max = b;
		adjacencyMatrix[a][b] = adjacencyMatrix[b][a] = 1;
		thread[a].Neb[thread[a].currentNeb++] = &thread[b];//¾F©~
		thread[b].Neb[thread[b].currentNeb++] = &thread[a];
	}
	for (a = 0; a <= max; a++) {
		thread[a].Neb[thread[a].currentNeb] = NULL;
	}//µ²§À
	printf("Adjacency matrix:\n");//¶}©l¦L
	for (a = 0; a <= max; a++) {//matrix
		for (b = 0; b < max; b++) {
			printf("%d ", adjacencyMatrix[a][b]);
		}
		printf("%d\n", adjacencyMatrix[a][b]);
	}
	printf("\nAdjacency list:\n");
	for (a = 0; a <= max; a++) {//list
		int i = 0;
		printf("%d: ", a);
		while (thread[a].Neb[i]) {
			printf("%d -> ", thread[a].Neb[i++]->data);
		}
		printf("end\n");
	}
	return 0;
}