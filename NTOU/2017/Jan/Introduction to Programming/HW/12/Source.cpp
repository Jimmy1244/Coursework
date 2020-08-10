#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct dateData {
	int year, month, day;
};

void getdate(struct dateData *d) {
	scanf("%d/%d/%d", &d->year, &d->month, &d->day);
}

char datecmp(struct dateData data1, struct dateData data2) {
	if (data1.year > data2.year) return '>';
	else if (data1.year < data2.year) return '<';
	else if (data1.month > data2.month) return '>';
	else if (data1.month < data2.month) return '<';
	else if (data1.day > data2.day) return '>';
	else if (data1.day < data2.day) return '<';
	else return '=';
}

int main() {
	struct dateData data1, data2;
	int i = 0;
	while (i < 5) {
		printf("Input the first date (year/month/day): ");
		getdate(&data1);
		printf("Input the second date (year/month/day): ");
		getdate(&data2);
		printf("%d-%02d-%02d %c %d-%02d-%02d\n\n", data1.year, data1.month, data1.day, datecmp(data1, data2), data2.year, data2.month, data2.day);
		i++;
	}
	return 0;
}