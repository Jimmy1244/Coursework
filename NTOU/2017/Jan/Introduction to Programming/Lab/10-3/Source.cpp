#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
struct birthday {
	int year;
	int month;
	int day;
};
bool isLeapYear(int year);
int isInvalidDate(int year, int month, int day) {
	int monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year)) monthday[1] += 1;
	if (year < 1 || month < 1 || month > 12) return 1;
	else if (day < 1 || day > monthday[month - 1]) return 1;
	return 0;
}

bool isLeapYear(int year) {
	if (year % 400 == 0) return true;
	else if (year % 100 == 0) return false;
	else if (year % 4 == 0) return true;
	return false;
}

int zodiacCode(int month, int day) {
	int  code, beginningDay[12] = { 20, 20, 21, 21, 21, 22, 23, 23, 23, 23, 22, 22 };
	if (day >= beginningDay[month - 1]) code = (month + 9) % 12;
	if (day < beginningDay[month - 1]) code = (month + 8) % 12;
	return code;
}

char *zodiacName(int month, int day) {
	char *name[20] = { "牡羊座", "金牛座", "雙子座", "巨蟹座", "獅子座", "處女座", "天秤座", "天蠍座", "射手座", "摩羯座", "水瓶座", "雙魚座" };
	return name[zodiacCode(month, day)];
}

int main() {
	struct birthday boy, girl;
	int matchScore[12][12] = { // matchScore[girl's zodiac][boy's zodiac]
		90, 75, 82, 47, 94, 65, 85, 70, 99, 58, 88, 79,
		68, 88, 72, 75, 45, 97, 57, 78, 61, 93, 66, 81,
		79, 76, 89, 71, 81, 57, 93, 69, 86, 64, 99, 48,
		52, 82, 78, 89, 61, 84, 66, 92, 70, 87, 74, 97,
		97, 56, 79, 69, 87, 72, 81, 45, 92, 77, 84, 62,
		61, 91, 76, 88, 66, 89, 49, 81, 72, 95, 55, 84,
		85, 74, 98, 58, 88, 77, 90, 71, 80, 47, 95, 64,
		60, 80, 68, 97, 65, 84, 73, 87, 47, 76, 57, 92,
		92, 70, 81, 65, 98, 58, 86, 68, 89, 75, 78, 44,
		43, 97, 70, 80, 59, 92, 51, 85, 64, 88, 74, 77,
		72, 41, 91, 58, 78, 64, 96, 51, 82, 69, 87, 60,
		71, 78, 46, 93, 61, 65, 74, 99, 54, 82, 69, 88
	};
	printf("請輸入男生的生日。\n");
	scanf("%d/%d/%d", &boy.year, &boy.month, &boy.day);
	while (isInvalidDate(boy.year, boy.month, boy.day)) {
		printf("這不是合法的日期。\n");
		scanf("%d/%d/%d", &boy.year, &boy.month, &boy.day);
	}
	printf("請輸入女生的生日。\n");
	scanf("%d/%d/%d", &girl.year, &girl.month, &girl.day);
	while (isInvalidDate(girl.year, girl.month, girl.day)) {
		printf("這不是合法的日期。\n");
		scanf("%d/%d/%d", &girl.year, &girl.month, &girl.day);
	}
	printf("男生是%s，女生是%s\n", zodiacName(boy.month, boy.day), zodiacName(girl.month, girl.day));
	printf("兩人的速配指數是 %d!!!", matchScore[zodiacCode(girl.month, girl.day)][zodiacCode(boy.month, boy.day)]);
	return 0;
}