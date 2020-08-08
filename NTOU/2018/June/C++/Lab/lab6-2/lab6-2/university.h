#pragma once
#include "college.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class university
{
public:
	university(ifstream &infile);
	~university(void);
private:
	college *colleges;
	int collegeNum;
	string m_name;
public:
	void setCollegeNum(ifstream & infile);
	void setCollege(ifstream & infile);
	void printUniversity(void);
	void deleteDepartmentOfAllCollege(void);
};

