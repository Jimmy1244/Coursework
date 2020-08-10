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
	printf("請輸入玩家的名子: ");
	scanf("%s", player->name);
	player->health = rand() % 251 + 1000;
	player->exp = 0;
	player->mana = rand() % 21 + 100;
	player->spd = rand() % 16 + 35;
	player->atk = rand() % 21 + 40;
}

void initialMonster(struct monsterData * monster){
	strcpy(monster->name, "半獸人"); //不能直接assign
	monster->health = rand() % 21 + 150;
	monster->spd = rand() % 16 + 35;
	monster->atk = rand() % 11 + 20;
	monster->exp = 15;
}

void  printPlayerData(struct playerData player){
	printf("%s\n體力%d, 速度%d, 攻擊力%d, 經驗值%d\n\n", player.name, player.health, player.spd, player.atk, player.exp);
}

void atk_M2P(struct playerData *player, struct monsterData *monster){
	player->health -= monster->atk;
	printf("%s攻擊，造成%s失血 %d 點。\n", monster->name, player->name, monster->atk);
}

void atk_P2M(struct playerData *player, struct monsterData *monster){
	monster->health -= player->atk;
	printf("%s攻擊，造成%s失血 %d 點。\n", player->name, monster->name, player->atk);
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
		printf("碰到一隻半獸人！(半獸人體力為 %d, 速度 %d, 攻擊力 %d)\n", monster[i].health, monster[i].spd, monster[i].atk);
		if (monster[i].spd > player.spd) atk_M2P(&player, &monster[i]);
		while (monster[i].health > 0 && player.health > 0){
			 atk_P2M(&player, &monster[i]);
			 if (monster[i].health > 0) atk_M2P(&player, &monster[i]);
		}
		if (player.health <= 0){
			printf("%s死了。", player.name);
			break;
		}
		else {
			player.exp += 15;
			printf("%s獲得經驗值 %d。\n\n", player.name, monster[i].exp);
		}
	}
	return 0;
}