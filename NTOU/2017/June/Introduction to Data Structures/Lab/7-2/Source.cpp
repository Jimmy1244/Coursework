#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int strLen(char *a) {
	int i = 0;
	while (*(a + i) != '\0'){
		i++;
	}
	return i;
}

int main() {
	char key[20], org[100];
	int count = 0;
	while (scanf("%s", key) != EOF) {
		scanf("%s", org);
		char *p = org;
		int answer = 0;
		while (*p != '\0') {
			int i;
			int count = 0;
			for (i = 0; i < strLen(key); i++) {
				if (p[i] == key[i])count++;
			}
			count /= strLen(key);
			if (count) answer++;
			p++;
		}
		printf("%d\n", answer);
	}
	return 0;
}