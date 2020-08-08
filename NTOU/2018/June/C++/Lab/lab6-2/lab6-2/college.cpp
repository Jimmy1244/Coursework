#include "college.h"


college::college(void)
	:departmentNum(0)
{
}


college::~college(void)
{
}


void college::setDepartmentNumAndDepartment(ifstream &infile)
{
	infile >> departmentNum;
	int i;
	for(i = 0; i < departmentNum; i++){
		department * depart = new department(infile);
		departments.push_back(depart);
	}
}


void college::deleteDepartment(const int & index)
{
	department * tmp = departments[index];
	departments[index] = departments.back();
	departments.back() = tmp;
	delete departments.back();
	departments.pop_back();
}


void college::setCollegeName(ifstream & infile)
{
	infile >> m_name;
}

void college::printCollege(void)
{
	cout << "\n  ¾Ç°|¦WºÙ:" << m_name;
	int i;
	for(i = 0; i < departmentNum; i++){
		departments[i]->printDepartment();
	}
}


void college::deleteAllDepartment(void)
{
	int i;
	for(i = 0; i < departmentNum; i++){
		delete departments.back();
		departments.pop_back();
	}
}
