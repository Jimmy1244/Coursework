#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int nums[50000];

void merge(int head, int quan) {
	int *A = (int *)malloc(sizeof(int) * ((quan % 2 + (quan >> 1)) + 1));
	int *B = (int *)malloc(sizeof(int) * ((quan >> 1) + 1));
	int i;
	for (i = 0; (i < quan % 2 + (quan >> 1)); i++) {
		A[i] = nums[head + i];
	}
	for (i = 0; i < quan >> 1; i++) {
		B[i] = nums[head + (quan >> 1) + quan % 2 + i];
	}
	A[(quan % 2 + (quan >> 1))] = INT_MAX;
	B[(quan >> 1)] = INT_MAX;
	int Ap = 0, Bp = 0;
	for (i = 0; i < quan; i++) {
		nums[head + i] = A[Ap] < B[Bp] ? A[Ap++] : B[Bp++];
	}
	free(A);
	free(B);
}

void mergeSort(int head, int quan) {
	if (quan < 2) return;
	mergeSort(head, quan % 2 + (quan >> 1));
	mergeSort(head + (quan >> 1) + quan % 2, quan >> 1);
	merge(head, quan);
}

int main() {
	int total = 0;
	while (scanf("%d", &nums[total]) != EOF) {
		total++;
	}
	mergeSort(0, total);
	int i = 0;
	while (i < total) {
		printf("%d ", nums[i]);
		i++;
	}
	printf("\n");
	return 0;
}