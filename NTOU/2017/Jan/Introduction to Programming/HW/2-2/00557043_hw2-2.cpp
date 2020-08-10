#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int price, age, gender, i;
	for (i = 0; i < 4; i++) {
		printf("Original Price: ");
		scanf("%d", &price);
		printf("Age: ");
		scanf("%d", &age);
		printf("Gender (0=female, 1=male): ");
		scanf("%d", &gender);
		if (age >= 65) {
			price = price * 6 / 10;
		}
		if (gender == 0) {
			price = price * 9 / 10;
		}
		printf("Real price is %d.\n\n", price);

	}
	return 0;
}