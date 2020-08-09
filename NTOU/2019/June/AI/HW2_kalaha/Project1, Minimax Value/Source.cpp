#include<iostream>

using namespace std;

int maxvalue(int house[], int depthMax, int depth, int *alpha, int *beta);

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
	while (beans > 0) {
		pickedhouse++;
		if (pickedhouse > 13)
			pickedhouse = pickedhouse % 14;
		if (pickedhouse == opponentStore)
			continue;
		house[pickedhouse]++;
		beans--;
	}
	if (house[pickedhouse] == 1 && house[12 - pickedhouse] > 0 && pickedhouse < playerStore && pickedhouse > playerStore - 7) {
		house[playerStore] += house[12 - pickedhouse] + house[pickedhouse];
		house[12 - pickedhouse] = 0;
		house[pickedhouse] = 0;
	}
	return nextMove;
}

void backupArray(int house[], int temp[]) {
	int i;
	for (i = 0; i < 14; i++) {
		temp[i] = house[i];
	}
}

void minvalue(int house[], int depthMax, int depth, int *alpha, int *beta) {
	if (depth >= depthMax) {
		int t;
		t = house[13] - house[6];
		*beta = t < *beta ? t : *beta ;
		return;
	}
	int i;
	bool endFlag = true;
	int temp[14], tmpMin = 100;
	for (i = 0; i < 6; i++) {
		if (*alpha >= *beta)
			return;
		if (house[i] != 0) {
			backupArray(house, temp);
			int nextAlpha;
			endFlag = false;
			if (relocation(house, i)) {
				nextAlpha = *beta;
				minvalue(house, depthMax, depth + 2, alpha, &nextAlpha);
			}
			else {
				nextAlpha = *alpha;
				maxvalue(house, depthMax, depth + 1, &nextAlpha, beta);
			}
			if (nextAlpha < tmpMin) {
				tmpMin = nextAlpha;
				if(nextAlpha < *beta) //prevent beta from getting larger when being in loop
					*beta = nextAlpha;
			}
			backupArray(temp, house);
		}
	}
	*beta = tmpMin; //beta should be minimum in this node not origin beta which could be smaller
	if (endFlag) {
		*beta = house[13] - house[6];
		return;
	}
	return;
}


int maxvalue(int house[], int depthMax, int depth, int *alpha, int *beta) {
	if (depth >= depthMax) {
		int t;
		t = house[13] - house[6];
		*alpha = t > *alpha ? t : *alpha;
		return 0;
	}
	int i, action;
	bool endFlag = true;
	int tempArray[14], tmpMax = -100;
	for (i = 7; i < 13; i++) {
		if (*alpha >= *beta)
			return 0;
		if (house[i] != 0) {
			backupArray(house, tempArray);
			int nextBeta;
			endFlag = false;
			if (relocation(house, i)) {
				nextBeta = *alpha;
				maxvalue(house, depthMax, depth + 2, &nextBeta, beta);
			}
			else {
				nextBeta = *beta;
				minvalue(house, depthMax, depth + 1, alpha, &nextBeta);
			}
			backupArray(tempArray, house);
			if (nextBeta > tmpMax) {
				tmpMax = nextBeta;
				if(nextBeta > *alpha)
					*alpha = nextBeta;
				action = i;
			}
		}
	}
	*alpha = tmpMax;
	if (endFlag) {
		*alpha = house[13] - house[6];
		return 0;
	}
	return action;
}

int minimaxDecision(int house[], int depthMax) {
	int max = -100, min = 100;
	return maxvalue(house, depthMax, 0, &max, &min);
}

int main() {
	int t, house[14], depth;
	cin >> t;
	while (t--) {
		int i;
		for (i = 0; i < 14; i++) {
			cin >> house[i];
		}
		cin >> depth;
		cout << minimaxDecision(house, depth) << endl;
	}
	return 0;
}