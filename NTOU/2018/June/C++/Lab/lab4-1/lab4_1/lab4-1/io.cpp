#include<fstream>
#include<vector>
#include<iostream>
#include "Complex.h"

using namespace std;

void readFile(vector<Complex> &com){
	fstream infile("complex.dat");
	double realTmp, imaginaryTmp;
	int countLine = 0;
	while(infile){
		infile >> realTmp >> imaginaryTmp;
		if(infile.good()){
			Complex tmp;
			tmp.setValue(realTmp, imaginaryTmp);
			com.push_back(tmp);
		}
	}
	infile.close();
}