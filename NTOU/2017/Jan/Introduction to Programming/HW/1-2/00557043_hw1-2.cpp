#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int i=1, n,ans=0;
	scanf("%d", &n);
	for ( i = 1; i <= n; i++) {
		ans = i*i*i;
		printf("%d ^ 3 = %d\n",i,ans);
	}
	return 0;
}
