#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main() {
	int num, tree[100] = { 0 }, root;
	double maxR = 0;
	scanf("%d", &tree[1]);
	while (getchar() != '\n') {
		scanf("%d", &num);
		root = 1;
		while (tree[root] != 0) {
			if (num > tree[root]) root = root * 2 + 1;
			if (num < tree[root]) root = root * 2;
		}
		tree[root] = num;
		if (root > maxR) maxR = root;
	}
	maxR = log(maxR + 1) / log(2);
	if (maxR > (int)maxR) maxR++;
	maxR = (int)maxR;
	printf("%.0lf\n", maxR);
	return 0;
}