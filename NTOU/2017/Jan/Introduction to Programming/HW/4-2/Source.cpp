#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int number,repeat;
	repeat = 0;
	while (repeat < 3) {
		printf("Input a number: "); scanf("%d", &number);
		printf("Reverse: ");
		while (number > 0) {
			printf("%d", number % 10);
			number /= 10;
		}
		repeat++;
		printf("\n\n");
	}
	return 0;
}
