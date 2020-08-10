#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main() {
	int a, b, i = 0;
	while (i < 5) {
		printf("a = ");
		scanf("%d", &a);
		printf("b = ");
		scanf("%d", &b);
		printf("GCD(%d, %d) = %d", a, b, gcd(a, b));
		printf("\n\n");
		i++;
	}
	return 0;
}