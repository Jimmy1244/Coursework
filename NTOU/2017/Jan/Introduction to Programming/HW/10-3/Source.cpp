#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void skipAndPrint(int skip, char str[],int last) {
	str[last] = '\0';
	printf("[%s]\n", str);
	while (last - skip > 0){
		str = str + skip;
		printf("[%s]\n", str);
		last -= skip;
	}
}

int findLastChar(char str[]) {
	int i;
	for (i = 0; *(str + i) != '\n'; i++);
	return i;
}

int main() {
	int repeat, skip, i = 0, strlen = 0;
	char str[1000] = { '\0' };
	printf("Repeat times: ");
	scanf("%d", &repeat);
	getchar();
	while (i < repeat){
		printf("Input a string: ");
		fgets(str, sizeof(str), stdin);
		printf("Skipping = ");
		scanf("%d", &skip);
		getchar();
		skipAndPrint(skip, str, findLastChar(str));
		i++;
	}
	return 0;
}