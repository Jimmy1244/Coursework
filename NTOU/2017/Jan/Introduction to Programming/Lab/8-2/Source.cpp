#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int height = 6;
const int width = 6;
const int mineTotal = 10;
int mine[height + 2][width + 2];

void initialGame() {
	int i, j, k = 0, mineI, mineJ;
	for (i = 0; i < height + 1; i++){
		for (j = 0; j < width + 1; j++){
			mine[i][j] = 0;
		}
	}
	while (k < mineTotal){
		mineI = rand() % height + 1;
		mineJ = rand() % width + 1;
		if (mine[mineI][mineJ] == -1) continue;
		mine[mineI][mineJ] = -1;
		for (i = mineI - 1; i <= mineI + 1; i++){
			for (j = mineJ - 1; j <= mineJ + 1; j++) {
				if (mine[i][j] != -1) mine[i][j]++;
			}
		}
		k++;
	}
}

void printGameField(){
	int i, j;
	for (i = 1; i <= height; i++) {
		for (j = 1; j <= width; j++){
			if (i == 1 && j == 1) printf("¢z¢w");
			else if (i == 1) printf("¢s¢w");
			else if (j == 1) printf("¢u¢w");
			else printf("¢q¢w");
		}
		if (i == 1) printf("¢{\n");
		else printf("¢t\n");
		for (j = 1; j <= width; j++){
			if (mine[i][j] == -1) printf("¢x¡´");
			else if (mine[i][j] != 0) printf("¢x%2d", mine[i][j]);
			else printf("¢x¡@");
		}
		printf("¢x\n");
	}
	for (i = 0; i < width; i++){
		if (i == 0) printf("¢|¢w");
		else printf("¢r¢w");
	}
	printf("¢}");
}
int main() {
	srand((unsigned)time(NULL));
	initialGame();
	printGameField();
	return 0;
}