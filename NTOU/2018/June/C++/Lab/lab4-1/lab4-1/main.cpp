#define _CRT_SECURE_NO_WARNINGS

#include<vector>

#include "Complex.h"
#include "io.h"
#include "statistic.h"

using namespace std;

int main(){
	vector <Complex> complexArray;
	readFile(complexArray);
	vectorAdd(complexArray);
	sortVector(complexArray);
}