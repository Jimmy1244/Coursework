#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct Activity {
	int se;//§Ç¸¹
	int s;
	int f;
}a;

int main() {
	a i;
	int ans[30000], count = 0, f = 0;
	scanf("%d", &i.se);
	do {
		scanf("%d%d", &i.s, &i.f);
		if (i.s >= f) {
			f = i.f;
			ans[count++] = i.se;
		}
	} while (scanf("%d", &i.se) != EOF); //!= EOF (Ctrl+ Z¨â¦¸ Enter) * 3
	f = 0;
	while (f < count) {
		printf("%d ", ans[f]);
		f++;
	}
	printf("\n");
}