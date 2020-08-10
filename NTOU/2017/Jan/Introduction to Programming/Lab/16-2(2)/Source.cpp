#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

char *mystrtok(char str[], char brk[]) {
	static char *nextp = NULL;
	char *q;
	if (str != NULL) nextp = str;
	if (nextp != NULL) {
		while (*nextp != '\0' && strchr(brk, *nextp) != NULL) {
			nextp++;
		}
	}
	q = nextp;
	if (*nextp == '\0') nextp = NULL;
	if (nextp == NULL) return NULL;
	q = nextp;
	while (*nextp != '\0' && strchr(brk, *nextp) == NULL) {
		nextp++;
	}
	*nextp = '\0';
	nextp++;
	return q;
	/*if (str != NULL) nextp = str;
	if (nextp == NULL) return NULL;
	q = nextp;
	while (q != NULL && strchr(brk, *q) != NULL) q++;
	nextp = q;
	while (nextp != NULL && strchr(brk, *nextp) == NULL) {
		nextp++;
		if (*nextp == '\0') {
			nextp = NULL; 
			return q;
		}
	}
	if (nextp != NULL) *nextp = '\0';
	if(nextp != NULL) nextp++;
	return q;*/
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
	return 0;
}