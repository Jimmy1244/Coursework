#include<fstream>
#include "university.h"

using namespace std;

void main(){
	ifstream infile("ntou1.txt");
	university myUniversity(infile);
	myUniversity.setCollegeNum(infile);
	myUniversity.setCollege(infile);
	myUniversity.printUniversity();
	infile.close();
	cout << "\npress <enter> to continue:";
	getchar();
	myUniversity.deleteDepartmentOfAllCollege();
}