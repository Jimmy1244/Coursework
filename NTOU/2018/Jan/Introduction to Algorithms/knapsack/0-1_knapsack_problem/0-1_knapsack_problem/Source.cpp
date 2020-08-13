#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct item {
	int num;
	int weight;
	int value;
}items;

void makeTable(items* itemARR, int inum, int ** maxtable, int maxKnapsack) {//inum - 1是此次輸入
	maxtable[inum % 2][0] = 0;
	int i;
	for (i = 0; i < maxKnapsack; i++) {
		if (i + 1 - itemARR[inum - 1].weight < 0)//當前背包上限小於要加入的物品重量
			maxtable[inum % 2][i + 1] = maxtable[(inum + 1) % 2][i + 1];//給上一層的值
		else /*if (itemARR[inum - 1].weight * 2 <= i + 1)*/ {//i+1大於weight的一半的時候避免重複使用同一個item
			int newNum = itemARR[inum - 1].value + maxtable[(inum + 1) % 2][i - itemARR[inum - 1].weight + 1];//用上一層的結果
			maxtable[inum % 2][i + 1] = newNum > maxtable[(inum + 1) % 2][i + 1] ? newNum : maxtable[(inum + 1) % 2][i + 1];//用上面的結果跟正上方比
		}
		/*else {
			int newNum = itemARR[inum - 1].value + maxtable[inum % 2][i - itemARR[inum - 1].weight + 1];//[物品重量]的VALUE + [背包上限-物品重量]的VALUE(這一層)
			maxtable[inum % 2][i + 1] = newNum > maxtable[(inum + 1) % 2][i] ? newNum : maxtable[(inum + 1) % 2][i + 1];//後者為上一層的
		}*/
	}
}

int findMax(int ** maxtable, int lay, int totalWeight) {
	int max = 0, i;
	for (i = 1; i < totalWeight + 1; i++) {
		if (maxtable[lay % 2][i] > max) max = maxtable[lay % 2][i];
	}
	return max;
}

int main() {//找出weight = 1 到 totalWeight 的最大組成方法，每一種方法可以為前面的和
	int totalWeight, i = 0, ** maxtable, max = 0;
	scanf("%d", &totalWeight);
	maxtable = (int **)malloc(sizeof(int *) * 2 + sizeof(int) * 2 * (totalWeight + 1));
	int *p, j;
	for (p = (int *)(maxtable + 2), j = 0; i < 2; i++, p += (totalWeight + 1)) {
		maxtable[i] = p;
	}
	items itemsArr[8000];
	for (j = 0; j < totalWeight + 1; j++) {//第一行先歸零
		maxtable[0][j] = 0;
	}
	i = 0;
	while (scanf("%d%d%d", &itemsArr[i].num, &itemsArr[i].weight, &itemsArr[i].value)) {
		if (itemsArr[i].num == -1 && itemsArr[i].weight == -1 && itemsArr[i].value == -1) {
			break;
		}
		i++;
		for (j = 0; j < totalWeight; j++) {//這裡是將要被更改的
			maxtable[i % 2][j + 1] = 0;
		}
		makeTable(itemsArr, i, maxtable, totalWeight);
	}

	printf("%d\n", findMax(maxtable, i, totalWeight));
}