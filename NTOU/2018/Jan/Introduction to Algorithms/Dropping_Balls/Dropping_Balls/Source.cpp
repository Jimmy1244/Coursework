#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	int times;
	while (scanf("%d", &times) != EOF) {
		if (times == -1) break;
		int i;
		int depth, quan;
		for (i = 0; i < times; i++) {
			int ans;
			scanf("%d%d", &depth, &quan);
			int pos = 1, j = 1;
			while (j < depth) {
				if (quan % 2 == 0)
					pos = (pos << 1) + 1;//偶數球往右
				else pos <<= 1;//奇數球往左
				if (quan > 1) {
					quan = quan / 2 + quan % 2;
				}
				j++;
			}
			printf("%d\n", pos);
		}
	}
}