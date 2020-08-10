#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct playerData {
	char name[30]; // name of the player
	int level; // level of the player
	char skill; // kongfu records which the player has learned
};

int main(){
	int i;
	FILE *fpt;
	fpt = fopen("playerData.binary", "rb");
	if (fpt == NULL) {
		printf("∂}¿…•¢±—\n");
		exit(0);
	}
	fseek(fpt, 0, SEEK_END);
	int fsize = ftell(fpt);
	rewind(fpt);
	int playerTotal = fsize / sizeof(playerData);
	struct playerData *players = (playerData *)malloc(fsize + 1);
	fread(players, sizeof(playerData), playerTotal, fpt);
	for (i = 0; i < playerTotal; i++){
		players[i].level += 1;
	}
	fpt = fopen("playerData.binary", "wb");
	for (i = 0; i < playerTotal; i++){
		printf("Name: %s\n", players[i].name);
		printf("Level: %d\n\n", players[i].level);
	}
	fwrite(players, sizeof(playerData), playerTotal, fpt);
	fclose(fpt);
	return 0;
}