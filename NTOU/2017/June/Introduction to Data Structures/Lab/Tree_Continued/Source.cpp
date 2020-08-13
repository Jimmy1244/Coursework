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

char ope[100][4];
int i = 0;

void treeToPost(treeLP th) {
	if (i >= count || !th) return;
	treeToPost(th->left);
	treeToPost(th->right);
	strcpy(ope[i], th->data);//試試看i++
	i++;
}

int culPost() {
	int culS[100];
	int t = -1;
	int j;
	for (j = 0; j < count; j++) {
		if (ope[j][0] > 47 && ope[j][0] < 58) {
			culS[++t] = atoi(ope[j]);
		}
		else if (ope[j][0] == '*') {
			t--;
			culS[t] = culS[t] * culS[t + 1];
		}
		else if (ope[j][0] == '/') {
			t--;
			culS[t] = culS[t] / culS[t + 1];
		}
		else if (ope[j][0] == '+') {
			t--;
			culS[t] = culS[t] + culS[t + 1];
		}
		else if (ope[j][0] == '-') {
			t--;
			culS[t] = culS[t] - culS[t + 1];
		}
		else if (ope[j][0] == '%') {
			t--;
			culS[t] = culS[t] % culS[t + 1];
		}
	}
	return culS[t];
}

int main() {
	char s[100];
	scanf("%s", s);
	sp = s;
	top = newTree();
	intoTree(top);
	top = top->left;
	treeToPost(top);
	printf("%d\n", culPost());
	return 0;
}