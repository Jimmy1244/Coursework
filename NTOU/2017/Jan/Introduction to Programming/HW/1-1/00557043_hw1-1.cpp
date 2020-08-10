#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int n, i;
	for (i = 0; i < 4; i++) {
		scanf("%d", &n);
		if (n % 5 == 0) {
			printf("%d is a multiple of 5.\n", n);
		}
		if (n % 7 == 0) {
			printf("%d is a multiple of 7.\n", n);
		}
	}
	return 0;
}