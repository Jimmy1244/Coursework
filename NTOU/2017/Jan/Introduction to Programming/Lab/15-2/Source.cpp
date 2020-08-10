#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct playerData {
	char name[30]; // name of the player
	int level; // level of the player
	char skill; // kongfu records which the player has learned
};

void printInfo(playerData *players, int size){
	char name[20];
	int i;
	printf("\n請輸入玩家：");
	scanf("%s", name);
	for (i = 0; i < size; i++){
		if (strcmp(players[i].name, name) == 0)
			break;
	}
	printf("\nName: %s\n", players[i].name);
	printf("Level: %d\n", players[i].level);
	if (players[i].skill & 1) printf("	鐵頭功\n");
	if (players[i].skill & 2) printf("	旋風地堂腿\n");
	if (players[i].skill & 4) printf("	金鐘罩鐵布衫\n");
	if (players[i].skill & 8) printf("	鬼影擒拿手\n");
	if (players[i].skill & 16) printf("	輕功水上飄\n");
	if (players[i].skill & 32) printf("	大力金剛腿\n");
	if (players[i].skill & 64) printf("	獅子吼\n");
	if (players[i].skill & 128) printf("	如來神掌\n");
}

int main(){
	char name[20];
	int i, k;
	FILE *fpt;
	fpt = fopen("playerData.binary", "rb");
	if (fpt == NULL) {
		printf("開檔失敗\n");
		exit(0);
	}
	fseek(fpt, 0, SEEK_END);
	int fsize = ftell(fpt);
	rewind(fpt);
	int playerTotal = fsize / sizeof(playerData);
	struct playerData *players = (playerData *)malloc(fsize + 1);
	fread(players, sizeof(playerData), playerTotal, fpt);
	int action = 0;
	while (action != 4){
		printf("1. 儲存新學會功夫\n2. 查詢玩家學會的功夫\n3. 查詢學會功夫之玩家\n4. 離開\n請輸入動作：");
		scanf("%d", &action);
		getchar();
		switch (action){
		case 2: printInfo(players, playerTotal); printf("\n"); break;
		case 1:
			printf("\n請輸入玩家：");
			scanf("%s", name);
			for (i = 0; i < playerTotal; i++){
				if (strcmp(players[i].name, name) == 0)
					break;
			}
			printf("請輸入功夫: ");
			scanf("%s", name);
			k = 0;
			if (strcmp(name, "鐵頭功") == 0) {
				k = 1;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "旋風地堂腿") == 0) {
				k = 2;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "金鐘罩鐵布衫") == 0) {
				k = 4;
					players[i].skill = players[i].skill | k;
				}
			if (strcmp(name, "鬼影擒拿手") == 0) {
				k = 8;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "輕功水上飄") == 0) {
				k = 16;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "大力金剛腿") == 0) {
				k = 32;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "獅子吼") == 0) {
				k = 64;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "如來神掌") == 0) {
				k = 128;
				players[i].skill = players[i].skill | k;
			}
			if (k == 0) printf("亂學!!\n\n");
			else printf("儲存%s學會%s成功\n\n", players[i].name, name);
			break;
		case 3: 
			k = 0;
			printf("請輸入查詢的功夫：");
			scanf("%s", name);
			if (strcmp(name, "鐵頭功") == 0) k = 1;
			if (strcmp(name, "旋風地堂腿") == 0) k = 2;
			if (strcmp(name, "金鐘罩鐵布衫") == 0) k = 4;
			if (strcmp(name, "鬼影擒拿手") == 0) k = 8;
			if (strcmp(name, "輕功水上飄") == 0) k = 16;
			if (strcmp(name, "大力金剛腿") == 0) k = 32;
			if (strcmp(name, "獅子吼") == 0) k = 64;
			if (strcmp(name, "如來神掌") == 0) k = 128;
			printf("學會這些功夫的玩家為：");
			for (i = 0; i < playerTotal; i++){
				if (players[i].skill & k && i == 0) printf("%s", players[i].name);
				else if ((players[i].skill & k)) printf(", %s", players[i].name);
			}
			printf("\n\n");
		}
	}
	return 0;
}