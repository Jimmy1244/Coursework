#include "department.h"

department::department(ifstream &infile)
{
	infile >> m_name;
}


department::~department(void)
{
}


void department::printDepartment(void)
{
	cout <<"\n    �Ǩt�W��:" << m_name;
}
