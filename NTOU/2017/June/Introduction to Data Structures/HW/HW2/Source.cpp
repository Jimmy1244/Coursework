#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int binarysearch1(int *num, int target, int left, int right) {
	int middle = (left + right) / 2;
	if (left != right) {
		if (target == num[middle]) return middle;
		else if (target < num[middle]) return binarysearch1(num, target, left, middle - 1);
		else if (target > num[middle]) return binarysearch1(num, target, middle + 1, right);
	}
	else return -1;
}
/*int binarysearch2(int *num, int target, int right) {
	int left = 0, middle;
	while (left < right) {
		middle = (left + right) / 2;
		if (num[middle] == target) return middle;
		else if (num[middle] > target) {
			right = middle - 1;
		}
		else if (num[middle] < target) {
			left = middle + 1;
		}
	}
	return -1;
}*/

int main() {
	int quantity;
	int target;
	scanf("%d", &target);
	scanf("%d", &quantity);
	int *numbers = (int *)malloc(sizeof(int)*quantity);
	int i = 0;
	while (i < quantity) {
		scanf("%d", numbers + i);
		i++;
	}
	printf("%d\n", binarysearch1(numbers, target, 0, quantity - 1));
	//printf("%d", binarysearch2(numbers, target, quantity - 1));
	return 0;
}