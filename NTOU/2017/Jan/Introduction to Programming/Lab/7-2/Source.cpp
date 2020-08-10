#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
void printdivision(int numerator, int denominator) {
	int i;
	for (i = denominator; i >=2 ; i--) {
		if (denominator % i == 0 && numerator % i == 0) {
			denominator /= i;
			numerator /= i;
		}
	}
		if (numerator == 1 && denominator == 1) printf("PI");
		else if (numerator == 1) printf("PI/%d", denominator);
		else if (denominator == 1) printf("%dPI", numerator);
		else if (numerator != 1) printf("%dPI/%d", numerator, denominator);
		
}

int main() {
	const double PI = 3.1415926;
	int numerator = 1, denominator = 16;
	printf("x \t sin(x) \t cos(x) \t tan(x)\n");
	printf("0 \t 0.000000 \t 1.000000 \t 0.000000\n");
	while (numerator <= 32) {
		denominator = 16;
		printdivision(numerator, denominator);
		printf("\t ");
		printf("%f \t %f \t %f\n", sin(numerator*PI / 16), cos(numerator*PI / 16), tan(numerator * PI / 16));
		numerator++;
	}
	printf("%f", tan(2 * PI));
	return 0;
}