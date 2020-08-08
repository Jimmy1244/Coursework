#include<fstream>
#include<iostream>
#include "university.h"

using namespace std;

void main(){
	ifstream infile("ntou2.txt");
	if(!infile){
		cerr << "打開文件失敗\n";
		return;
	}
	university myUniversity(infile);
	infile.close();
	myUniversity.unitTest();
	while(myUniversity.query(cout));
	cout << "Press <enter> to continue:\n";
	getchar();
	myUniversity.deleteDepartmentOfAllCollege();
}