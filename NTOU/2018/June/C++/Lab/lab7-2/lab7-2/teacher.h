#pragma once

#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include "course.h"

class institute;
class department;

using namespace std;

class teacher
{
public:
	teacher();
	teacher(ifstream &infile, department* rhs);
	teacher(ifstream &infilem, institute* rhs);
	~teacher(void);
	void printName(ostream &os)const;
	void printTeacher(ostream &os)const;
	void printCourse(ostream &os);
	teacher* queryTeacherBasicsByName(string name);
	void linkCourse(course *rhs);
private:
	string m_name;
	institute* m_institute;
	department* m_department;
	vector<course*> m_courses;
};

