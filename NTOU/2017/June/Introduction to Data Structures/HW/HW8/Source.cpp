#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char operatorPos[6] = {'+', '-', 'a', '*', '/' , '%'};

int cmpPos(char ch1, char ch2) {
	int i, j;
	for (i = 0; i < 4; i++) {
		if (operatorPos[i] == ch1) break;
	}
	for (j = 0; j < 4; j++) {
		if (operatorPos[j] == ch2) break;
	}
	i /= 3;
	j /= 3;
	if (i <= j) return 0;
	else  return 1;
}

int main() {
	int top = -1;
	char ch[4], chS[50][4];
	char ope[50][4];
	int bracketF = 0;
	int i = 0;
	while (scanf("%s", &ch)) {
		if (ch[0] != ')' && ch[0] > 39 && ch[0] < 48 || ch[0] == '%') {
			if (top >= 0 && ch[0] != '(' && chS[top][0] != '(') {
				while (top != -1 && chS[top][0] != '(') {
					int a = cmpPos(ch[0], chS[top][0]);
					if (a == 0) {
						chS[top][1] = '\0';
						strcpy(ope[i], chS[top--]);//如果直接 assign 字串中的字元無效
						i++;
					}
					if (a == 1) {
						chS[++top][0] = ch[0];
						break;
					}
				}
				if(top == -1 || chS[top][0] == '(') chS[++top][0] = ch[0];
			}
			else {
				chS[++top][0] = ch[0];
			}
		}
		else if (ch[0] == ')') { 
			chS[top][1] = '\0';
			strcpy(ope[i], chS[top--]);
			i++;
			top--;
		}
		else {
			strcpy(ope[i], ch);
			i++;
		}
		if (getchar() == '\n') break;
	}
	while (top > -1) {
		chS[top][1] = '\0';
		strcpy(ope[i], chS[top--]);
		i++;
	}
	int culS[50];
	int j;
	top = -1;
	for (j = 0; j < i; j++) {
		if (j == i - 1)printf("%s", ope[j]);
		else printf("%s ", ope[j]);
		if (ope[j][0] > 47 && ope[j][0] < 58) {
			culS[++top] = atoi(ope[j]);
		}
		else if (ope[j][0] == '*') {
			top--;
			culS[top] = culS[top] * culS[top + 1];
		}
		else if (ope[j][0] == '/') {
			top--;
			culS[top] = culS[top] / culS[top + 1];
		}
		else if (ope[j][0] == '+') {
			top--;
			culS[top] = culS[top] + culS[top + 1];
		}
		else if (ope[j][0] == '-') {
			top--;
			culS[top] = culS[top] - culS[top + 1];
		}
		else if (ope[j][0] == '%') {
			top--;
			culS[top] = culS[top] % culS[top + 1];
		}
	}
	printf("\n");
	printf("%d\n", culS[top]);
	return 0;
}