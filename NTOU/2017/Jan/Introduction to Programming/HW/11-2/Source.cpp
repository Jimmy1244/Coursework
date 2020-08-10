#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	char sent[1000], *p, cutStr[20];
	printf("Input a string: ");
	fgets(sent, 1000, stdin);
	sent[strlen(sent) - 1] = '\0';
	printf("Divided by what symbols: ");
	fgets(cutStr, 20, stdin);
	cutStr[strlen(cutStr) - 1] = '\0';
	p = strtok(sent, cutStr);
	while (p != NULL) {
		printf("[%s] length = %d\n", p, strlen(p));
		p = strtok(NULL, cutStr);
	}
	return 0;
}