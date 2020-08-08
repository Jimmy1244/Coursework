#include "university.h"


university::university(ifstream &infile)
	: colleges(new college[10])
{
	infile >> m_name;
}


university::~university(void)
{
	delete[] colleges;
}

void university::setCollegeNum(ifstream &infile)
{
	infile >> collegeNum;
}

void university::setCollege(ifstream & infile)
{
	int i;
	for(i = 0; i < collegeNum; i++){
		colleges[i].setCollegeName(infile);
		colleges[i].setDepartmentNumAndDepartment(infile);
	}
}

void university::printUniversity(void)
{
	cout << "¾Ç®Õ¦WºÙ:" << m_name;
	int i;
	for(i = 0;i < collegeNum; i++){
		colleges[i].printCollege();
	}
}

void university::deleteDepartmentOfAllCollege(void)
{
	int i;
	for(i = 0; i <collegeNum; i++){
		colleges[i].deleteAllDepartment();
	}
}
