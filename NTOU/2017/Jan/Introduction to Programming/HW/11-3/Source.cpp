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
	struct fishData fish[5] = { {"��س�", "Milk Fish", "Chanos chanos", 40 , 300, 's' }, {"����", "Black King Fish", "Rachycentron canadum", 150, 40000, 's'}, {"��", "Grass carp", "Ctenopharyngodon idella", 150, 35000, 'f'}, {"���Y�ճ�", "Gold Head Cichlid", "Aulonocara baenschi", 15, -1, 'f'}, {"����������", "Ocellaris clownfish", "Amphiprion ocellaris", 4, -1, 's'} };
	char check[50];
	int i;
	printf("�w��d�߮��j�Ʀ���þi�ޥͪ���Ʈw�I\n\n");
	printf("�n��M���س�����ơH(��J \"\quit\"\ ���}��Ʈw) ");
	fgets(check, 50, stdin);
	check[strlen(check) - 1] = '\0';
	while (strcmp(check, "quit")) {
		for (i = 0; i < 5; i++) {
			if (!strcmp(fish[i].chinese, check)) break;
		}
		if (i == 5) printf("�z�n�䪺 [%s] �ä��b��Ʈw���C\n\n", check);
		else {
			if (fish[i].enviroment == 's') printf("[������] ");
			else if (fish[i].enviroment == 'f')printf("[�H����] ");	
			if (fish[i].weight == -1 ) 
				printf("%s�A�^��s %s�A�ǦW�O %s�A�����i���� %d �������C\n\n", fish[i].chinese, fish[i].english, fish[i].sci, fish[i].len);
			else 
				printf("%s�A�^��s %s�A�ǦW�O %s�A�����i���� %d �������A%d ���J���C\n\n", fish[i].chinese, fish[i].english, fish[i].sci, fish[i].len, fish[i].weight);
		}
		printf("�n��M���س�����ơH(��J \"\quit\"\ ���}��Ʈw) ");
		fgets(check, 50, stdin);
		check[strlen(check) - 1] = '\0';
	}
	printf("\n");
	printf("�P�±z���ϥΡI");
	return 0;
}