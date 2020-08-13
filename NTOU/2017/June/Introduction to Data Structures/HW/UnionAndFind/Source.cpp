#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vectrix {
	int data;
	int parent;
}vec;

vec * v;
int quan;

void find(char *s) {
	int num[2];
	sscanf(s, "Find(%d), Find(%d)", &num[0], &num[1]);
	printf("%s: ", s);
	if(v[num[0]].parent < 0 && v[num[1]].parent < 0) printf("No\n");
	else if (v[num[0]].parent == v[num[1]].parent || v[num[1]].parent == v[num[0]].data || v[num[0]].parent == v[num[1]].data) printf("Yes\n");
	else printf("No\n");
}

void printSpace() {
	int i, j;
	for (i = 0; i < quan; i++) {
		if (v[i].parent < 0) {
			printf(" {%d", v[i].data);
			for (j = 0; j < quan; j++) {
				if (v[j].parent == v[i].data)	printf(",%d", v[j]);
			}
			printf("}");
		}
	}
	printf("\n");
}

void uni(char *s) {
	int num[2];
	sscanf(s, "Union(%d,%d)", &num[0], &num[1]);//要打Union
	if (num[0] > num[1]) {
		int temp;
		temp = num[0];
		num[0] = num[1];
		num[1] = temp;
	}
	v[num[0]].parent > 0 ? num[0] = v[num[0]].parent : 1;
	v[num[1]].parent > 0 ? num[1] = v[num[1]].parent : 1;
	v[num[0]].parent--;//改變這裡的條件即可為權重unionAndFind
	v[num[1]].parent = v[num[0]].data;
	for (num[0] = 0; num[0] < quan; num[0]++) {
		if (v[num[0]].parent == v[num[1]].data) v[num[0]].parent = v[num[1]].parent;
	}
	printf("%s:", s);
	printSpace();
}

int main() {
	scanf("%d", &quan);
	v = (vec*)malloc(sizeof(vec) * quan);
	int i;
	for (i = 0; i < quan; i++) {
		v[i].data = i;
		v[i].parent = -1;
	}
	char s[20];
	getchar();
	while (scanf("%[^\n]", s) != EOF){
		if (s[0] == 'F') find(s);
		else uni(s);
		getchar();
	}
	return 0;
}