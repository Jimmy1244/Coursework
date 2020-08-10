#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void swap(int *x, int *y) {
	int tmp = *x;
	if (*x > *y) {
		*x = *y;
		*y = tmp;
	}
}

void sort3(int *x, int * y, int *z) {
	int tmp1 = *x, tmp2 = *y, tmp3 = *z;
	while (*x > *y || *x > *z || *y > *z) {
		swap(x, y);
		swap(y, z);
	}
}

int main() {
	int x, y, z, ti, times;
	scanf("%d", &times);
	for (ti = 0; ti < times; ti++) {
		printf("Please input three numbers: ");
		scanf("%d%d%d", &x, &y, &z);
		sort3(&x, &y, &z);
		printf("Results after sorting: %d, %d, %d\n", x, y, z);
	}
	return 0;
}
