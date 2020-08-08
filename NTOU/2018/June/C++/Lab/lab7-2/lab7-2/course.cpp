#include "course.h"
#include "teacher.h"
#include "department.h"
#include "Institute.h"

using namespace std;

course::course(std::ifstream &infile, department* rhs)
{
	infile >> m_name >> m_ID >> m_year >> m_semester;
	m_department = rhs;
	m_institute = NULL;
	std::string buf;
	infile >> buf;//��X�Ѯv���Ы��L�h
	m_teacher = m_department->queryTeacherBasicsByName(buf);
	m_teacher->linkCourse(this);
}

course::course(std::ifstream &infile, institute* rhs)
{
	infile >> m_name >> m_ID >> m_year >> m_semester;
	m_institute = rhs;
	m_department = NULL;
	std::string buf;
	infile >> buf;//��X�Ѯv���Ы��L�h
	m_teacher = m_institute->queryTeacherBasicsByName(buf);
	m_teacher->linkCourse(this);
}

course::~course(void)
{
}

void course::printCourse(ostream &os)const{
	os << "\n      �ҵ{�W��: " << m_name << '\n'
	   << "        �Ҹ�: " << m_ID << '\n'
	   << "        �}�Ҧ~��: " << m_year << '\n'
	   << "        �}�ҾǴ�: " << m_semester << '\n'
	   << "        �½ҦѮv: ";
	m_teacher->printName(os);
	if(m_department){
		m_department->printName(os);
	}
	else{
		m_institute->printName(os);
	}
}

bool course::queryCourseBasicsByName(string name, ostream &os){
	if(name == m_name){
		printCourse(os);
		return true;
	}
	return false;
}

bool course::queryCourseBasicsById(string ID, ostream &os){
	if(ID == m_ID){
		printCourse(os);
		return true;
	}
	return false;
}