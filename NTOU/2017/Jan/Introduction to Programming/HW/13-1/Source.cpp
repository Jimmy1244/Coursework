#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(){
	int repeat = 0, num, newNum, count;
	while(repeat < 5){
		count = 0;
		printf("Input: ");
		scanf("%d", &num);
		printf("The 1 bits are at: ");
		while (num) {
			newNum = num % 2;
			if (newNum) {
				printf("%d ", count);
			}
			count++;
			num /= 2;
		}
		repeat++;
		printf("\n\n");
	}
	return 0;
}