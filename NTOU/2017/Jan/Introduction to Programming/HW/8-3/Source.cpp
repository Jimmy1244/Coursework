#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int an(int a);
int bn(int b);

int an(int a) {
	if (a == 1) return 1;
	else return an(a - 1) + 2 * bn(a - 1) + 1;
}

int bn(int b) {
	if (b == 1) return 1;
	else return 3 * an(b - 1) - bn(b - 1) + 1;
}

int main() {
	int i, n = 0, upper;
	while (n < 2) {
		printf("What is the upper limit? ");
		scanf("%d", &upper);
		for (i = 1; an(i) <= upper || bn(i) <= upper; i++) {
			printf("n = %d, (a, b) = (%d, %d)\n", i, an(i), bn(i));
		}
		printf("\n");
		n++;
	}
	return 0;
}