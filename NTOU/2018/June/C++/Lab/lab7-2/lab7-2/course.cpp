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
	infile >> buf;//找出老師指標指過去
	m_teacher = m_department->queryTeacherBasicsByName(buf);
	m_teacher->linkCourse(this);
}

course::course(std::ifstream &infile, institute* rhs)
{
	infile >> m_name >> m_ID >> m_year >> m_semester;
	m_institute = rhs;
	m_department = NULL;
	std::string buf;
	infile >> buf;//找出老師指標指過去
	m_teacher = m_institute->queryTeacherBasicsByName(buf);
	m_teacher->linkCourse(this);
}

course::~course(void)
{
}

void course::printCourse(ostream &os)const{
	os << "\n      課程名稱: " << m_name << '\n'
	   << "        課號: " << m_ID << '\n'
	   << "        開課年度: " << m_year << '\n'
	   << "        開課學期: " << m_semester << '\n'
	   << "        授課老師: ";
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