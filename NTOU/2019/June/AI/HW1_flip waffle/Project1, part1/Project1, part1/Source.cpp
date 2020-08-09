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
		if (nodeT.isGoal())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	double h = 0;
	while (h < 2000000000) {
		h++;
	}
	return 0;
}