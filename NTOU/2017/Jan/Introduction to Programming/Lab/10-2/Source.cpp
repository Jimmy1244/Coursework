#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int changeNumber(int base, char number[]) {
	int i = 0, answer = 0, realNum;
	while (i < strlen(number)) {
		if (number[i] <= 'Z' && number[i] >= 'A') 
			realNum = number[i] - 55;
		else if (number[i] <= 'z' && number[i] >= 'a') 
			realNum = number[i] - 87;
		else if (number[i] <= '9' && number[i] >= '0') 
			realNum = number[i] - 48;//當'0'減48時 == '\0'
		if (realNum >= base) break;
		answer = answer * base + realNum;
		i++;
	}
	return answer;
}

int main() {
	int base, answer;
	char number[20];
	printf("請輸入進位制：");
	scanf("%d", &base);
	printf("請輸入以該進位制表示的數: ");
	scanf("%s", number);
	printf("輸入的數以十進位表示則為 ");
	printf("%d", changeNumber(base, number));
	return 0;
}