#pragma once
#include "department.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class college
{
public:
	college(void);
	~college(void);
private:
	vector<department *> departments;
	int departmentNum;
	string m_name;
public:
	void setDepartmentNumAndDepartment(ifstream &infile);
	void deleteDepartment(const int & index);
	void setCollegeName(ifstream & infile);
	void printCollege(void);
	void deleteAllDepartment(void);
};

