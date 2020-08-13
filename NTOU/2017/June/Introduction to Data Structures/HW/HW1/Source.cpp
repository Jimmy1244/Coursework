#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d+%d=%d\n%d*%d=%d\n%d-%d=%d\n%d/%d=%d...%d\n================\n", a, b, a + b, a, b, a * b, a, b, a - b, a, b, a / b, a % b);
	}
	return 0;
}