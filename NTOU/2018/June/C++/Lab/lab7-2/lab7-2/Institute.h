#pragma once

#include <fstream>
#include "department.h"
#include "teacher.h"
#include "course.h"

using namespace std;

class institute
{
public:
	institute(ifstream &infile);
	~institute(void);
	void printName(ostream &os)const;
	void printInstitute(ostream &os)const;
	teacher* queryTeacherBasicsByName(string name);
	void printCourses(ostream &os);
	void printTeachersName(ostream &os);
	bool queryCourseBasicsByName(string name, ostream &os);
	institute* queryInstituteBasicsByName(string name);
	bool queryCourseBasicsById(string ID, ostream &os);
	void deleteAllteacherAndCourse(void);
private:
	string m_name;
	int teacherNum;
	int courseNum;
	vector<teacher*> m_teachers;
	vector<course*> m_courses;
};

