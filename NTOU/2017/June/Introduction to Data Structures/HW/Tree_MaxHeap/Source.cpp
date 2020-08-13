#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int tree[100], index = 1;

void printT() {
	int i = 1;
	while (i <= index) {
		printf("%d[%d] ", i, tree[i]);
		i++;
	}
	printf("\n");
}

void intoTree(int num) {
	int temp, tempindex = index, lastindex = index / 2;
	tree[index] = num;
	while (lastindex && num > tree[lastindex]) {
		temp = tree[lastindex];
		tree[lastindex] = num;
		tree[tempindex] = temp;
		tempindex = lastindex;
		lastindex /= 2;
	}
	printT();
	index++;
}

int main() {
	int num;
	scanf("%d", &tree[index]);
	index++;
	printf("1[%d] \n", tree[index - 1]);
	while (scanf("%d", &num) != EOF) {
		intoTree(num);
	}
	return 0;
}