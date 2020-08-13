#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(){
	int nums[50000], i, j, total = 0, max = 0, numsTemp[50000] = { 0 };
	while (scanf("%d", &nums[total]) != EOF) {
		if (nums[total] > max) max = nums[total];
		total++;
	}
	for (i = 2; i <= total; i++) {//從兩個相加的開始比
		for (j = 0; j < i; j++) {
			numsTemp[i - 2] += nums[j];
		}
		if (numsTemp[i - 2] > max) max = numsTemp[i - 2];
	}
	for (i = 0; i < total; i++) {//減第幾個
		for (j = i + 1; j < total - 2; j++) {
			numsTemp[j] -= nums[i];
			if (numsTemp[j] > max) max = numsTemp[j];
		}
	}
	printf("%d\n", max);
	return 0;
}