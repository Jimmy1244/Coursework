#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int number[15], count, repeat = 0, num = 0;
	while (repeat < 4) {
		int time = 0;
		count = 1;
		printf("Numbers in this array: ");
		scanf("%d", &number[0]);
		while (count < 15) {
			scanf("%d", &number[count]);
			count++;
		}
		printf("a[] = {%d", number[0]);
		for (count = 1; count < 15; count++) {
			printf(", %d", number[count]);
		}
		printf("}\n");
		printf("Give me a number: ");
		scanf("%d", &num);
		for (count = 0; count < 15; count++) {
			if (number[count] % num == 0) {
				time++;
				if (time == 1) printf("%d's multiples in a[] are:\n", num);
				printf("a[%d], whose value is %d\n", count, number[count]);
			}
		}
		if (time == 0) printf("No %d's multiple in a[].\n", num);
		printf("\n");
		repeat++;
	}
	return 0;
}