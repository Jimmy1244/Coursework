#include<vector>
#include<cassert>
#include<algorithm>

#include "Complex.h"

using namespace std;

void vectorAdd(vector<Complex> &com){
	vector<Complex>::iterator iter;
	for(iter = com.begin(); iter < com.end() - 1; iter++){
		com[0].multiply(*(iter+1));
	}
	Complex cmpTmp;
	cmpTmp.setValue( -8.96419, -3.24387);
	assert(com[0].equal(cmpTmp, 1e-4));//»~®t­È¤Ó¤j¤F
}

bool cmp(Complex a, Complex b){
	return a.magnitude() > b.magnitude();
}

void sortVector(vector<Complex> &com){
	sort(com.begin(), com.end(), cmp);
	int i;
	for(i = 0; i < com.size(); i++){
		com[i].print();
	}
}