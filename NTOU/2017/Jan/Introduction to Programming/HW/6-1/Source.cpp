#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int A[20][20], B[20][20], C[20][20] = { 0 }, Am = 0, An = 0, Bp = 0, m, p, k;
	printf("A is a matrix with m x n elements and\nB is a matrix with n x p elements.\nInput values of m, n, p: ");
	scanf("%d%d%d", &Am, &An, &Bp);
	printf("Input numbers in A: ");
	for (m = 0; m < Am; m++) {
		for (p = 0; p < An; p++) {
			scanf("%d", &A[m][p]);
		}
	}
	printf("Input numbers in B: ");
	for (m = 0; m < An; m++) {
		for (p = 0; p < Bp; p++) {
			scanf("%d", &B[m][p]);
		}
	}
	for (m = 0; m < Am; m++) {
		for (p = 0; p < Bp; p++) {
			for (k = 0; k < An; k++) {
				C[m][p] = C[m][p] + A[m][k] * B[k][p];
				}
		}
	}
	printf("Numbers in C are:\n");
	printf("{");
	for (m = 0, p = 0; m < Am; m++, p = 0) {
		printf("{%d", C[m][p]);
		for (p = 1 ; p < Bp; p++) {
			printf(", %d", C[m][p]);
		}
		printf("}");
		if (m < Am - 1) printf(",\n");
		else printf("}");
	}
	return 0;
}