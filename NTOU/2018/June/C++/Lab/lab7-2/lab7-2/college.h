#pragma once
#include "department.h"
#include "Institute.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class teacher;

class college
{
public:
	college(ifstream &infile);
	~college(void);
private:
	vector<department *> m_departments;
	vector<institute *> m_institutes;
	int instituteNum;
	int departmentNum;
	string m_name;
public:
	void setDepartmentNumAndDepartment(ifstream &infile);
	void deleteDepartment(const int & index);
	void setCollegeName(ifstream & infile);
	void printCollege(ostream &os);
	void deleteAllDepartment(void);
	teacher* queryTeacherBasicsByName(string name);
	bool queryCourseBasicsByName(string name, ostream &os);
	department* queryDepartmentBasicsByName(string name);
	institute* queryInstituteBasicsByName(string name);
	bool queryCourseBasicsById(string ID, ostream &os);
};

