#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int renewP(int *arr, int len) {
	int i, p = arr[len];
	for (i = 1; i < len / 2 + 1; i++) {
		p = p < arr[i] + arr[len - i] ? arr[i] + arr[len - i] : p;
	}
	return p;
}

int answer(int * arr, int max, int obj) {
	int i, p = 0;
	for (i = obj - max; i < obj / 2 + 1; i++) {
		if(i)
		p = p < arr[i] + arr[obj - i] ? arr[i] + arr[max - i] : p;
	}
	return p;
}

int main() {
	int rodA[100000];
	int i = 1;
	scanf("%d", &rodA[0]);
	int a;
	while (scanf("%d%d", &a, &rodA[i]) && a != 0 && rodA[i] != 0) {
		rodA[i] = renewP(rodA, i);
		i++;
	}
	printf("%d\n", renewP(rodA, rodA[0]));
}