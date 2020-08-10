#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char sent[300];
	int j, i = 0;
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 300; i++) {
			sent[i] = '\0';
		}
		i = 0;
		printf("Input a line:\n");
		fgets(sent, sizeof(sent), stdin);
		while (sent[i] != '\n') {
			if (sent[i] > '9' || sent[i] < '0' && sent[i] != '.' && sent[i] != '%')
				sent[i] = '_';
			i++;
		}
		printf("Modified line:\n");
		printf("%s", sent);
	}
	return 0;
}