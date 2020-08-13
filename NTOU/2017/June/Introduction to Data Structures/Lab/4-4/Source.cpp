#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int puzzle(char **str, char *target, int currentTarget, int row, int col) {
	char temp;
	if (target[currentTarget + 1] == '\0') return 1;
	if (str[row - 1][col] == target[currentTarget + 1]) {
		temp = str[row][col];
		str[row][col] = '\0';
		if (puzzle(str, target, currentTarget + 1, row - 1, col)) { 
			str[row][col] = temp;
			return 1; 
		}
		str[row][col] = temp;
	}
	if (str[row][col + 1] == target[currentTarget + 1]) {
		temp = str[row][col];
		str[row][col] = '\0';
		if (puzzle(str, target, currentTarget + 1, row, col + 1)) {
			str[row][col] = temp;
			return 1;
		}
		str[row][col] = temp;
	}
	if (str[row + 1][col] == target[currentTarget + 1]) {
		temp = str[row][col];
		str[row][col] = '\0';
		if (puzzle(str, target, currentTarget + 1, row + 1, col)) {
			str[row][col] = temp;
			return 1;
		}
		str[row][col] = temp;
	}
	if (str[row][col - 1] == target[currentTarget + 1]) {
		temp = str[row][col];
		str[row][col] = '\0';
		if (puzzle(str, target, currentTarget + 1, row, col - 1)) {
			str[row][col] = temp;
			return 1;
		}
		str[row][col] = temp;
	}
	return 0;
}

int main() {
	int N, M;
	scanf("%d", &N);
	N = N + 2;
	scanf("%d", &M);
	getchar();
	char target[100];
	char **str = (char **)malloc(sizeof(char *) * N);
	int i, j;
	char *sP = (char *)malloc(sizeof(char) * N * N);
	for (i = 0; i < N; i++, sP += N) str[i] = sP;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			str[i][j] = '\0';
		}
	}
	for (i = 1; i < N - 1; i++) {
		for (j = 1; j < N - 1; j++) {
			scanf("%c", &str[i][j]);
		}
		getchar();
	}
	int k = 0;
	int check;
	while (k < M) {
		scanf("%s", target);
		check = 0;
		for (i = 1; i < N - 1; i++) {
			for (j = 1; j < N - 1; j++) {
				if (target[0] == str[i][j]) {
					if (puzzle(str, target, 0, i, j)) {
						check = 1;
					}
				}
			}
		}
		if (check) printf("Yes\n");
		else printf("No\n");
		k++;
	}
	return 0;
}