#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Lstr* Lsp;

typedef struct Lstr{
	char word[20];
	Lsp next;
}Ls;

Lsp lead, middle, trail = NULL;
int i = -1;

Lsp newNode() {
	Lsp L = (Lsp)malloc(sizeof(Ls));
	return L;
}

void printStep(Lsp trail, Lsp middle, Lsp lead, int i) {
	if (i == 0) {
		printf("Initial step: \nlead = %s\nmiddle = NULL\n", lead->word);
	}
	else {
		printf("Step %d: \n", i);
		printf("trail = %s\nmiddle = %s\nlead = %s\n",trail? trail->word :"NULL", middle->word, lead?lead->word: "NULL");
	}
}

void invertAndprint() {
	while (lead) {
		if (i != -1) {
			printStep(trail, middle, lead, i);
			printf("\n");
		}
		trail = middle;
		middle = lead;
		lead = lead->next;
		middle->next = trail;
		if (i != -1) i++;
	}
	if (i != -1) {
			printStep(trail, middle, lead, i);
		}
}

int main() {
	lead = newNode();
	scanf("%s", lead->word);
	lead->next = NULL;
	middle = newNode();
	scanf("%s", middle->word);
	middle->next = NULL;
	lead->next = middle;
	char a[50];
	while (scanf("%s", a)!= EOF) {
		middle->next = newNode();
		middle = middle->next;
		strcpy(middle->word, a);
		middle->next = NULL;
	}
	middle = NULL;
	invertAndprint();
	printf("String invert:");
	Lsp temp;
	temp = middle;
	while (temp) {
		printf(" %s", temp->word);
		temp = temp->next;
	}
	printf("\n\n"); 
	lead = middle;
	middle = NULL;
	invertAndprint();
	lead = middle;
	middle = NULL;
	i = 0;
	invertAndprint();
	return 0;
}