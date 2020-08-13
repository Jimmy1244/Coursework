#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int avail = 0;
typedef struct {
	double coef;
	unsigned int expo;
}polynomial;

int comp(unsigned int a, unsigned int b) {
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

void addPolynomial(int SE[][2], polynomial * poly) {
	int aP = SE[0][0], bP = SE[1][0];
	while (aP <= SE[0][1] && bP <= SE[1][1]) {
		if (comp(poly[aP].expo, poly[bP].expo) == 0) {
			poly[avail].coef = poly[aP].coef + poly[bP].coef;
			if (poly[avail].coef) {
				poly[avail].expo = poly[aP].expo;
				avail++;
			}
				aP++; bP++;
		}
		else if (comp(poly[aP].expo, poly[bP].expo) == -1) {
			poly[avail].coef = poly[bP].coef;
			poly[avail].expo = poly[bP].expo;
			bP++;
			avail++;
		}
		else if (comp(poly[aP].expo, poly[bP].expo) == 1) {
			poly[avail].coef = poly[aP].coef;
			poly[avail].expo = poly[aP].expo;
			aP++;
			avail++;
		}
	}
	for (; aP <= SE[0][1]; aP++) {
		poly[avail].coef = poly[aP].coef;
		poly[avail].expo = poly[aP].expo;
		aP++;
		avail++;
	}
	for (; bP <= SE[1][1]; bP++) {
		poly[avail].coef = poly[bP].coef;
		poly[avail].expo = poly[bP].expo;
		bP++;
		avail++;
	}
}

void printPoly(int S, int E, polynomial *poly) {
	int a = S;
	for (; a <= E; a++) {
		if (a == S && poly[a].coef == 0) {
			printf("%.2f", poly[a].coef);
		}
		else if (a == S) {
			if (poly[a].expo == 0)
				printf("%.2f", poly[a].coef);
			else if (poly[a].expo == 1)
				printf("%.2fx", poly[a].coef);
			else	
				printf("%.2fx^%u", poly[a].coef, poly[a].expo);
		}
		else if (poly[a].expo == 0) {
			poly[a].coef < 0 ? printf(" %.2f", poly[a].coef) : printf(" +%.2f", poly[a].coef);
		}
		else if (poly[a].expo == 1) {
			if (poly[a].coef < 0)
				printf(" %.2fx", poly[a].coef, poly[a].expo);
			else if (poly[a].coef > 0)
				printf(" +%.2fx", poly[a].coef, poly[a].expo);
		}
		else if (poly[a].expo > 1) {
			if (poly[a].coef < 0)
				printf(" %.2fx^%u", poly[a].coef, poly[a].expo);
			else if (poly[a].coef > 0)
				printf(" +%.2fx^%u", poly[a].coef, poly[a].expo);
		}
	}
	printf("\n");
}

int main() {
	polynomial poly[100];
	int num, times = 2, i = 0, j;
	int abSE[2][2] = { 0 }, cS;
	while (i < times) {
		scanf("%d", &num);
		j = 0;
		if (num > 0)
			while (j < num) {
			scanf("%lf%u", &poly[avail].coef, &poly[avail].expo);
			avail++;
			j++;
		}
		else {
			poly[avail].coef = 0;
			poly[avail].expo = 0;
			avail++;
			j++;
		}
		cS = avail;
		if (i == 0) {
			abSE[i][i] = 0;
			abSE[i][i + 1] = avail - 1;
			abSE[i + 1][i] = avail;
		}
		else abSE[i][i] = avail - 1;
		i++;
	}
	addPolynomial(abSE, poly);
	printPoly(abSE[0][0], abSE[0][1], poly);
	printPoly(abSE[1][0], abSE[1][1], poly);
	printPoly(cS, avail - 1, poly);
	return 0;
}