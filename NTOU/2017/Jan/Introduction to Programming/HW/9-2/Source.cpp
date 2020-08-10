#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
void meanValue(double a, double b, double *aMean, double *gMean, double *hMean) {
	*aMean = (a + b) / 2;
	*gMean = sqrt(a * b);
	if (a + b == 0)
		*hMean = 0;
	else 
		*hMean = 2 * a * b / (a + b);
}

int main() {
	double a, b, aMean, gMean, hMean;
	int i;
	for (i = 0; i < 5; i++) {
		printf("Please input two numbers: ");
		scanf("%lf%lf", &a, &b);
		meanValue(a, b, &aMean, &gMean, &hMean);
		printf("The arithmetic mean of %f and %f is %f\n", a, b, aMean);
		printf("The geometric mean of %f and %f is %f\n", a, b, gMean);
		printf("The harmonic mean of %f and %f is %f\n\n", a, b, hMean);
	}
	return 0;
}