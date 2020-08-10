#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	char * monthname[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int year = 0, month = 0, day = 0, repeat = 0;
	while (repeat < 5) {
		printf("Input your birthday (year/month/day): ");
		scanf("%d/%d/%d", &year, &month, &day);
		printf("You were born in %s %d, %d.\n\n", monthname[month-1], day, year);
		repeat++;
	}
	return 0;
}