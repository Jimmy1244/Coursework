#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int repeattimesstraight, repeattimesplus, repeattimesmoney,size,i=0;
	for (i = 0; i < 2; i++) {
		printf("Size: ");
		scanf("%d", &size);
		for (repeattimesstraight = 0; repeattimesstraight < size; repeattimesstraight++) {
			for (repeattimesplus = 0; (repeattimesplus +repeattimesstraight+6) < size; repeattimesplus++) {
				printf("+");
			}
			for (repeattimesmoney = 0; (repeattimesmoney+repeattimesplus+repeattimesstraight)< size; repeattimesmoney++) {
				printf("$");
			}
			for (repeattimesplus = 0; repeattimesplus < size; repeattimesplus++) {
				if (repeattimesplus + repeattimesstraight >= size)
					printf("+");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}