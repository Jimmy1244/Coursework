#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int times = 0;
int a[8] = { 0 }, b[8] = { 0 }, c[8] = { 0 };

void printState(int quantity) {
	printf("***********************************\n");
	if (times == 0) printf("Initial State: \n");
	else printf("After Moved %d Times: \n", times);
	int i;
	printf("A: ");
	for (i = 0; i < quantity; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}
	printf("\n");
	printf("B: ");
	for (i = 0; i < quantity; i++) {
		if (b[i] != 0) printf("%d ", b[i]);
	}
	printf("\n");
	printf("C: ");
	for (i = 0; i < quantity; i++) {
		if (c[i] != 0) printf("%d ", c[i]);
	}
	printf("\n");
}

int lastZero(int *a, int size) {
	int i = 0;
	while (i < size) {
		if (a[i] == 0) break;
		i++;
	}
	return i;
}

void hanoi(int n, int *start, int *aid, int *end, int size) {
	if (n == 1) {
		if (times % 5 == 0) printState(size);
		end[lastZero(end, size)] = start[lastZero(start, size) - 1];
		start[lastZero(start, size) - 1] = 0;
		times++;
	}
	else {
		hanoi(n - 1, start, end, aid, size); 
		hanoi(1, start, aid, end, size); 
		hanoi(n - 1, aid, start, end, size); 
	}
}

int main() {
	int quantity;
	scanf("%d", &quantity);
	printf("Number of Discs: %d\n", quantity);
	int i = 0;
	while (i < quantity) {
		a[i] = quantity - i;
		i++;
	}
	hanoi(quantity, a, b, c, quantity);
	printf("***********************************\nTotal Moved %d Times: \n", times);
	printf("A: ");
	for (i = 0; i < quantity; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}
	printf("\n");
	printf("B: ");
	for (i = 0; i < quantity; i++) {
		if (b[i] != 0) printf("%d ", b[i]);
	}
	printf("\n");
	printf("C: ");
	for (i = 0; i < quantity; i++) {
		if (c[i] != 0) printf("%d ", c[i]);
	}
	printf("\n");
}