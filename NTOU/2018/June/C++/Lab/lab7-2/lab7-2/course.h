#pragma once

#include<fstream>
#include<iostream>
#include<string>

class department;
class institute;
class teacher;

class course
{
public:
	course(std::ifstream &infile, department* department);
	course(std::ifstream &infile, institute* rhs);
	~course(void);
	void printCourse(std::ostream &os)const;
	bool queryCourseBasicsByName(std::string name, std::ostream &os);
	bool queryCourseBasicsById(std::string ID, std::ostream &os);
private:
	std::string m_name;
	std::string m_ID;
	teacher *m_teacher;
	int m_year, m_semester;
	department* m_department;
	institute* m_institute;
};

