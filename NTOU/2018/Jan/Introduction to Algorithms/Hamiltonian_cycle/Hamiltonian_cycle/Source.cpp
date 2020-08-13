#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int num;
	struct Node * next;
	char passed;
}node;

int queue[1000000] = { 0 }, front, bottom, max, find;

void backtracking(node * nodes, int num, int count) {
	queue[++bottom] = num;
	nodes[num].passed = 1;
	node * thread = nodes[num].next;
	if (count == max) {
		while (thread) {
			if (thread->num == 1) {
				while (front < bottom) {
					printf("%d ", queue[++front]);
				}
				find = 1;
				return;
			}
			thread = thread->next;
		}
		return;
	}
	while (thread) {
		if (!nodes[thread->num].passed && thread->num) {
			backtracking(nodes, thread->num, count + 1);
			if (find)
				return;
			bottom--;
			nodes[thread->num].passed = 0;
		}
		thread = thread->next;
	}
}

void buildNode(node * nodes, int s, int e) {
	nodes[s].num = s;
	nodes[s].passed = 0;
	node * thread = &nodes[s];//thread 要到最後
	while (thread->next)
		thread = thread->next;
	thread->next = (node *)malloc(sizeof(node));
	thread->next->num = e;
	thread->next->next = NULL;
	nodes[e].num = e;
	nodes[e].passed = 0;
	thread = &nodes[e];//thread 要到最後
	while (thread->next)
		thread = thread->next;
	thread->next = (node *)malloc(sizeof(node));
	thread->next->num = s;
	thread->next->next = NULL;
}

int main() {
	int lastS = 0, lastE = 0;
	while (scanf("%d", &max) != EOF) {
		node *nodes = (node *)malloc(sizeof(node) * (257));
		char ch[10000];
		for (int j = 0; j < 257; j++) {
			nodes[j].next = NULL;
		}
		front = -1; bottom = -1;
		find = 0;
		int s = 0, e = 0;
		buildNode(nodes, lastS, lastE);//讓上一筆測資的最後兩個加入，如果是第一筆測資或上一次沒輸入則加入0,0
		while (scanf("%s", ch)) {
			if (ch[0] == '%') {
				lastS = s;
				lastE = e;
				break;
			}
			s = atoi(ch);
			scanf("%d", &e);
			buildNode(nodes, s, e);
		}
		backtracking(nodes, 1, 1);
		if (find)
			printf("1\n");
		else
			printf("N\n");
	}
}