#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int comp(char * str1, char * str2) {
	int a = 0;
	while (str1[a] != '\0') {
		if (str1[a] != str2[a]) return 0;
		a++;
	}
	return 1;
}

int main() {
	char str1[20], str2[20];
	scanf("%[^\n]", str1);
	int a = 0, b = 0;
	while (str1[a] != '\0') a++;
	while (a) {
		str2[b++] = str1[--a];
	}
	str2[b] = '\0';
	if (comp(str1, str2))printf("%s is a palindrome.\n", str1);
	else printf("%s is not a palindrome.\n", str1);
	return 0;
}