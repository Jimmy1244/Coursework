#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int repeat = 0, a, b, upper, n,t;
	while (repeat < 3) {
		printf("a1 = "); scanf("%d", &a);
		printf("b1 = "); scanf("%d", &b);
		printf("upper limit = "); scanf("%d", &upper);
		n = 1;
		while (a <= upper && b <= upper) {
			printf("n = %d, ", n);
			printf("(a, b) = (%d, %d)\n", a, b);
			t = a;
			a = a + 2*b + 1;
			b = 3 * t - b + 1;
			n++;
		}
		printf("\n");
		repeat++;
	}
		return 0;
}