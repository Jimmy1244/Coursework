#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	struct donation {
		int year, month, day, money;
		char name[20];
	};
	int count, varNum, i = 0, big = 0;
	struct donation *dona;
	printf("請輸入捐款筆數：");
	scanf("%d", &count);
	dona = (donation *)malloc(sizeof(donation) * count);
	printf("請輸入 %d 筆捐款資料：\n", count); 
	while (i < count) {
		printf("請輸入捐款人姓名、捐款日期(年/月/日) 和金額：");
		varNum = scanf("%s%d/%d/%d%d", dona[i].name, &dona[i].year, &dona[i].month, &dona[i].day, &dona[i].money);
		if(varNum < 5) {
			scanf("%*s");
			scanf("%*s");
			printf("@@ 輸入格式不正確！只讀到 %d 個變數。\n", varNum);
			continue;
		}
		i++;
	}
	for (i = 0; i < count; i++) {
		varNum = strlen(dona[i].name);
		if(big < varNum) big = varNum;
	}
	for (i = 0; i < count; i++) {
		printf("%04d/%02d/%02d [%-*s] ", dona[i].year, dona[i].month, dona[i].day, big, dona[i].name);
		printf("$%7d\n", dona[i].money);
	}
	return 0;
}