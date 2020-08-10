#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int num, position, repeat = 0, i;
	while (repeat < 5) {
		printf("Number: ");
		scanf("%d", &num);
		printf("Position: ");
		scanf("%d", &position);
		for (i = 0; i < position; i++) {
			num /= 2;
		}
		printf("It is a %d bit.\n\n", num % 2);
		repeat++;
	}
	return 0;
}