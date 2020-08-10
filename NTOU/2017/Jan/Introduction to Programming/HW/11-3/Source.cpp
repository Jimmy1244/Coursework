#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	struct fishData {
		char chinese[50];
		char english[20];
		char sci[30];
		int len;
		int weight;
		char enviroment;
	};
	struct fishData fish[5] = { {"虱目魚", "Milk Fish", "Chanos chanos", 40 , 300, 's' }, {"海鱺", "Black King Fish", "Rachycentron canadum", 150, 40000, 's'}, {"草魚", "Grass carp", "Ctenopharyngodon idella", 150, 35000, 'f'}, {"金頭孔雀", "Gold Head Cichlid", "Aulonocara baenschi", 15, -1, 'f'}, {"眼斑海葵魚", "Ocellaris clownfish", "Amphiprion ocellaris", 4, -1, 's'} };
	char check[50];
	int i;
	printf("歡迎查詢海大數位典藏養殖生物資料庫！\n\n");
	printf("要找尋哪種魚的資料？(輸入 \"\quit\"\ 離開資料庫) ");
	fgets(check, 50, stdin);
	check[strlen(check) - 1] = '\0';
	while (strcmp(check, "quit")) {
		for (i = 0; i < 5; i++) {
			if (!strcmp(fish[i].chinese, check)) break;
		}
		if (i == 5) printf("您要找的 [%s] 並不在資料庫中。\n\n", check);
		else {
			if (fish[i].enviroment == 's') printf("[海水魚] ");
			else if (fish[i].enviroment == 'f')printf("[淡水魚] ");	
			if (fish[i].weight == -1 ) 
				printf("%s，英文叫 %s，學名是 %s，平均可長到 %d 公分長。\n\n", fish[i].chinese, fish[i].english, fish[i].sci, fish[i].len);
			else 
				printf("%s，英文叫 %s，學名是 %s，平均可長到 %d 公分長，%d 公克重。\n\n", fish[i].chinese, fish[i].english, fish[i].sci, fish[i].len, fish[i].weight);
		}
		printf("要找尋哪種魚的資料？(輸入 \"\quit\"\ 離開資料庫) ");
		fgets(check, 50, stdin);
		check[strlen(check) - 1] = '\0';
	}
	printf("\n");
	printf("感謝您的使用！");
	return 0;
}