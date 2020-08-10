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
	printf("[帳號] %-12s [暱稱] %-20s [上站] %8d [文章] %8d\n", user.ID, user.nickame, user.loginTimes, user.articles);
	strcpy(tempchar, "尚未通過認證");
	if (user.verified) strcpy(tempchar, "已經通過認證");
	printf("[認證] %-12s [上次] %4d 年 %2d  月 %2d 日 ", tempchar, user.lastLogin.year, user.lastLogin.month, user.lastLogin.day);
	strcpy(tempchar, "帥哥");
	if (user.gender == 'G') strcpy(tempchar, "美女");
	else if (user.gender == 'A') strcpy(tempchar, "動物");
	else if (user.gender == 'P') strcpy(tempchar, "植物");
	else if (user.gender == 'R') strcpy(tempchar, "礦物");
	else if (user.gender == 'U') strcpy(tempchar, "未知");
	printf("[性別] 我是%s ", tempchar);
	if (user.money < 0) strcpy(tempchar, "負債累累");
	else if (user.money >= 0 && user.money <= 999) strcpy(tempchar, "家境清寒");
	else if (user.money > 999 && user.money <= 9999) strcpy(tempchar, "家境普通");
	else if (user.money > 9999 && user.money <= 19999) strcpy(tempchar, "家境小康");
	else if (user.money > 19999 && user.money < 29999) strcpy(tempchar, "家境富有");
	else if (user.money > 29999) strcpy(tempchar, "家境富有");
	printf("[財產] %s\n", tempchar);
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