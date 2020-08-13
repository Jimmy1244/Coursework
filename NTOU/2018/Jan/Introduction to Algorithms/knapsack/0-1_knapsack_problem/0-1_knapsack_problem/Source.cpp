#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct item {
	int num;
	int weight;
	int value;
}items;

void makeTable(items* itemARR, int inum, int ** maxtable, int maxKnapsack) {//inum - 1�O������J
	maxtable[inum % 2][0] = 0;
	int i;
	for (i = 0; i < maxKnapsack; i++) {
		if (i + 1 - itemARR[inum - 1].weight < 0)//��e�I�]�W���p��n�[�J�����~���q
			maxtable[inum % 2][i + 1] = maxtable[(inum + 1) % 2][i + 1];//���W�@�h����
		else /*if (itemARR[inum - 1].weight * 2 <= i + 1)*/ {//i+1�j��weight���@�b���ɭ��קK���ƨϥΦP�@��item
			int newNum = itemARR[inum - 1].value + maxtable[(inum + 1) % 2][i - itemARR[inum - 1].weight + 1];//�ΤW�@�h�����G
			maxtable[inum % 2][i + 1] = newNum > maxtable[(inum + 1) % 2][i + 1] ? newNum : maxtable[(inum + 1) % 2][i + 1];//�ΤW�������G�򥿤W���
		}
		/*else {
			int newNum = itemARR[inum - 1].value + maxtable[inum % 2][i - itemARR[inum - 1].weight + 1];//[���~���q]��VALUE + [�I�]�W��-���~���q]��VALUE(�o�@�h)
			maxtable[inum % 2][i + 1] = newNum > maxtable[(inum + 1) % 2][i] ? newNum : maxtable[(inum + 1) % 2][i + 1];//��̬��W�@�h��
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

int main() {//��Xweight = 1 �� totalWeight ���̤j�զ���k�A�C�@�ؤ�k�i�H���e�����M
	int totalWeight, i = 0, ** maxtable, max = 0;
	scanf("%d", &totalWeight);
	maxtable = (int **)malloc(sizeof(int *) * 2 + sizeof(int) * 2 * (totalWeight + 1));
	int *p, j;
	for (p = (int *)(maxtable + 2), j = 0; i < 2; i++, p += (totalWeight + 1)) {
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
			maxtable[i % 2][j + 1] = 0;
		}
		makeTable(itemsArr, i, maxtable, totalWeight);
	}

	printf("%d\n", findMax(maxtable, i, totalWeight));
}