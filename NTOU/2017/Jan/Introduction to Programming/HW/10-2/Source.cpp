#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void duplicateStr(char dest[], char *src, int n) {
	int repeat = 0, p = 0, arraynum = 0, i;
	for (i = 0; i < 1000; i++)
		dest[i] = '\0';
	while (repeat < n) {
		while (dest[p] != '\0') p++;
		arraynum = 0;
		while (*(src + arraynum) != '\0') {
			*(dest + p + arraynum) = *(src + arraynum);
			arraynum++;
		}
		repeat++;
	}
}

int main() {
	char newStr[1000], inputStr[1000];
	int ti, rpTimes;
	for (ti = 0; ti < 5; ti++) {
		printf("Input a string: ");
		scanf("%s", inputStr);
		printf("Duplicate how many times: ");
		scanf("%d", &rpTimes);
		duplicateStr(newStr, inputStr, rpTimes);
		printf("The new string is [%s]\n", newStr);
	}
	return 0;
}