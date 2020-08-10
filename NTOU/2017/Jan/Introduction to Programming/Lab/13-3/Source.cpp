#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const int height = 9;
const int width = 9;
int puzzle[height][width] = { 0 };
bool candidate[height][width][height + 1];

void initSudoku(){
	int i, j;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			puzzle[i][j] = getchar() - 48;
		}
		getchar();
	}
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			printf("%d", puzzle[i][j]);
		}
		printf("\n");
	}
}

void printGameField(){
	int i, j;
	for (i = 0; i < height; i++){
		for (j = 0; j < 9; j++){
			if (i == 0 && j == 0) printf("שÝשש");
			else if (i == 0) printf("שחשש");
			else if (i % 3 == 0 && j == 0) printf("שאשש");
			else if (i % 3 == 0) printf("שךשש");
			else printf("שע¢w");
			if (i == 0 && j == width - 1) printf("ש‗\n");
			else if (i % 3 == 0 && j == width - 1) printf("שג\n");
			else if (j == width - 1) printf("שפ\n");
		}
		for (j = 0; j < width; j++){
			if (j == 0) {
				printf("שר");
				if (puzzle[i][j] > 0) printf(" %d", puzzle[i][j]);
				else printf("  ");
			}
			else {
				printf("¢x");
				if (puzzle[i][j] > 0) printf(" %d", puzzle[i][j]);
				else printf("  ");
			}
			if (j == width - 1) printf("שר\n");
		}
	}
	printf("שדשששםשששםשששהשששםשששםשששהשששםשששםשששו\n");
}

void removeCandidate(int i, int j, int value) {
	int m, n;
	for (m = 0; m < width; m++){
		candidate[i][m][value] = false;
	}
	for (m = 0; m < height; m++){
		candidate[m][j][value] = false;
	}
	for (m = 0; m < i / 3 * 3 + 3; m++){
		for (n = 0; n < j / 3 * 3 + 3; n++){
			candidate[m][n][value] = false;
		}
	}
	for (m = 0; m < 10; m++){
		candidate[i][j][m] = false;
	}
	candidate[i][j][value] = true;
}

void startFindSolution() {
	int i, j, k;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			for (k = 0; k < height; k++){
				candidate[i][j][k] = true;
			}
		}
	}
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			if (puzzle[i][j] != 0) removeCandidate(i, j, puzzle[i][j]);
		}
	}
}

int checkOnlyOne(int i, int j) {
	int m, count = 0, temp;
	for (m = 0; m < 10; m++){
		if (candidate[i][j][m] == false)  {
			count++;
		}
	}
	for (m = 1; m < 10; m++){
		if (candidate[i][j][m] == true){
			temp = m;
			break;
		}
	}
	if (count == 8) return temp;
	else return 0;
}

int solveBySingleSol(){
	int i, j;
	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			if (puzzle[i][j] == 0 && checkOnlyOne(i, j)) {
				puzzle[i][j] = checkOnlyOne(i, j);
				removeCandidate(i, j, puzzle[i][j]);
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	initSudoku();
	printGameField();
	startFindSolution();
	int yes = 1;
	while (yes > 0) {
		yes = 0;
		yes += solveBySingleSol();
		// yes += otherSolution(); // add other solutions in the future
	}
	printGameField();
	return 0;
}