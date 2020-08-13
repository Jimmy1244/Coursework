#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct item {
	int w;
	int v;
	double division;
}items;

int cmp(const void *a, const void * b) {
	items * na = (items*)a, *nb = (items*)b;
	double A = na->division;
	double B = nb->division;
	return A > B ? 1 : A == B ? 0 : -1;
}

int main() {
	int quan;
	scanf("%d", &quan);
	int i = 0;
	items *itemsA = (items*)malloc(sizeof(items) * 40000);
	int v, w;
	while (scanf("%d", &v) != EOF) {
		scanf("%d", &w);
		//itemsA[i] = (double)v / w + w * 1000000 + v * 1000;//打包寫法需要改良，包包的大小要動態
		itemsA[i].division = (double)v / w;//struct寫法
		itemsA[i].w = w; itemsA[i].v = v;
		i++;
	}
	qsort(itemsA, i, sizeof(items), cmp);
	double totalv = 0, totalw = 0;
	int k;
	for (k = i - 1; totalw < quan && k >= 0; k--) {
		if (itemsA[k].w + totalw > quan) break;
		totalv += itemsA[k].v;
		totalw += itemsA[k].w;
	}
	totalv += (double)(quan - totalw) / itemsA[k].w * itemsA[k].v;
	printf("%lf\n", totalv);
}