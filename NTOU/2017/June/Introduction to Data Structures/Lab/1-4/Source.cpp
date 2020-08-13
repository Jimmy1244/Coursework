#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int blackBlank(short int *a, int num) {
	int i, sum = 0;
	for (i = 0; i <= num; i++) {
		sum = sum + a[i];
	}
	return sum;
}

int chances(int blanksize, int blackBlank,int inputNumbers) {//inputNumbers + 1 + (blanksize - blackBlank - inputNumbers + 1)blanksize - blackBlank - inputNumbers + 1
	int i, num = 1;
	for (i = 1; i <= blanksize - blackBlank - inputNumbers + 1; i++) {
		num = (blanksize - blackBlank + 2 - i) / i * num;
	}
	return num;
}

void printfitoBin(short int a, int size) {
	int stack[16] = { 0 };
	int i = -1;
	while (a > 0) {
		i++;
		stack[i] = a % 2;
		a /= 2;
	}
	int max = i;
	printf("0 ");
	while (i >= 0) {
		if (i == 0 && max == size - 2) printf("%d", stack[i]);
		else printf("%d ", stack[i]);
		i--;
	}
	printf("\n");
}

int main() {
	int ableBlank;
	scanf("%d", &ableBlank);
	short int *input = (short int *)malloc(sizeof(int)* ableBlank);
	short int *bitinput = (short int *)malloc(sizeof(int)* ableBlank);
	int times = 0, sum = 0, i = 0;
	int temp;
	while (sum < ableBlank) {//sum = 计计+计㎝
		scanf("%d", &temp);
		if (temp + sum > ableBlank) break;
		input[times] = temp;
		sum = sum + 1 + input[times];
		times++;
	}
	while (i <= times) {//input 锣bitwise
		bitinput[i] = (2 << input[i] - 1) - 1;//1.刚刚--times 2. 2input - 1Ωよ - 1
		i++;
	}
	int j = 0;
	int chance = chances(ableBlank, blackBlank(input, times - 1), times);
	short int *bit = (short int *)malloc(sizeof(short int) * chance + 1);//材chances块
	for (i = 0; i <= chance; i++) bit[i] = 0;
	while (j < chance) {//安砞眔だ筳フ
		for (i = 0; i < times; i++) {
			if (i < times - j) bit[j] = bit[j] | bitinput[i] << ableBlank - blackBlank(input, i) - i;//程オshift = ﹍计 - 堵 - i;
			else bit[j] = bit[j] | bitinput[i] << ableBlank - blackBlank(input, i) - i - 1;
		}
		j++;
	}
	j = 0;
	while (j < chance) {
		bit[0] = bit[0] & bit[j];
		j++;
	}
	printfitoBin(bit[0], ableBlank);
	return 0;
}