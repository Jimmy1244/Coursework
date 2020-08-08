#pragma once
#include "college.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class teacher;
class department;
class institute;

class university
{
public:
	university(ifstream &infile);
	~university(void);
private:
	vector<college *> m_colleges;
	int collegeNum;
	string m_name;
public:
	void setCollege(ifstream & infile);
	void printUniversity(ostream &os);
	void deleteDepartmentOfAllCollege(void);
	teacher* queryTeacherBasicsByName(string name);
	bool queryCourseBasicsByName(string name, ostream &os);
	department* queryDepartmentBasicsByName(string name);
	institute* queryInstituteBasicsByName(string name);
	bool queryCourseBasicsById(string ID, ostream &os);
	static void unitTest();
	bool query(ostream &os);
};

