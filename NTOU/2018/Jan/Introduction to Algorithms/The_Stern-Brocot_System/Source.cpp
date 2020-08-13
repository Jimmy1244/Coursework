#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	double a, b;
	while (scanf("%lf%lf", &a, &b) != EOF) {
		if (a == 1 && b == 1)break;
		double la = 0, lb = 1, ra = 1, rb  = 0, ma = 1, mb = 1;
		while (ma != a || mb != b) {
			if (a / b > ma / mb) {
				la = ma; lb = mb;
				ma += ra; mb += rb;
				printf("R");
			}
			else {
				ra = ma; rb = mb;
				ma += la; mb += lb;
				printf("L");
			}
		}
		printf("\n");
	}
}