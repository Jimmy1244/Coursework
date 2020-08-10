#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int inputScore(int score[], int size){
	printf("Please input scores (-1 to terminate): ");
	int i = 0;
	scanf("%d", &score[i]);
	while (score[i] !=-1 && i < size) {
		i++;
		if (i == 50) break;
		scanf("%d", &score[i]);
	}
	return i;
}
int main() {
	int score[50], total, times, i;
	for (times = 0; times < 3; times++) {
		total = inputScore(score, 50);
		printf("Scores are");
		for (i = 0; i < total; i++) printf(" %d", score[i]);
		printf("\n\n");
	}
	return 0;
}
