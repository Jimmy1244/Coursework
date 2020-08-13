#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class fx
{
public:
	fx() {}
	~fx() {}
	int pos;
	int weight;
};

bool fxCmp(fx a, fx b) {
	return a.pos < b.pos;
}

bool xCmp(fx a, fx b) {
	return a.weight < b.weight;
}

int main() {
	int n, m, i, area = 0;
	ios::sync_with_stdio(false);//���P�Bcin�Pstdio�A�W�[�Ĳv
	cin >> n >> m;
	vector<fx> fxs(2 * n);
	vector<fx>xs(m);
	for (i = 0; i < n; i++) {
		cin >> fxs[i].pos;
		fxs[i].weight = 1;
	}
	for (; i < 2 * n; i++) {
		cin >> fxs[i].pos;
		fxs[i].weight = -1;
	}
	sort(fxs.begin(), fxs.end(), fxCmp);
	for (i = 0; i < m; i++) {
		cin >> xs[i].weight;
		xs[i].pos = i;
	}
	sort(xs.begin(), xs.end(), xCmp);
	vector<fx>::iterator iter = fxs.begin();
	int lastIndex = 0, endIndex = 0;//�W�@��index
	long long int *ansTable = new long long int[m];
	long long int ans = 0;
	for (i = 0; i < m; i++) {
		while (endIndex < xs[i].weight) {
			int plusFlag = 0;
			if (iter != fxs.end() && (*iter).pos <= xs[i].weight) {
				endIndex = (*iter).pos;//�C�����p���I������
				plusFlag = (*iter).weight;//�ݥ��t
				iter++;
			}
			else {
				endIndex = xs[i].weight;
			}
			ans += area * (endIndex - lastIndex);//���tendIndex
			area += plusFlag;
			lastIndex = endIndex;
		}
		ansTable[xs[i].pos] = ans;
	}
	cout << ansTable[0];
	for (i = 1; i < m; i++) {
		cout << ' ' << ansTable[i];
	}
	cout << endl;
	delete[] ansTable;
}