#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	char buf[20];
	int a = 0;
	while (scanf("%s", buf) != EOF) {
		while (buf[a] != '\0') a++;
		while (a) {
			printf("%c", buf[a - 1]);
			a--;
		}
		printf("\n");
	}
	return 0;
}