#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct Lpoly* pLp;

typedef struct Lpoly{
	float coef;
	int exp;
	pLp next;
}Lp;

pLp first1, first2, first3, temp;

void addpoly() {
	temp = first3 = (pLp)malloc(sizeof(Lp));
	pLp temp1 = first1, temp2 = first2;
	while (temp1 && temp2) {
		temp = temp->next = (pLp)malloc(sizeof(Lp));
		if (temp1->exp == temp2->exp) {
			temp->coef = temp1->coef + temp2->coef;
			temp->exp = temp2->exp;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1->exp > temp2->exp) {
			*temp = *temp1;
			temp1 = temp1->next;
		}
		else {
			*temp = *temp2;
			temp2 = temp2->next;
		}
	}
	while (temp1) {
		temp = temp->next = (pLp)malloc(sizeof(Lp));
		*temp = *temp1;
		temp1 = temp1->next;
	}
	while (temp2) {
		temp = temp->next = (pLp)malloc(sizeof(Lp));
		*temp = *temp2;
		temp2 = temp2->next;
	}
	temp->next = NULL;
	first3 = first3->next->next;
}

pLp newNode() {
	pLp node = (pLp)malloc(sizeof(Lp));
	scanf("%f%d", &node->coef, &node->exp);
	node->next = NULL;
	return node;
}

int AllZero(pLp a) {
	while (a && !a->coef) {
		a = a->next;
	}
	if (a) return 0;
	return 1;//¥þ¬°zero
}

void printPoly(pLp p) {
	if (AllZero(p)) printf("0.00\n");
	else {
		while (p->next) {
			if (p->coef != 0) {
				if (p->exp != 1) {
					if (p->next->coef >= 0) printf("%.2fx^%d +", p->coef, p->exp);
					else if (p->next->coef < 0) printf("%.2fx^%d ", p->coef, p->exp);
				}
				else {
					if (p->next->coef >= 0) printf("%.2fx +", p->coef);
					else if (p->next->coef < 0) printf("%.2fx ", p->coef);
				}
			}
			p = p->next;
		}
		if (p->coef != 0) {
			if (p->exp == 1) {
				printf("%.2fx\n", p->coef);
			}
			else if (p->exp == 0) {
				printf("%.2f\n", p->coef);
			}
			else {
				printf("%.2fx^%d\n", p->coef, p->exp);
			}
		}
	}
}

int main() {
	int quan[2], i = 0;
	scanf("%d", &quan[0]);
	first1 = (pLp)malloc(sizeof(Lp));
	first1->coef = 0;
	first1->exp = 0;
	first1->next = NULL;
	temp = first1;
	while (i < quan[0]) {
		temp->next = newNode();
		temp = temp->next;
		i++;
	}
	scanf("%d", &quan[1]);
	first2 = (pLp)malloc(sizeof(Lp));
	first2->coef = 0;
	first2->exp = 0;
	first2->next = NULL;
	temp = first2;
	i = 0;
	while (i < quan[1]) {
		temp->next = newNode();
		temp = temp->next;
		i++;
	}
	addpoly();
	printPoly(first1);
	printPoly(first2);
	printPoly(first3);
	return 0;
}