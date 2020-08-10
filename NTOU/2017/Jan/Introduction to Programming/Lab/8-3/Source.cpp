#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int height = 3;
const int width = 3;
const int mineTotal = 3;
int mine[height + 2][width + 2];

void initialGame() {
	int i, j, k = 0, mineI, mineJ;
	for (i = 0; i < height + 1; i++) {
		for (j = 0; j < width + 1; j++) {
			mine[i][j] = 0;
		}
	}
	while (k < mineTotal) {
		mineI = rand() % height + 1;
		mineJ = rand() % width + 1;
		if (mine[mineI][mineJ] == -1) continue;
		mine[mineI][mineJ] = -1;
		for (i = mineI - 1; i <= mineI + 1; i++) {
			for (j = mineJ - 1; j <= mineJ + 1; j++) {
				if (mine[i][j] != -1) mine[i][j]++;
			}
		}
		k++;
	}
}

int printGameField(char a[height + 1][width + 1]) {
	int i, j, bomb = 0;
	for (i = 1; i <= height; i++) {
		for (j = 1; j <= width; j++) {
			if (i == 1 && j == 1) printf("¢z¢w");
			else if (i == 1) printf("¢s¢w");
			else if (j == 1) printf("¢u¢w");
			else printf("¢q¢w");
		}
		if (i == 1) printf("¢{\n");
		else printf("¢t\n");
		for (j = 1; j <= width; j++) {
			if (a[i][j] == 'c') printf("¢x¡½");
			else if (a[i][j] == 'f') printf("¢x¢«");
			else if (a[i][j] == 'u') {
				if (mine[i][j] == -1) {
					printf("¢x¡´");
					bomb = 1;
				}
				else if (mine[i][j] == 0) printf("¢x  ");
				else printf("¢x%d ", mine[i][j]);
			}
		}
		printf("¢x\n");
	}
	for (i = 0; i < width; i++) {
		if (i == 0) printf("¢|¢w");
		else printf("¢r¢w");
	}
	printf("¢}\n");
	return bomb;
}

void uncover(char a[height + 1][width + 1]) {
	int x, y;
	scanf("%d %d", &x, &y);
	while (x < 1 || y < 1 || x > height || y > width) {
		printf("Wrong position, input a correct position:");
		scanf("%d %d", &x, &y);
	}
	a[x][y] = 'u';
}

void flag(char a[height + 1][width + 1]) {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x < 1 || y < 1 || x > height || y > width) {
		printf("Wrong position, input a correct position:");
		return;
	}
	a[x][y] = 'f';
}

void unflag(char a[height + 1][width + 1]) {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x < 1 || y < 1 || x > height || y > width || a[x][y] != 'f') {
		return;
	}
	a[x][y] = 'c';
}

int checkFinish(char state[height + 1][width + 1]) {
	int i, j;
	for (i = 1; i < height + 1; i++) {
		for (j = 1; j < width + 1; j++) {
			if (state[i][j] == 'c') return 1;
		}
	}
	return 0;
}

int main() {
	srand((unsigned)time(NULL));
	int action, i, j;
	char state[height + 1][width + 1];
	for (i = 1; i <= height; i++) {
		for (j = 0; j <= width; j++) {
			state[i][j] = 'c';
		}
	}
	i = 0;
	initialGame();
	printGameField(state);
	while (checkFinish(state)) {
		printf("select an action:");
		scanf("%d", &action);
		if (action == 1) {
			uncover(state);
			if (printGameField(state)) return 0;;
		}
		if (action == 2) {
			flag(state);
			printGameField(state);
		}
		if (action == 3) {
			unflag(state);
			printGameField(state);
		}
		i++;
	}
	return 0;
}