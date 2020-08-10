#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int number[20], count, repeat = 0, mxi;
	while (repeat < 3) {
		count = 0;
		mxi = 0;
		printf("Numbers in this array: ");
		while (count < 20) {
			scanf("%d", &number[count]);
			if (number[count] < number[mxi]) {
				mxi = count;
			}
			count++;
		}
		printf("a[] = {%d",number[0]);
		for (count = 1; count < 20; count++) {
			printf(", %d", number[count]);
		}
		printf("}\n");
		printf("The (first) minimum value is at a[%d] which is %d.\n\n", mxi, number[mxi]);
		repeat++;
	}
	return 0;
}