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
	printf("�п�J���ڵ��ơG");
	scanf("%d", &count);
	dona = (donation *)malloc(sizeof(donation) * count);
	printf("�п�J %d �����ڸ�ơG\n", count); 
	while (i < count) {
		printf("�п�J���ڤH�m�W�B���ڤ��(�~/��/��) �M���B�G");
		varNum = scanf("%s%d/%d/%d%d", dona[i].name, &dona[i].year, &dona[i].month, &dona[i].day, &dona[i].money);
		if(varNum < 5) {
			scanf("%*s");
			scanf("%*s");
			printf("@@ ��J�榡�����T�I�uŪ�� %d ���ܼơC\n", varNum);
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