#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int repeattimes, firstnumber, lastnumber, commonratio,answer;
	for (repeattimes = 1; repeattimes <= 2; repeattimes++) {
		printf("The first number: ");
		scanf("%d", &firstnumber);
		printf("The last number: ");
		scanf("%d", &lastnumber);
		printf("Common ratio: ");
		scanf("%d", &commonratio);
		answer = 0;
		while (firstnumber<=lastnumber){
			answer = answer + firstnumber;
			firstnumber*=commonratio;
		}
		printf("The sum of this geometric series is %d.\n\n", answer);
	}
return 0;
}