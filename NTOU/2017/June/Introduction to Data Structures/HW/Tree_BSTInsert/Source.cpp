#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int tree[50] = { 0 }, num, root, max = 0;
		while (scanf("%d", &num) != EOF) {
			if (num > max) max = num;
			root = 1;
			while (tree[root] != 0) {
				if (num > tree[root]) root = root * 2 + 1;
				else if (num < tree[root]) root = root * 2;
			}
			tree[root] = num;
			root = 1;
			int leftF = 1;
			while (tree[root] <= max) {
				if(leftF > 0) printf("%d ", tree[root]);
				if (tree[root * 2] && leftF) {
					root = root * 2;
					leftF = 1;
				}
				else if (tree[root * 2 + 1]) {
					root = root * 2 + 1;
					leftF = 1;
				}
				else {
					if (tree[root] == max) break;
					if (root % 2) root /= 2;//是右子樹的向上兩層
					root /= 2; 
					leftF = 0;//回上一層不走左子樹
				}
			}
			printf("\n");
	}
	return 0;
}