#include<iostream>
#include<vector>
#include<algorithm>
#include "shades.h"

using namespace std;

int cmp(shades a, shades b) {
	int aPos = a.pos, bPos = b.pos;
	return aPos < bPos;
}

int BS(shades *k_shades, int s, int e, int key) {
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (key > k_shades[mid].pos) 
			s = mid + 1;
		else 
			e = mid - 1;
	}
	return mid;
}

int fixMatch() {//����������(0, �_�b����, ���ʫ᪺�t���n�j��max.pos)
	
}

//�ѥ����k���̾A�X��(�_�b������)�A���ʳ̥��䪺�p�ǡA�@�w�n���ʨ�t�̦h���_�b�p��

int main() {
	int j, k;//�pj, ki��
	cin >> j >> k;
	shades *j_shades = new shades[j], *k_shades = new shades[k], *match_shades = new shades[j];
	int p;
	for (p = 0; p < j; p++) {
		cin >> j_shades[p].pos;
	}
	sort(j_shades, &j_shades[j], cmp);
	for (p = 0; p < k; p++) {
		cin >> k_shades[p].pos;
	}
	sort(k_shades, &k_shades[k], cmp);
	int p;
	shades max;
	int matchP = 0;
	for (p = 0; matchP < k; p++) {//j BS k
		matchP = BS(k_shades, 0, k, j_shades[p].pos);
		while (k_shades[matchP].used && matchP < k)//���@�ӥ��Q�����_�b
			matchP++;
		k_shades[matchP].used = 1;
		match_shades[p].pos = matchP;
		match_shades[p].used = p - matchP > 0 ? p - matchP : matchP - p;
		if (max.used < match_shades[p].used) {
			max.used = match_shades[p].used;
			max.pos = p;
		}
	}
	fixMatch();
}