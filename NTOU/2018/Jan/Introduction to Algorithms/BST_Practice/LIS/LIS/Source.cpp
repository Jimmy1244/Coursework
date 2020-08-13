#define _CRT_SEUCRE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int quan, lenth = 1, num;
	cin >> quan;
	vector < int > nums(quan);
	int i;
	cin >> num;
	nums[0] = num;
	for (i = 1; i < quan; i++) {
		cin >> num;
		if (num < nums[0]) {
			nums[0] = num;
		}
		else if (num > nums[lenth - 1]) {
			nums[lenth] = num;
			lenth++;
		}
		else {
			int start, end;
			for (start = 0, end = lenth; start <= end;) {
				int mid = (start + end) / 2;
				if (mid < lenth - 1 && num <= nums[mid + 1] && num > nums[mid]) {//如果num < nums[第0個]判斷不到
					nums[mid + 1] = num;
					break;
				}
				else if (nums[mid] > num) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
		}
		/*for (int j = 0; j < lenth; j++) {
			cout << nums[j] << ' ';
		}
		cout << '\n';*/
	}
	cout << lenth << endl;
}