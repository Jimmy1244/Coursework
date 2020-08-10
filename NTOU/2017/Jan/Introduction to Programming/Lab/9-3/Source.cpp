#define _CRT_SEUCRE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int width = 24;
const int height = 12;
char maze[2 * height + 1][2 * width + 1];

void initMaze() {
	int i, j;
	for (i = 0; i < 2 * height + 1; i++){
		for (j = 0; j < 2 * width + 1; j++){
			if (i == 1 && j == 0 || i == 1 && j == 1) maze[i][j] = ' ';
			else if (i % 2 == 1 && j % 2 == 1) maze[i][j] = '?';
			else maze[i][j] = '@';
		}
	}
	maze[2 * height - 1][2 * width] = ' ';
}

void creatMaze(int x, int y) {
	int count = 0, next, i;
	int offsetX[4] = { -2, 2, 0, 0 };
	int offsetY[4] = { 0, 0, -2, 2 };
	while (true){
		count = 0;
		for (i = 0; i < 4; i++) {
			if (maze[x + offsetX[i]][y + offsetY[i]] == '?') count++;
		}
		if (count == 0) return;
		do {
			next = rand() % 4;
		} while (maze[x + offsetX[next]][y + offsetY[next]] != '?');
		maze[x + offsetX[next]][y + offsetY[next]] = ' ';
		maze[x + offsetX[next] / 2][y + offsetY[next] / 2] = ' ';
		creatMaze(x + offsetX[next], y + offsetY[next]);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int i, j;
	initMaze();
	creatMaze(1, 1);
	for (i = 0; i < 2 * height + 1; i++){
		for (j = 0; j < 2 * width + 1; j++){
			printf("%c", maze[i][j]);
			if (j == 2 * width) printf("\n");
		}
	}
	return 0;
}