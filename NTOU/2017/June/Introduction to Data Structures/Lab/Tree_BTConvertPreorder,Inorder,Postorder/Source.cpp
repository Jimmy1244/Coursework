#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treeL* treeLP;
typedef struct treeL {
	char data[5];
	treeLP left;
	treeLP right;
}tree;

void intoTreeB(treeLP th);

treeLP newTree() {
	treeLP T;
	T = (treeLP)malloc(sizeof(tree));
	T->left = NULL;
	T->right = NULL;
	return T;
}

treeLP top;
int rightFlag = 0;
char *sp;
int count = 0;

void intoTree(treeLP th) {
	if (*sp == '\0') return;
	if (*sp == 40 || *sp == 41 || *sp == ',') sp++;
	else {
		count++;
		int i = 0;//放字元的位子
		if (!rightFlag) {
			th->left = newTree();
			th = th->left;
		}
		else {
			th->right = newTree();
			th = th->right;
		}
		if (*sp > 41 && *sp < 48 || *sp == 37) {
			*th->data = *sp;
			sp++;
			rightFlag = 0;
			i++;
		}
		else {
			while (*sp > 47 && *sp < 58) {
				*(th->data + i) = *sp;
				sp++;
				i++;
				rightFlag = 1;
			}
			*(th->data + i) = '\0';
			return;//數字填完回上一層
		}
		*(th->data + i) = '\0';
		intoTree(th);
	}
	intoTree(th);
}

void printTree(treeLP th, int order) {
	if (!th) return;
	if (order == 1) printf("%s ", th->data);
	printTree(th->left, order);
	if (!order) printf("%s ", th->data);
	printTree(th->right, order);
	if (order == 2) printf("%s ", th->data);
}

treeLP stack[100];

void printLevelOrder(treeLP th) {
	printf("Level-order:\n");
	int t = 0;
	stack[++t] = th;
	int i = 1;
	printf("%s ", stack[t]->data);
	while (i < count) {
		++t;
		if (stack[t / 2]) {
			stack[t] = t % 2 ? stack[t / 2]->right : stack[t / 2]->left;
			if (stack[t]) {
				i++;
				printf("%s ", stack[t]->data);
			}
		}
		else stack[t] = NULL;
	}
	printf("\n");
}

int main() {
	char s[50];
	scanf("%s", s);
	sp = s;
	top = newTree();
	intoTree(top);
	top = top->left;
	int i;
	for (i = 0; i < 3; i++) {
		if (i == 0) printf("In-order:\n");
		if (i == 1) printf("Pre-order:\n");
		if (i == 2) printf("Post-order:\n");
		printTree(top, i);
		printf("\n\n");
	}
	printLevelOrder(top);
	return 0;
}