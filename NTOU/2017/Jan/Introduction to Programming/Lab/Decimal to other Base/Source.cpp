#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	char name[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int num, base, maxbase;
	printf("Input a number: ");
	scanf("%d", &num);
	printf("Input base: ");
	scanf("%d", &base);
	for (maxbase = 1; maxbase * base < num; maxbase *= base);
	while (maxbase >= 1) {
		if (num / maxbase < 10) {
			printf("%d", num / maxbase);
		}
		else printf("%c", name[num / maxbase % 10]);
		num %= maxbase;
		maxbase /= base;
	}
	return 0;
}