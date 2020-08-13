#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int second, output;
	scanf("%d", &second);
	printf("%d days\n", second / (60 * 60 * 24));
	second = second % (60 * 60 * 24);
	printf("%d hours\n", second / (60 * 60));
	second = second % (60 * 60);
	printf("%d minutes\n", second / 60);
	printf("%d seconds\n", second = second % 60);
	return 0;
}