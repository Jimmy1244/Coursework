#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int C(int n, int k) {
	if (k == 0) return 1;
	if (n == k) return 1;
	else return C(n - 1, k) + C(n - 1, k - 1);
}

int main() {
	int i, j;
	for (i = 1; i <= 6; i++) {
		for (j = 0; j <= i; j++){
			printf("C(%d, %d) = %d\n", i, j, C(i, j));
		}
	}
	return 0;
}