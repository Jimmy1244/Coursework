#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int k;
	while (scanf("%d", &k) != EOF) {
		int total = 2 * k, num, min = k;
		while (total > k) {
			total = 2 * k;
			min++;
			num = (min) % total;
			while (num > k || num == 0 && total != 0) {
				--total;
				if (num != 0) num = (num + min - 1) % total;
				else num = (num + min) % total;
			}
		}
		printf("%d\n", min);
	}
	return 0;
}