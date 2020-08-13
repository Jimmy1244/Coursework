#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

/*typedef struct treeL * treeP;
typedef struct treeL{
	int data;
	treeP left;
	treeP right;
}tree;*/

const int size = 1000;

void bubble(int *a, int pos) {
	if (!a[pos] && !a[pos + 1]) return;
	a[pos] = a[pos * 2];
	a[pos + 1] = a[pos * 2 + 1];
	bubble(a, pos * 2);
	bubble(a, pos * 2 + 1);
}

int numPos(int *a, int key) {
	int i;
	for (i = 0; i < size; i++) {
		if (key == a[i]) break;
	}
	return i;
}

void printTree(int *tree) {
	int max = 0, root = 1, leftF = 1;
	for (root = 0; root < size; root++) {
		if (max < tree[root]) max = tree[root];
	}//找最大
	root = 1;
	while (tree[root] <= max) {
		if (leftF > 0) printf("%d ", tree[root]);
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

int main() {
	int num = 0, tree[1000] = { 0 }, root = 1;
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
	printf("Binary search tree:\n");
	printTree(tree);
	printf("\n");
	while (scanf("%d", &num) != EOF) {
		root = numPos(tree, num);
		if (root == size) {
			printf("no %d this node!\n\n", num);
			continue;
		}
		int temp = root;
		/*if (tree[root * 2])//判斷該用左還右*/ temp *= 2;
		while (tree[temp * 2 + 1] != 0) {
			temp = temp * 2 + 1;
		}
		tree[root] = tree[temp];
		tree[temp] = tree[temp * 2];
		bubble(tree, temp * 2);
	}
	printf("After delete:\n");
	printTree(tree);
	return 0;
}