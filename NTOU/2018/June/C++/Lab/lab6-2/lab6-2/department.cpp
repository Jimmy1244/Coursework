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
	cout <<"\n    ¾Ç¨t¦WºÙ:" << m_name;
}
