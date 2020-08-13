#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int top = -1;
float tWei = 0, tVal = 0;

typedef struct {
	char name;
	float value;
	float weight;
}object;

void push(object *bag, object in) {
	bag[++top] = in;
	tVal += in.value;
	tWei += in.weight;
}

int main() {
	object things[5];
	object obtains[5];
	int i = 0;
	while (i < 5) {
		scanf("%c%f%f", &things[i].name, &things[i].value, &things[i].weight);
		getchar();
		i++;
	}
	i = 0;
	while (i < 5 && tWei <= 20) {
		if (tWei + things[i].weight <= 20) {//�e���H�K��
			push(obtains, things[i]);
		}
		else{//�W�X���q
			int tempT = top;//�Ȯɪ�top�A���F���U��
			while (tempT > -1) {
				if (tWei - obtains[tempT].weight + things[i].weight <= 20 && obtains[tempT].value <= things[i].value) {//�U�@�Ӫ��~V.S.�H�o���~(����p�G�] < 20�A�Ĥ@�Ӱ���N��)
					tWei = tWei - obtains[tempT].weight + things[i].weight;
					tVal = tVal - obtains[tempT].value + things[i].value;
					obtains[tempT] = things[i];
					tempT = top;
					break;
				}
				else tempT--;//�w�o���~���U��
			}
		}
		i++;
	}
	for (i = top; i >=0; i--) {
		printf("%c %.1f %.1f\n", obtains[i].name, obtains[i].value, obtains[i].weight);
	}
	printf("weight:%.1f\nvalue:%.1f\n", tWei, tVal);
	return 0;
}