#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int nums[50000];

void Maxmum_Subarray_cross(int mid, int left, int right) {

}

void Maxmum_Subarray(int s, int e) {//�Ѽ�:�}�Y�B����
	int mid = (s + e) / 2;
	Maxmum_Subarray(s, mid);//�V��
	Maxmum_Subarray(mid + 1, e);//�V�k
	Maxmum_Subarray_cross(mid, s, e);//�q����������
}

int main() {
	int count = 0;
	while (scanf("%d", &nums[count])) {//e-tutor �ݭn�[�W!=EOF
		count++;
	}
	Maxmum_Subarray(0, count - 1);//count�O�`�ӼơA���O����
	return 0;
}