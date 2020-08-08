#include "Institute.h"


institute::institute(ifstream &infile)
{
	infile >> m_name >> teacherNum;
	int i;
	m_teachers.resize(teacherNum);
	for(i = 0; i < teacherNum; i++){
		m_teachers[i] = new teacher(infile, this);
	}
	infile >> courseNum;
	m_courses.resize(courseNum);
	for(i = 0; i < courseNum; i++){
		m_courses[i] = new course(infile, this);
	}
}


institute::~institute(void)
{
}


void institute::printName(ostream &os)const{
	os << "      研究所名稱: " << m_name << '\n';
}

void institute::printInstitute(ostream &os)const
{
	printName(os);
	int i;
	if(!teacherNum)
		os<<"      無教師資料\n";
	else{
		for(i = 0; i < teacherNum; i++){
			os << "      教師姓名: ";
			m_teachers[i]->printName(os);
		}
	}
	if(!courseNum)
		os<<"      無課程資料\n";
	else{
		for(i = 0; i < courseNum; i++){
			m_courses[i]->printCourse(os);
		}
	}
}

void institute::printCourses(ostream &os){
	vector<course*>::iterator iter;
	for(iter = m_courses.begin(); iter < m_courses.end(); iter++){
		(*iter)->printCourse(os);
	}			
}

void institute::printTeachersName(ostream &os){
	vector<teacher*>::iterator iter;
	for(iter = m_teachers.begin(); iter < m_teachers.end(); iter++){
			os << "             ";
			(*iter)->printName(os);
	}
}

teacher* institute::queryTeacherBasicsByName(string name){
	vector<teacher*>::iterator iter;
	for(iter = m_teachers.begin(); iter < m_teachers.end(); iter++){
			if((*iter)->queryTeacherBasicsByName(name))
				return (*iter)->queryTeacherBasicsByName(name);
	}
	return NULL;
}

bool institute::queryCourseBasicsByName(string name, ostream &os){
	vector<course*>::iterator iter;
	for(iter = m_courses.begin(); iter < m_courses.end(); iter++){		
		if((*iter)->queryCourseBasicsByName(name, os))
			return true;
	}
	return false;
}

institute* institute::queryInstituteBasicsByName(string name){
	if(name == m_name)
		return this;
	return false;
}

bool institute::queryCourseBasicsById(string ID, ostream &os){
	vector<course*>::iterator iter;
	for(iter = m_courses.begin(); iter < m_courses.end(); iter++){		
		if((*iter)->queryCourseBasicsById(ID, os))
			return true;
	}
	return false;
}

void institute::deleteAllteacherAndCourse(void){
	int i;
	for(i = 0; i < courseNum; i++){
		delete m_courses.back();
		m_courses.pop_back();
	}
	for(i = 0; i < teacherNum; i++){
		delete m_teachers.back();
		m_teachers.pop_back();
	}
}