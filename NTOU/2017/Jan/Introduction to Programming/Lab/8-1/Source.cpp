#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const int height = 6;
const int width = 6;
const int mineTotal = 10;
int mine[height + 2][width + 2];

void initialGame() {
	int i, j;
	for (i = 0; i < height + 1; i++){
		for (j = 0; j < width + 1; j++){
			mine[i][j] = 0;
		}
	}
	mine[1][width] = -1;
	mine[1][width-1] = mine[2][width-1] = mine[2][width] = 1;
}

void printGameField(){
	int i, j;
	for (i = 1; i <= height; i++) {
		for (j = 1; j <= width; j++){
			if (i == 1 && j == 1) printf("�z�w");
			else if (i == 1) printf("�s�w");
			else if (j == 1) printf("�u�w");
			else printf("�q�w");
		}
		if (i == 1) printf("�{\n");
		else printf("�t\n");
		for (j = 1; j <= width; j++){
			if (mine[i][j] == -1) printf("�x��");
			else if (mine[i][j] != 0) printf("�x%2d", mine[i][j]);
			else printf("�x�@");
		}
		printf("�x\n");
	}
	for (i = 0; i < width; i++){
		if (i == 0) printf("�|�w");
		else printf("�r�w");
	}
	printf("�}");
}
int main() {
	initialGame();
	printGameField();
	return 0;
}