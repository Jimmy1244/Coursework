#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int inputScore(int score[], int size) {
	printf("Please input scores (-1 to terminate): ");
	int i = 0;
	scanf("%d", &score[i]);
	while (score[i] != -1 && i < size) {
		i++;
		if (i == 50) break;
		scanf("%d", &score[i]);
	}
	return i;
}

void countScore(int count[], int score[], int scoreTotal) {
	int i;
	for (i = 0; i < 10; i++) {
		count[i] = 0;
	}
	for (i = 0; i < scoreTotal; i++) {
		if (score[i] != -1) count[score[i] / 10]++;
	}
}

void printBar(int i , int count[]) {
	int j;
	printf("%2d ~ %2d ", 10 * i, 10 * i + 9);
	printf("%2d  ", count[i]);
	for (j = 0; j < count[i]; j++) {
		printf("%c", '*');
	}
	printf("\n");
}

int main() {
	int count[10], score[50], total, times, i;
	for (times = 0; times < 3; times++) {
		total = inputScore(score, 50);
		countScore(count, score, total);
		printf("Range   ##  Bar\n");
		for (i = 0; i < 10; i++)
			printBar(i , count);
		printf("\n");
	}
	return 0;
}