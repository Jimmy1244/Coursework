#define _CRT_SEUCRE_NO_WARNINGS

#include<stdio.h>

void delspace(char *str){
	int countSpace = 0;
	char *p, *q;
	for (q = str; *q != '\0'; q++){}
	q--;
	while (*q == ' ') {
		*q = '\0';
		q--;
	}
	q = str;
	while (*q == ' '){
		q++;
	}
	p = str;
	while (*q != '\0'){
		*p = *q;
		if (*q == ' ')while (*q == ' '){
			q++;
		}
		else q++;
		p++;
	}
	*p = '\0';
}

int main() {
		char str1[] = "Test    string    1";
		char str2[] = "   Test string    2   ";
		char str3[] = "    ";
		printf("Before:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);
		delspace(str1);
		delspace(str2);
		delspace(str3);
		printf("\nAfter:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);
		return 0;
}