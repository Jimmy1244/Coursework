#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lenA, lenB;
char stra[40000], strb[40000];

int main() {
	scanf("%s%s", stra, strb);
	int i, max = 0, j;
	lenA = strlen(stra); lenB = strlen(strb);
	int **count = (int **)malloc(2 * (lenB) * sizeof(int *) + 2 * sizeof(int **));//(int**)也要配置
	int *p;
	for (i = 0, p = (int *)(count + 2); i < 2; i++, p += lenB)
		count[i] = p;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < lenB; j++) {
			count[i][j] = 0;
		}
	}
	int tempMax = 0;
	for (i = 0; i < lenA; i++) {
		for (j = 0; j < lenB; j++) {
			int last = 0;
			int tempLeft = j ? count[i % 2][j - 1] : 0, tempUp = i ? count[(i + 1) % 2][j] : 0;
			if (stra[i] == strb[j]) {
				last = i && j ? count[(i + 1) % 2][j - 1] + 1 : 1;//j 和 i 都要大於0
			}
			else if (tempUp < tempLeft)//左邊大於上面
				last = tempLeft;
			else//上面大於等於左邊
				last = tempUp;
			count[i % 2][j] = last;
			tempMax = count[i % 2][j];
			if (tempMax > max) max = tempMax;
		}
	}
	printf("%d\n", max);
	return 0;
}