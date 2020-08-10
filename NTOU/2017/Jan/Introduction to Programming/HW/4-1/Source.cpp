#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int c, t, a, n,repeat,count;
	repeat = 0;
	while (repeat < 2) {
		printf("c = "); scanf("%d", &c);
		printf("t = "); scanf("%d", &t);
		printf("a0 = "); scanf("%d", &a);
		printf("n = "); scanf("%d", &n);
		printf("a_0 = %d\n", a);
		count = 1;
		while (count<=n) {
			a = a*c + t;
			printf("a_%d = %d\n", count, a);
			count++;
		}
		printf("\n");
		repeat++;
	}
	return 0;
}