#include<iostream>

using namespace std;

class node {
public:
	node(int cakeNums) 
	:pancakeNums(cakeNums)
	{
		int i;
		for (i = 0; i < pancakeNums; i++) {
			cin >> state[i];
		}
	}
	~node() {}
	bool isGoal() {
		int i;
		for (i = 0; i < pancakeNums; i++) {
			if (state[i] != i)
				return false;
		}
		return true;
	}
	int gapNumber() {
		int count = 0, i;
		for (i = 0; i < pancakeNums - 1; i++) {
			if (state[i + 1] != state[i] + 1 && state[i + 1] != state[i] - 1) //總是會越做越少gap=>我猜這樣會快點；而且如果continue寫在if底下，可能不會被預處理
				count++;
		}
		return count;
	}
private:
	int pancakeNums;
	int state[1000];
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int cakeNums;
		cin >> cakeNums;
		node nodeT(cakeNums);
		cout << nodeT.gapNumber() << '\n';
	}
	double h = 0;
	while (h < 2000000000) {//2000000000
		h++;
	}
	return 0;
}