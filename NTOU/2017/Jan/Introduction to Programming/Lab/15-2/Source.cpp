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
	printf("\n�п�J���a�G");
	scanf("%s", name);
	for (i = 0; i < size; i++){
		if (strcmp(players[i].name, name) == 0)
			break;
	}
	printf("\nName: %s\n", players[i].name);
	printf("Level: %d\n", players[i].level);
	if (players[i].skill & 1) printf("	�K�Y�\\n");
	if (players[i].skill & 2) printf("	�ۭ��a��L\n");
	if (players[i].skill & 4) printf("	�����n�K���m\n");
	if (players[i].skill & 8) printf("	���v�ள��\n");
	if (players[i].skill & 16) printf("	���\���W��\n");
	if (players[i].skill & 32) printf("	�j�O����L\n");
	if (players[i].skill & 64) printf("	��l�q\n");
	if (players[i].skill & 128) printf("	�p�ӯ��x\n");
}

int main(){
	char name[20];
	int i, k;
	FILE *fpt;
	fpt = fopen("playerData.binary", "rb");
	if (fpt == NULL) {
		printf("�}�ɥ���\n");
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
		printf("1. �x�s�s�Ƿ|�\��\n2. �d�ߪ��a�Ƿ|���\��\n3. �d�߾Ƿ|�\�Ҥ����a\n4. ���}\n�п�J�ʧ@�G");
		scanf("%d", &action);
		getchar();
		switch (action){
		case 2: printInfo(players, playerTotal); printf("\n"); break;
		case 1:
			printf("\n�п�J���a�G");
			scanf("%s", name);
			for (i = 0; i < playerTotal; i++){
				if (strcmp(players[i].name, name) == 0)
					break;
			}
			printf("�п�J�\��: ");
			scanf("%s", name);
			k = 0;
			if (strcmp(name, "�K�Y�\") == 0) {
				k = 1;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "�ۭ��a��L") == 0) {
				k = 2;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "�����n�K���m") == 0) {
				k = 4;
					players[i].skill = players[i].skill | k;
				}
			if (strcmp(name, "���v�ள��") == 0) {
				k = 8;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "���\���W��") == 0) {
				k = 16;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "�j�O����L") == 0) {
				k = 32;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "��l�q") == 0) {
				k = 64;
				players[i].skill = players[i].skill | k;
			}
			if (strcmp(name, "�p�ӯ��x") == 0) {
				k = 128;
				players[i].skill = players[i].skill | k;
			}
			if (k == 0) printf("�þ�!!\n\n");
			else printf("�x�s%s�Ƿ|%s���\\n\n", players[i].name, name);
			break;
		case 3: 
			k = 0;
			printf("�п�J�d�ߪ��\�ҡG");
			scanf("%s", name);
			if (strcmp(name, "�K�Y�\") == 0) k = 1;
			if (strcmp(name, "�ۭ��a��L") == 0) k = 2;
			if (strcmp(name, "�����n�K���m") == 0) k = 4;
			if (strcmp(name, "���v�ள��") == 0) k = 8;
			if (strcmp(name, "���\���W��") == 0) k = 16;
			if (strcmp(name, "�j�O����L") == 0) k = 32;
			if (strcmp(name, "��l�q") == 0) k = 64;
			if (strcmp(name, "�p�ӯ��x") == 0) k = 128;
			printf("�Ƿ|�o�ǥ\�Ҫ����a���G");
			for (i = 0; i < playerTotal; i++){
				if (players[i].skill & k && i == 0) printf("%s", players[i].name);
				else if ((players[i].skill & k)) printf(", %s", players[i].name);
			}
			printf("\n\n");
		}
	}
	return 0;
}