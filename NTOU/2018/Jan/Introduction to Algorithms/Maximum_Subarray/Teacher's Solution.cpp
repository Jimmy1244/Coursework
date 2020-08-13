#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int nums[50000];

void Maxmum_Subarray_cross(int mid, int left, int right) {

}

void Maxmum_Subarray(int s, int e) {//參數:開頭、結尾
	int mid = (s + e) / 2;
	Maxmum_Subarray(s, mid);//向左
	Maxmum_Subarray(mid + 1, e);//向右
	Maxmum_Subarray_cross(mid, s, e);//從中間往兩邊
}

int main() {
	int count = 0;
	while (scanf("%d", &nums[count])) {//e-tutor 需要加上!=EOF
		count++;
	}
	Maxmum_Subarray(0, count - 1);//count是總個數，不是結尾
	return 0;
}