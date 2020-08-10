#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
bool isLeapYear(int year) {
	if (year % 400 == 0) return true;
	else if (year % 100 == 0) return false;
	else if (year % 4 == 0) return true;
	return false;
}

int isInvalidDate(int year, int month, int day) {
	int monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year)) monthday[1] += 1;
	if (year < 1 || month < 1 || month > 12) return 1;
	else if (day < 1 || day > monthday[month-1]) return 1;
	return 0;
}

int main() {
	int t, year, month, day;
	for (t = 0; t < 5; t++) {
		printf("Input a date (year/month/day): ");
		scanf("%d/%d/%d", &year, &month, &day);
		printf("%d/%d/%d %s a valid date.\n\n", year, month, day, isInvalidDate(year, month, day) ? "is not" : "is");
	}
	return 0;
}
