#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int num, top = -1, i, nums[20];

void printAndcountCompose(int current, int sum) {
	while (current < num) {
		current++;
		if (sum + current < num) {
			nums[++top] = current;
			printAndcountCompose(current, sum + current);
			top--;
		}
		else if (sum + current == num) {
			nums[++top] = current;
			for (i = 0; i < top; i++) {
				printf("%d ", nums[i]);
			}
			printf("%d\n", nums[top--]);
			return;
		}
	}
}

int main() {
	scanf("%d", &num);
	int sum = 0;
	int current = 0;
	printAndcountCompose(current, sum);
	return 0;
}