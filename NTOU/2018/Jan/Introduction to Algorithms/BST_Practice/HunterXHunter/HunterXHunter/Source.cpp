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

int fixMatch() {//往左的底限(0, 奇犽不夠, 移動後的差不要大於max.pos)
	
}

//由左往右找到最適合的(奇犽不重複)，移動最左邊的小傑，一定要移動到差最多的奇犽小傑

int main() {
	int j, k;//小j, ki牙
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
		while (k_shades[matchP].used && matchP < k)//找到一個未被佔的奇犽
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