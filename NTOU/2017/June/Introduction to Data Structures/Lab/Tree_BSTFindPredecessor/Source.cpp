#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int orderS[20] = { 0 }, key, top = -1;

void findPIn(int* a, int root) {
	if (a[root * 2]) {
		findPIn(a, root * 2);
	}
	if (a[root] == key) {
		printf("%d ", orderS[top]);
		return;
	}
	orderS[++top] = a[root];
	if (a[root * 2 + 1]) {
		findPIn(a, root * 2 + 1);
	}
}

void findPPre(int* a, int root) {
	if (a[root] == key) {
		printf("%d ", orderS[top]);
		return;
	}
	orderS[++top] = a[root];
	if (a[root * 2]) {
		findPPre(a, root * 2);
	}
	if (a[root * 2 + 1]) {
		findPPre(a, root * 2 + 1);
	}
}

void findPPost(int* a, int root) {
	if (a[root * 2]) {
		findPPost(a, root * 2);
	}
	if (a[root * 2 + 1]) {
		findPPost(a, root * 2 + 1);
	}
	if (a[root] == key) {
		printf("%d\n", orderS[top]);
		return;
	}
	orderS[++top] = a[root];
}


int main() {
	int tree[100] = { 0 }, root, num;
	scanf("%d", &tree[1]);
	while (getchar() != '\n') {
		scanf("%d", &num);
		root = 1;
		while (tree[root] != 0) {
			if (num > tree[root]) root = root * 2 + 1;
			if (num < tree[root]) root = root * 2;
		}
		tree[root] = num;
	}
	scanf("%d", &key);
	findPIn(tree, 1);
	top = -1;
	findPPre(tree, 1);
	top = -1;
	findPPost(tree, 1);
	return 0;
}