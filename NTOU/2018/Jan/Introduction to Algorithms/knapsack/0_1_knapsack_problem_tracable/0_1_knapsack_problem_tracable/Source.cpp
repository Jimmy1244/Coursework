#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct item {
	int num;
	int weight;
	int value;
}items;

int max;
char record[8000][200] = { 0 };

void makeTable(items* itemARR, int inum, int ** maxtable, int maxKnapsack) {//inum - 1�O������J
	maxtable[inum][0] = 0;
	int i;
	for (i = 0; i < maxKnapsack; i++) {
		if (i + 1 - itemARR[inum - 1].weight < 0)//��e�I�]�W���p��n�[�J�����~���q
			maxtable[inum][i + 1] = maxtable[inum - 1][i + 1];//���W�@�h����
		else {
			int newNum = itemARR[inum - 1].value + maxtable[inum - 1][i - itemARR[inum - 1].weight + 1];//�ΤW�@�h�����G
			maxtable[inum][i + 1] = newNum > maxtable[inum - 1][i + 1] ? newNum : maxtable[inum - 1][i + 1];//�ΤW�������G�򥿤W���
			if(newNum > maxtable[inum - 1][i + 1])
				record[itemARR[inum - 1].num][i + 1] = 1;
		}
	}
	max = maxtable[inum][i];
}

int main() {//��Xweight = 1 �� totalWeight ���̤j�զ���k�A�C�@�ؤ�k�i�H���e�����M
	int totalWeight, i = 0, ** maxtable;
	scanf("%d", &totalWeight);
	maxtable = (int **)malloc(sizeof(int *) * 8000 + sizeof(int) * 8000 * (totalWeight + 1));
	int *p, j;
	for (p = (int *)(maxtable + 8000), j = 0; i < 8000; i++, p += (totalWeight + 1)) {
		maxtable[i] = p;
	}
	items itemsArr[8000];
	for (j = 0; j < totalWeight + 1; j++) {//�Ĥ@����k�s
		maxtable[0][j] = 0;
	}
	i = 0;
	while (scanf("%d%d%d", &itemsArr[i].num, &itemsArr[i].weight, &itemsArr[i].value)) {
		if (itemsArr[i].num == -1 && itemsArr[i].weight == -1 && itemsArr[i].value == -1) {
			break;
		}
		i++;
		for (j = 0; j < totalWeight; j++) {//�o�̬O�N�n�Q��諸
			maxtable[i][j + 1] = 0;
		}
		makeTable(itemsArr, i, maxtable, totalWeight);
	}
	for (j = i - 1; j >= 0; j--) {
		if(record[itemsArr[j].num][totalWeight]){
			printf("%d ", itemsArr[j].num);//�]����ɭp�ⳣ�Oinum-1�b��
			totalWeight -= itemsArr[j].weight;//record�쪺���q���U
		}
	}
	printf("\n%d\n", max);
}