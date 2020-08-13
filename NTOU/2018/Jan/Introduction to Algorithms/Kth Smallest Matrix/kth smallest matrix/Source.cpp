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
	return i;//�^��pivot�b���Ӧ�m
}

void BST(vector<int> &matrix, int size, int index) {//�۰ʷ|��index�ȧ令��k�p
	int s = 0, e = size * size - 1, mid;
	while (s < e) {
		mid = (s + e) / 2;
		swap(&matrix[mid], &matrix[e]);
		int binIndex = findAndSort(matrix, s, e);//�^��mid�O�ĴX�p(�̤p�O��0�p)
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