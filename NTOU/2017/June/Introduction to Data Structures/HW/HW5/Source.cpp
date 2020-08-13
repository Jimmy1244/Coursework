#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
const int max = 100;

typedef struct {
	int row;
	int col;
	int data;
}matrix;

void setPos(matrix *a, int* c) {
	int i, j, count = 1;
	for (i = 0; i < a[0].col; i++) {
		c[i] = count;
		for (j = 1; j <= a[0].data; j++) {
			if (a[j].col == i) count++;
		}
	}
}

void rotateMatrix(matrix *a, matrix * b, int * c) {
	int i = 1;
	b[0].row = a[0].row;
	b[0].col = a[0].col;
	b[0].data = a[0].data;
	while (i <= a[0].data) {
		b[c[a[i].col]].row = a[i].col;
		b[c[a[i].col]].col = a[i].row;
		b[c[a[i].col]].data = a[i].data;
		c[a[i].col]++;
		i++;
	}
}

int main() {
	matrix a[max], b[max];
	scanf("%d%d%d", &a[0].row, &a[0].col, &a[0].data);
	int i = 1;
	while (i <= a[0].data) {
		scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].data);
		i++;
	}
	int *apos = (int *)malloc(sizeof(int) * a[0].col);
	for (i = 0; i < a[0].col; i++) {
		apos[i]= 0;
	}
	setPos(a, apos);
	rotateMatrix(a, b, apos);
	for (i = 0; i <= b[0].data; i++) {
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].data);
	}
	return 0;
}