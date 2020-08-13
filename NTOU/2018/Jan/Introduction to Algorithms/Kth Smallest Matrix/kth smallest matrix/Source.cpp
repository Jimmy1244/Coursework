#include<iostream>
#include<vector>

using namespace std;

void swap(int * a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int findAndSort(vector<int> &matrix, int s, int e) {
	int i;
	int pivot = matrix[e], largeIndex = e - 1;
	for (i = s; i < largeIndex; i++) {
		if (matrix[i] > pivot) {
			swap(&matrix[i], &matrix[largeIndex]);
			i--;
			largeIndex--;
		}
	}
	if (matrix[i] < matrix[e])
		i++;
	swap(&matrix[i], &matrix[e]);
	return i;//回傳pivot在哪個位置
}

void BST(vector<int> &matrix, int size, int index) {//自動會把index值改成第k小
	int s = 0, e = size * size - 1, mid;
	while (s < e) {
		mid = (s + e) / 2;
		swap(&matrix[mid], &matrix[e]);
		int binIndex = findAndSort(matrix, s, e);//回傳mid是第幾小(最小是第0小)
		if (binIndex == index) 
			return;
		if (binIndex > index) e = binIndex - 1;
		else
			s = binIndex + 1;
	}
}

int main() {
	int i, size, index;
	cin >> size >> index;
	vector<int> matrix(size * size, 0);
	for (i = 0; i < size * size; i++) {
			cin >> matrix[i];
	}
	BST(matrix, size, index - 1);
	cout << matrix[index - 1] << endl;
}