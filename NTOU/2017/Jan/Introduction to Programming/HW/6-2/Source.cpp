#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
bool isLeapYear(int year) {
	if (year % 400 == 0) return true;
	else if (year % 100 == 0) return false;
	else if (year % 4 == 0) return true;
	return false;
}

int main() {
	int t, year;
	for (t = 0; t < 5; t++) {
		printf("Input a year: "); scanf("%d", &year);
		printf("%d %s a leap year.\n\n", year, isLeapYear(year) ? "is" : "is not");
	}
	return 0;
}