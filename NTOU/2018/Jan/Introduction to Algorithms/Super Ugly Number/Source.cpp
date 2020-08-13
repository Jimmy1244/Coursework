#include<iostream>
#include<vector>

using namespace std;

int main() {
	int index, size;
	cin >> index >> size;
	vector<int> initialArray(size, 0);
	vector<int> multiplyPos(size, 0);
	vector<int> ugly(1, 1);
	int i, max = 0;
	for (i = 0; i < size; i++) {
		cin >> initialArray[i];
		if (max < initialArray[i])
			max = initialArray[i];
	}
	for (i = 1; i < index;) {
		int j, min =INT_MAX, changeIndex;
		for (j = 0; j < size; j++) {
			if (min > initialArray[j] * ugly[multiplyPos[j]]) {
				min = initialArray[j] * ugly[multiplyPos[j]];
				changeIndex = j;
			}
		}
		for (j = changeIndex; j < size; j++) {//
			if(min == initialArray[j] * ugly[multiplyPos[j]])//自己也會++
				multiplyPos[j]++;
		}
		ugly.push_back(min);
		i++;
	}
	cout << ugly[index - 1] << '\n';
}