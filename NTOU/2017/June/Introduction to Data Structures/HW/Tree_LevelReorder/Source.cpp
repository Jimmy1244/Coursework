#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	int pos;
}tree;

tree sTree[100];
int sTTop = -1, pre[100], preTop = -1;

int pop() {
	if (sTTop > -1) {
		printf("%7d - ", sTree[sTTop].data);
		pre[++preTop] = sTree[sTTop].data;
	}
	sTTop--;
	return sTree[sTTop + 1].pos;
}

void toPreorder(int *a, int size) {
		int i = pop();
		while (sTTop > -2) {
			i = (i + 1) * 2;//為了不浪費陣列0
			if (a[i]) {
				sTree[++sTTop].data = a[i];
				sTree[sTTop].pos = i;
			}
			if (a[i - 1]) {
				sTree[++sTTop].data = a[i - 1];
				sTree[sTTop].pos = i - 1;
			}
			i = 0;
			while (i <= sTTop) {
				printf("%d ", sTree[i].data);
				i++;
			}
			printf("\n");
			i = pop();
		}
}

int main() {
	int a[100] = { 0 }, i = 0;
	while (scanf("%d", a + i) != EOF) {
		i++;
	}
	printf("Current - Stack\n        - %d \n", a[0]);
	sTree[++sTTop].data = a[0];
	sTree[sTTop].pos = 0;
	toPreorder(a, i);
	printf("\n");
	printf("Preorder traversal:\n");
	for (i = 0; i <= preTop; i++) {
		printf("%d ", pre[i]);
	}
	printf("\n");
	return 0;
}