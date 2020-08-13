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
		if (tWei + things[i].weight <= 20) {//前面隨便拿
			push(obtains, things[i]);
		}
		else{//超出重量
			int tempT = top;//暫時的top，為了往下找
			while (tempT > -1) {
				if (tWei - obtains[tempT].weight + things[i].weight <= 20 && obtains[tempT].value <= things[i].value) {//下一個物品V.S.以得物品(條件如果設 < 20，第一個側資就對)
					tWei = tWei - obtains[tempT].weight + things[i].weight;
					tVal = tVal - obtains[tempT].value + things[i].value;
					obtains[tempT] = things[i];
					tempT = top;
					break;
				}
				else tempT--;//已得物品往下找
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