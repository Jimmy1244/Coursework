#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffling(int chess[], int N) {
	int i, temp, random;
	for (i = 0; i < N; i++) {
		chess[i] = i;
	}
	for (i = N ; i > 1; i--){
		random = rand() % i;
		temp = chess[i - 1];
		chess[i - 1] = chess[random];
		chess[random] = temp;
	}
}
int main() {
	char * chinesename[14] = { "將", "士", "象", "車", "馬", "包", "卒", "帥", "仕", "相", "捙", "傌", "炮", "兵" };
	srand((unsigned)time(NULL));
	int chess[32], i;
	shuffling(chess, 32);
	for (i = 0; i < 32; i++){
		if (chess[i] < 16){
			if (chess[i] <= 15 && chess[i] >= 13) chess[i] = 12;
			if (chess[i] % 2 == 0) chess[i] = chess[i] / 2;
			else if (chess[i] % 2 == 1) chess[i] = chess[i] / 2 + 1;
		}
		if (chess[i] < 32 && chess[i] >= 16) {
			if (chess[i] <= 31 && chess[i] >= 29) chess[i] = 27;
			if (chess[i] % 2 == 0) chess[i] = chess[i] / 2 - 1;
			else if (chess[i] % 2 == 1) chess[i] = chess[i] / 2;
		}
	}
	printf("┌─┬─┬─┬─┬─┬─┬─┬─┐\n");
	for (i = 0; i < 32; i++){
		if (i % 8 == 0) printf("│");
		printf("%s│", chinesename[chess[i]]);
		if (i % 8 == 7 && i < 24) printf("\n├─┼─┼─┼─┼─┼─┼─┼─┤\n");
		if (i == 31) printf("\n");
	}
	printf("└─┴─┴─┴─┴─┴─┴─┴─┘");
	return 0;
}