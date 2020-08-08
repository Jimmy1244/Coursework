#include "teacher.h"
#include "Institute.h"
#include "department.h"

teacher::teacher(ifstream &infile, department* rhs)
	:m_department(rhs), m_institute(0)
{
	infile >> m_name;
}

teacher::teacher(ifstream &infile, institute* rhs)
	:m_department(0), m_institute(rhs)
{
	infile >> m_name;
}


teacher::~teacher(void)
{
}

void teacher::printName(ostream &os) const{
	cout << m_name << '\n';
}

void teacher::printTeacher(ostream &os)const{
	os << "      ±Ð®v©m¦W: ";
	printName(os);
	if(m_department){
		m_department->printName(os);
	}
	else{
		m_institute->printName(os);
	}
}

void teacher::printCourse(ostream &os){
	vector<course*>::iterator iter;
	for(iter = m_courses.begin(); iter < m_courses.end(); iter++){
		(*iter)->printCourse(os);
		os << '\n';
	}
}

teacher* teacher::queryTeacherBasicsByName(string name){
	if(name == m_name)
		return this;
	return NULL;
}

void teacher::linkCourse(course* rhs){
	m_courses.push_back(rhs);
}