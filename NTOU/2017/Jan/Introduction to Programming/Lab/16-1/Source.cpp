#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dateData {
	int year;
	int month;
	int day;
};
struct blogger {
	char ID[50];
	char nickame[30];
	int loginTimes = 1;
	int articles = 0;
	int money = 0;
	dateData lastLogin;
	char gender = 'U';
	bool verified = false;
	bool hidden = false;
	bool blacklisted = false;
};

void printfProfile(blogger user) {
	char tempchar[14];
	printf("[�b��] %-12s [�ʺ�] %-20s [�W��] %8d [�峹] %8d\n", user.ID, user.nickame, user.loginTimes, user.articles);
	strcpy(tempchar, "�|���q�L�{��");
	if (user.verified) strcpy(tempchar, "�w�g�q�L�{��");
	printf("[�{��] %-12s [�W��] %4d �~ %2d  �� %2d �� ", tempchar, user.lastLogin.year, user.lastLogin.month, user.lastLogin.day);
	strcpy(tempchar, "�ӭ�");
	if (user.gender == 'G') strcpy(tempchar, "���k");
	else if (user.gender == 'A') strcpy(tempchar, "�ʪ�");
	else if (user.gender == 'P') strcpy(tempchar, "�Ӫ�");
	else if (user.gender == 'R') strcpy(tempchar, "�q��");
	else if (user.gender == 'U') strcpy(tempchar, "����");
	printf("[�ʧO] �ڬO%s ", tempchar);
	if (user.money < 0) strcpy(tempchar, "�t�Ųֲ�");
	else if (user.money >= 0 && user.money <= 999) strcpy(tempchar, "�a�ҲM�H");
	else if (user.money > 999 && user.money <= 9999) strcpy(tempchar, "�a�Ҵ��q");
	else if (user.money > 9999 && user.money <= 19999) strcpy(tempchar, "�a�Ҥp�d");
	else if (user.money > 19999 && user.money < 29999) strcpy(tempchar, "�a�ҴI��");
	else if (user.money > 29999) strcpy(tempchar, "�a�ҴI��");
	printf("[�]��] %s\n", tempchar);
}

int main() {
	int i = 0;
	FILE *fpt;
	char line[20];
	char temp[5];
	blogger user[500];
	int count = -1;
	fpt = fopen("bloggerData.txt", "r");
	while (fgets(line, sizeof(line), fpt) != NULL) {
		*(line + strlen(line) - 1) = '\0';
		if (!strcmp(line, "[user]")) {
			count++;
		}
		if (!strncmp(line, "ID=", strlen("ID="))) {
			strcpy(user[count].ID, line + strlen("ID="));
		}
		if (!strncmp(line, "nickname=", strlen("nickname="))) {
			strcpy(user[count].nickame, line + strlen("nickname="));
		}
		if (!strncmp(line, "loginTimes=", strlen("loginTimes="))) {
			user[count].loginTimes = atoi(line + strlen("loginTimes="));
		}
		if (!strncmp(line, "articles=", strlen("articles="))) {
			user[count].articles = atoi(line + strlen("articles="));
		}
		if (!strncmp(line, "money=", strlen("money="))) {
			user[count].money = atoi(line + strlen("money="));
		}
		if (!strncmp(line, "lastLogin=", strlen("lastLogin="))) {
			strncpy(temp, line + strlen("lastLogin="), 4);
			temp[4] = '\0';
			user[count].lastLogin.year = atoi(temp);
			strncpy(temp, line + 4 + strlen("lastLogin="), 2);
			temp[2] = '\0';
			user[count].lastLogin.month = atoi(temp);
			strncpy(temp, line + 6 + strlen("lastLogin="), 2);
			temp[2] = '\0';
			user[count].lastLogin.day = atoi(temp);
		}
		if (!strncmp(line, "gender=", strlen("gender="))) {
			user[count].gender = line[strlen(line) - 1];
		}
		if (!strncmp(line, "verified=", strlen("verified="))) {
			user[count].verified = line[strlen(line) - 1] ? 'Y' : 'N';
		}
		if (!strncmp(line, "hidden=", strlen("hidden="))) {
			user[count].hidden = line[strlen(line) - 1] ? 'Y' : 'N';
		}
		if (!strncmp(line, "blacklisted=", strlen("blacklisted="))) {
			user[count].blacklisted = line[strlen(line) - 1] ? 'Y' : 'N';
		}
	}
	fclose(fpt);
	while (i <= count) {
		printfProfile(user[i]);
		i++;
		printf("\n");
	}
	return 0;
}