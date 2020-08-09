#include<iostream>

using namespace std;

bool relocation(int *house, int pickedhouse) {
	bool nextMove = false;
	int  playerStore = 6, opponentStore = 13;
	if (pickedhouse > 6) {
		playerStore = 13;
		opponentStore = 6;
	}
	if ((pickedhouse + house[pickedhouse]) % 13 == playerStore % 13)
		nextMove = true;
	int beans = house[pickedhouse];
	house[pickedhouse] = 0;
	while (beans > 1) {
		pickedhouse++;
		if (pickedhouse > 13)
			pickedhouse = pickedhouse % 14;
		if (pickedhouse == opponentStore)
			continue;
		house[pickedhouse]++;
		beans--;
	}
	pickedhouse++;
	pickedhouse = pickedhouse % 14;
	house[pickedhouse]++;
	if (house[pickedhouse] == 1 && house[12 - pickedhouse] > 0  && pickedhouse < playerStore && pickedhouse > playerStore - 7) {
		house[playerStore] += house[12 - pickedhouse] + house[pickedhouse];
		house[12 - pickedhouse] = 0;
		house[pickedhouse] = 0;
	}
	cout << '['  << house[0];
	for (pickedhouse = 1; pickedhouse < 14; pickedhouse++) {
		cout << ' ' << house[pickedhouse];
	}
	cout << "]\n";
	return nextMove;
}

int main() {
	int t, house[14], pickedHouse;
	cin >> t;
	while (t--) {
		int i;
		for (i = 0; i < 14; i++) {
			cin >> house[i];
		}
		cin >> pickedHouse;
		cout << (relocation(house, pickedHouse) ? "YES" : "NO") << endl;
	}
	return 0;
}