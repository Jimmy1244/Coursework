#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int tree[2000] = { 0 };
int quan, node, total, last;
void treeA(int index);

void inputTree(int index) {
	scanf("%d", &tree[index * 2]);
	scanf("%d", &tree[index * 2 + 1]);
	if (tree[index * 2 + 1] == 0) {
		last = tree[index * 2];
	}
	else { 
		if (tree[index * 2] != 0) total++;
		last = tree[index * 2 + 1]; 
	}
	total++;
}

void cmpT(int index) {
	if (node == tree[index * 2]) {
		inputTree(index * 2);
		if (tree[index * 2 + 1] != 0) treeA(index);
		else treeA(index + 1);
	}
	else if (node == tree[index * 2 + 1]) {
		inputTree(index * 2 + 1);
		if(tree[index * 2]) treeA(index * 2);
		else treeA(index * 2 + 1);
	}
	else cmpT(index+1);//123456¥Î¨ì 
}

void treeA(int index) {
	if (total < quan) {
		scanf("%d", &node);
		cmpT(index);
	}
}

int main() {
	int index = 1;
	scanf("%d", &quan);
	scanf("%d", tree + index);
	total = 1;
	inputTree(index);
	treeA(index);
	index = 1;
	while (tree[index] != last) {
		printf("%d ", tree[index]);
		index++;
	}
	/*if (last == 9) {
		printf("9 0 \n");
	}
	else*/ printf("%d\n", last);
	return 0;
}