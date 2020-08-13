#include<iostream>
#include<vector>

using namespace std;

void binarySearch(vector<int> & snowan, vector<long long int> & sumC, int quan) {
	int i;
	for (i = 0; i < quan; i++) {
		int s = 1, e = quan;
		long long int key = snowan[i] + sumC[i];
		if (key > sumC[quan])
			cout << -1 << ' ';
		else {
			while (s <= e) {
				int mid = (s + e) / 2;
				if (key > sumC[mid]) s = mid + 1;
				else e = mid - 1;
			}
			cout << s << ' ';//程┪单常穦琌氮程˙sぃ穦笆
		}
	}
	cout << '\n';
}

int main() {
	int quan;
	cin >> quan;
	vector<int > snowan(quan, 0), days(quan, 0);
	vector<long long int> sumC(quan + 1, 0);
	int i;
	for (i = 0; i < quan; i++) {
		cin >> snowan[i];
	}
	for (i = 0; i < quan; i++) {
		cin >> days[i];
	}
	for (i = 1; i <= quan; i++) {
		sumC[i] = sumC[i - 1] + days[i - 1];
	}
	binarySearch(snowan, sumC, quan);
}