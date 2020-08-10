#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int a(int k) {
	if (k == 0) return 0;
	else if (k % 2 == 0) return 3 * a(k - 1) - 1;
	if (k % 2 == 1) return 2 * a(k - 1) + 1;
}

int main() {
	int lower = 0, upper = 0, i, n;
	n = 0;
	while (n < 2) {
		printf("Please input two integers: ");
		scanf("%d %d", &lower, &upper);
		for (i = lower; i <= upper; i++) {
			printf("a_%d = %d\n", i, a(i));
		}
		printf("\n");
		n++;
	}
	return 0;
}