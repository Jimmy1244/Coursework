#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include"teacher.h"
#include"course.h"

using namespace std;

class department
{
public:
	department(ifstream &infile);
	~department(void);
private:
	string m_name;
	int teacherNum;
	int courseNum;
	vector<teacher*> m_teachers;
	vector<course*> m_courses;
public:
	void printName(ostream &os);
	void printDepartment(ostream &os);
	void printCourses(ostream &os);
	void printTeachersName(ostream &os);
	teacher* queryTeacherBasicsByName(string name);
	bool queryCourseBasicsByName(string name, ostream &os);
	department* queryDepartmentBasicsByName(string name);
	bool queryCourseBasicsById(string ID, ostream &os);
	void deleteAllteacherAndCourse(void);
};