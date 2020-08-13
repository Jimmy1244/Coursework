#define _CRT_SECURE_NO_WARNINGS  

#include<stdio.h>  

int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeapYear(int year) {
	if (year % 400 == 0) return 1;
	else if (year % 100 == 0) return 0;
	else if (year % 4 == 0) return 1;
	return 0;
}

int isLegalDay(int year, int month, int day) {
	if (year >= 2000) {
		if (month > 12 || month < 1) return 0;
		if (day > 0 && day <= monthDays[month - 1] + (month == 2 ? isLeapYear(year) : 0)) // month == 2 ?一定要加()
				return 1;
	}
	return 0;
}

int main() {
	int times;
	scanf("%d", &times);
	while (times) {
		int year, month, day;
		int i;
		int answer, aMD = 1, bMD = 0;
		scanf("%d%d%d", &year, &month, &day);
		if (!isLegalDay(year, month, day)) {
			printf("非合法日期\n");
			times--;
			continue;
		}
		for (i = 0; i < month - 1; i++) {
			bMD = bMD + monthDays[i];
			if (isLeapYear(year) && i == 1)
				bMD += 1;
		}
		bMD += day;
		int yD = 0;
		year--;
		yD = year * 365 + year / 4 - year / 100 + year / 400;
		char chDay[7][20] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
		answer = (yD + bMD);
		printf("%s\n", chDay[answer % 7]);
		times--;
	}
	return 0;
}