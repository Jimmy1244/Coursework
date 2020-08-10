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
			realNum = number[i] - 48;//��'0'��48�� == '\0'
		if (realNum >= base) break;
		answer = answer * base + realNum;
		i++;
	}
	return answer;
}

int main() {
	int base, answer;
	char number[20];
	printf("�п�J�i���G");
	scanf("%d", &base);
	printf("�п�J�H�Ӷi����ܪ���: ");
	scanf("%s", number);
	printf("��J���ƥH�Q�i���ܫh�� ");
	printf("%d", changeNumber(base, number));
	return 0;
}