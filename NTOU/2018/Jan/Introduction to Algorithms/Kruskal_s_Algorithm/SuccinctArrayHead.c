#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct edge {
	int s;
	int e;
	int credit;
}edges;

int cmp(const void *a, const void *b) {
	edges eA = *(edges *)a; edges eB = *(edges *)b;
	return eA.credit - eB.credit;
}

int Kru(edges * edg, int size, int max) {
	int *head = (int *)malloc (sizeof(int) * (max + 1));
	int i, cost = 0, counts = 1;
	for (i = 0; i < max + 1; i++) {
		head[i] = -1;
	}
	for (i = 0; i < size; i++) {
		if (head[edg[i].s] == head[edg[i].e] && head[edg[i].s] != -1) continue;
		printf("%d: <%d,%d>\n", counts++, edg[i].s, edg[i].e);
		cost += edg[i].credit;
		if (head[edg[i].s] == -1 && head[edg[i].e] != -1) {//大的出現過了
			if (edg[i].s < head[edg[i].e]) {
				head[edg[i].s] = edg[i].s;
				int b = head[edg[i].e], k;
				for (k = 0; k < max + 1; k++) {
					if (head[k] == b) head[k] = edg[i].s;
				}
			}
			else {
				head[edg[i].s] = head[edg[i].e];
			}
		}
		else if (head[edg[i].e] == -1 && head[edg[i].s] != -1) {//小的出現過了
				head[edg[i].e] = head[edg[i].s];//應該只斯要這行就好
		}
		else if (head[edg[i].e] == -1 && head[edg[i].s] == -1) {
			head[edg[i].e] = edg[i].s;
			head[edg[i].s] = edg[i].s;
		}
		else {//兩邊各不同頭
			int s = head[edg[i].e] < head[edg[i].s] ? head[edg[i].e] : head[edg[i].s];
			int b = head[edg[i].e] > head[edg[i].s] ? head[edg[i].e] : head[edg[i].s];
			int k;
			for (k = 0; k < max + 1; k++) {
				if (head[k] == b) head[k] = s;
			}
		}
	}
	return cost;
}

void printAdjancencyList(edges *edg, int max, int size) {
	int i, k;
	int **link = (int **)calloc((max + 1) * (max + 1), sizeof(int *));
	int *p;
	for (i = 0, p = (int*)(link + max + 1); i < max + 1; i ++ , p += max + 1) {
		link[i] = p;
	}
	for (i = 0; i < size; i++) {
		link[edg[i].s][edg[i].e] = 1;
		link[edg[i].e][edg[i].s] = 1;
	}
	for (i = 0; i < max + 1; i++) {
		printf("%d: ", i);
		for (k = 0; k < max + 1; k++) {
			if (link[i][k] == 1) printf("%d -> ", k);
		}
		printf("end\n");
	}
}

int main() {
	edges edgesA[30000];
	int count = 0, max = 0;
	printf("Adjacency list:\n");
	while (scanf("%d%d%d", &edgesA[count].s, &edgesA[count].e, &edgesA[count].credit) != EOF) {
		if (max < edgesA[count].e) max = edgesA[count].e;
		count++;
	}
	printAdjancencyList(edgesA, max, count);
	printf("\nminimum spanning tree:\n");
	qsort(edgesA, count, sizeof(edges), cmp);
	printf("\nThe cost of minimum spanning tree: %d\n", Kru(edgesA, count, max));
}