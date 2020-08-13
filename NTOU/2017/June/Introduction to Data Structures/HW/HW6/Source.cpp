#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int top = -1;

void pushStack(char * a) {
	top++;
}

void popStack(char *a) {
	top--;
}

int strlen(char*a) {
	int count = 0;
	while (a[count] != '\0') {
		count++;
	}
	return count;
}

int main() {
	char a[100], b[100];
	scanf("%[^\n]", a);
	int i;
	for (i = 0; i < strlen(a); i++) {
		if (a[i] == '(') pushStack(b);
		if (a[i] == ')') popStack(b);
	}
	printf("%s\n", top == -1 ? "Yes" : "No");
	return 0;
}