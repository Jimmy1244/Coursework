#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct playerData {
	char name[50];
	int exp;
	int health;
	int mana;
	int spd;
	int atk;
};

struct monsterData {
	char name[50];
	int health;
	int spd;
	int atk;
	int exp;
};

void initialPlayer(struct playerData * player){
	printf("�п�J���a���W�l: ");
	scanf("%s", player->name);
	player->health = rand() % 251 + 1000;
	player->exp = 0;
	player->mana = rand() % 21 + 100;
	player->spd = rand() % 16 + 35;
	player->atk = rand() % 21 + 40;
}

void initialMonster(struct monsterData * monster){
	strcpy(monster->name, "�b�~�H"); //���ઽ��assign
	monster->health = rand() % 21 + 150;
	monster->spd = rand() % 16 + 35;
	monster->atk = rand() % 11 + 20;
	monster->exp = 15;
}

void  printPlayerData(struct playerData player){
	printf("%s\n��O%d, �t��%d, �����O%d, �g���%d\n\n", player.name, player.health, player.spd, player.atk, player.exp);
}

void atk_M2P(struct playerData *player, struct monsterData *monster){
	player->health -= monster->atk;
	printf("%s�����A�y��%s���� %d �I�C\n", monster->name, player->name, monster->atk);
}

void atk_P2M(struct playerData *player, struct monsterData *monster){
	monster->health -= player->atk;
	printf("%s�����A�y��%s���� %d �I�C\n", player->name, monster->name, player->atk);
	player->health += player->atk * 2;
}

int main(){
	srand((unsigned)time(NULL));
	const int monsterTotal = 1000;
	struct playerData player;
	struct monsterData monster[monsterTotal];
	int i;

	initialPlayer(&player);
	for (i = 0; i < monsterTotal; i++){
		initialMonster(&monster[i]);
	}

	for (i = 0; i < monsterTotal; i++){
		printPlayerData(player);
		printf("�I��@���b�~�H�I(�b�~�H��O�� %d, �t�� %d, �����O %d)\n", monster[i].health, monster[i].spd, monster[i].atk);
		if (monster[i].spd > player.spd) atk_M2P(&player, &monster[i]);
		while (monster[i].health > 0 && player.health > 0){
			 atk_P2M(&player, &monster[i]);
			 if (monster[i].health > 0) atk_M2P(&player, &monster[i]);
		}
		if (player.health <= 0){
			printf("%s���F�C", player.name);
			break;
		}
		else {
			player.exp += 15;
			printf("%s��o�g��� %d�C\n\n", player.name, monster[i].exp);
		}
	}
	return 0;
}