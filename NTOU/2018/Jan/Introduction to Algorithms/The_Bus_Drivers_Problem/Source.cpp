#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int n, d, r;
	while (scanf("%d%d%d", &n, &d, &r) && !(n == 0 && d == 0 && r == 0)) {
		int *mor = (int *)malloc(sizeof(int) * n);
		int *eve = (int *)malloc(sizeof(int) * n);
		int i;
		for (i = 0; i < n; i++) {
			scanf("%d", mor + i);
		}
		for (i = 0; i < n; i++) {
			scanf("%d", eve + i);
		}
		qsort(mor, n, sizeof(int), cmp);
		qsort(eve, n, sizeof(int), cmp);
		int cost = 0;
		for (i = 0; i < n; i++) {
			if (mor[i] + eve[n - 1 - i] > d) {
				cost += mor[i] + eve[n - 1 - i] - d;
			}
		}
		printf("%d\n", cost * r);
	}
}