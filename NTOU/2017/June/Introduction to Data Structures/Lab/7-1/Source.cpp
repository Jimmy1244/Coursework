#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct {
	int year, month, day;
}date;

int isLeapYear(int year) {
	if (year % 400 == 0) return 1;
	else if (year % 100 == 0) return 0;
	else if (year % 4 == 0) return 1;
	return 0;
}

int main() {
	int times;
	int monthDays[12] = { 31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31 };
	scanf("%d", &times);
	while (times) {
		date a, b;
		int i;
		int answer, aMD = 0, bMD = 0;
		scanf("%4d/%2d/%2d", &a.year, &a.month, &a.day);
		scanf("%4d/%2d/%2d", &b.year, &b.month, &b.day);
		for (i = 0; i < a.month - 1; i++) {
			aMD = aMD + monthDays[i];
			if (isLeapYear(a.year) && i == 1)
				aMD += 1;
				
		}
		aMD += a.day;
		for (i = 0; i < b.month - 1; i++) {
			bMD = bMD + monthDays[i];
			if (isLeapYear(b.year) && i == 1)
				bMD += 1;
		}
		bMD += b.day;
		int yD = 0;
		for (i = a.year; i < b.year; i++) {
			if (isLeapYear(i)) yD += 366;
			else yD += 365;
		}
		answer = yD + bMD - aMD;
		printf("%d\n", answer);
		times--;
	}
	return 0;
}