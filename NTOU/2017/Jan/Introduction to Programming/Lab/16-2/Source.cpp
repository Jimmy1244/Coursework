#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char * mystrtok(char str[], char brk[]) {
	static char *nextp = NULL;
	char *q = str;
	if (str != NULL) nextp = str;
	if (nextp != NULL) {
		while (*nextp != '\0' && strchr(brk, *nextp) != NULL) nextp++;
		if (*nextp == '\0') nextp = NULL;
	}
	if (nextp == NULL) return NULL;
	q = nextp;
/*	while (strchr(brk, *q) != NULL) q++;
	nextp = q;*/
	while (strchr(brk, *nextp) == NULL) nextp++;
	*nextp = '\0';
	nextp++;
	if (*nextp == '\0') return q;
	return q;
}

int main() {
	const int lineTotal = 4;
	char testline[lineTotal][100] = {
		"... Yes you got it!!! \\^^/",
		".,?!///\\\\!!? ..",
		"",
		"A normal test. Hope it works!"
	};
	char brk[] = "., \\/?!";
	int i; char line[100], *token;
	for (i = 0; i < lineTotal; i++) {
		printf("Testing [%s] by strtok:\n", testline[i]);
		strcpy(line, testline[i]);
		token = strtok(line, brk);
		while (token != NULL) {
			printf("\t[%s]\n", token);
			token = strtok(NULL, brk);
		}
		printf("Testing [%s] by mystrtok:\n", testline[i]);
		strcpy(line, testline[i]);
		token = mystrtok(line, brk);
		while (token != NULL) {
			printf("\t[%s]\n", token);
			token = mystrtok(NULL, brk);
		}
	}
	system("pause");
	return 0;
}