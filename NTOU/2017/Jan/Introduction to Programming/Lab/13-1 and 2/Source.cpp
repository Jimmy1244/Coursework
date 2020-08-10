#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const int height = 9; 
const int width = 9;
int puzzle[height][width] = { 0 };
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



int main(){
	initSudoku();
	printGameField();
	return 0;
}