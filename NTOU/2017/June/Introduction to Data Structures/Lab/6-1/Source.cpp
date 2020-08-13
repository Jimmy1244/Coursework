#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int top = -1;

typedef struct{
	int row;
	int col;
}stack;

void push(stack path[], int row, int col) {
	path[++top].row = row;
	path[top].col = col;
}

int main() {
	int row, col, stRow, stCol, i, j, found = 0, dir = 0, endR, endC;
	int maxTop = 0;
	stack path[100];
	scanf("%d\t%d\t%d\t%d\t%d\t%d", &row, &col, &stRow, &stCol, &endR, &endC);
	row += 2;
	col += 2;
	int **a = (int **)malloc(sizeof(int *) * row);
	int *p = (int *)malloc(sizeof(int) * row * col);
	for (i = 0; i < row; i++, p += col)
		a[i] = p;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			a[i][j] = 1;
		}
	}
	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	a[stRow][stCol] = 1;
	printf("The path is:\n");
	push(path, stRow, stCol);
	while (!found) {
		switch (dir) {
		case 0:
			if (a[stRow - 1][stCol] == 0) {
				stRow -= 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 1:
			if (a[stRow - 1][stCol + 1] == 0) {
				stRow -= 1;
				stCol += 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 2:
			if (a[stRow][stCol + 1] == 0) {
				stCol += 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 3:
			if (a[stRow + 1][stCol + 1] == 0) {
				stCol += 1;
				stRow += 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 4:
			if (a[stRow + 1][stCol] == 0) {
				stRow += 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 5:
			if (a[stRow + 1][stCol - 1] == 0) {
				stRow += 1;
				stCol -= 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 6:
			if (a[stRow][stCol - 1] == 0) {
				stCol -= 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		case 7:
			if (a[stRow - 1][stCol - 1] == 0) {
				stCol -= 1;
				stRow -= 1;
				a[stRow][stCol] = 1;
				push(path, stRow, stCol);
				dir = 0;
			}
			else dir++;
			break;
		}
		if (maxTop < top) maxTop = top;
		if ((path[top].row == endR && path[top].col == endC )|| (top == 0 && dir == 8)) found = 1;
		else if (dir == 8) {
			dir = 0;
			top--;
			stRow = path[top].row;
			stCol = path[top].col;
		}
	}
	for (i = 0; i <= maxTop; i++) {
		printf("(%d,%d)\n", path[i].row, path[i].col);
	}
	return 0;
}