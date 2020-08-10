#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int A(int m, int n) {
	if (m == 0) return n + 1;
	if (m > 0 && n == 0) return A(m - 1, 1);
	if (m > 0 && n > 0) return A(m - 1, A(m, n - 1));
}

int main() {
	int i, j;
	for (i = 0; i <= 3; i++){
		for (j = 0; j <= 9; j++){
			printf("A(%d, %d) = %d\n", i, j, A(i, j));
		}
	}
	return 0;
}