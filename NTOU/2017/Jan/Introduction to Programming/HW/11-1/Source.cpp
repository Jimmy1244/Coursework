#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
char * myStrRchr(char * sentence, char c) {
	int i;
	for (i = 0; sentence[i] != '\0'; i++);
	for (i = i - 1; sentence[i] != c; i--);
	if (i < 0) return NULL;
	return  &sentence[i];
}

int main() {
	int i, j;
	for (i = 0; i < 2; i++) {
		char sent[1000], ch;
		for (j = 0; j < 1000; j++) {
			sent[j] = '\0';
		}
		char *p;
		printf("Input a string: ");
		fgets(sent, 1000, stdin);
		sent[strlen(sent) - 1] = '\0';//
		printf("Divided by what symbol: ");
		scanf("%c", &ch);
		getchar();
		printf("Results:\n");
		printf("[%s]\n", sent);
		while (myStrRchr(sent, ch) != NULL) {
			p = myStrRchr(sent, ch);
			*p = '\0';
			printf("[%s]\n", sent);
		}
		printf("\n");
	}
	return 0;
}