#include "college.h"
#include "teacher.h"


college::college(ifstream &infile)
{
	infile >> m_name;
	infile >> departmentNum;
	int i;
	m_departments.resize(departmentNum);
	for(i = 0; i < departmentNum; i++){
		m_departments[i] = new department(infile);
	}
	infile >> instituteNum;
	m_institutes.resize(instituteNum);
	for(i = 0; i < instituteNum; i++){
		m_institutes[i] = new institute(infile);
	}
}


college::~college(void)
{
}


void college::deleteDepartment(const int & index)
{
	department * tmp = m_departments[index];
	m_departments[index] = m_departments.back();
	m_departments.back() = tmp;
	delete m_departments.back();
	m_departments.pop_back();
}


void college::setCollegeName(ifstream & infile)
{
	infile >> m_name;
}

void college::printCollege(ostream &os)
{
	cout << "  ¾Ç°|¦WºÙ: " << m_name << '\n';
	int i;
	for(i = 0; i < departmentNum; i++){
		m_departments[i]->printDepartment(os);
	}
	for(i = 0; i < instituteNum; i++){
		m_institutes[i]->printInstitute(os);
	}
}


void college::deleteAllDepartment(void)
{
	int i;
	for(i = 0; i < departmentNum; i++){
		m_departments.back()->deleteAllteacherAndCourse();
		delete m_departments.back();
		m_departments.pop_back();
	}
	for(i = 0; i < instituteNum; i++){
		m_institutes.back()->deleteAllteacherAndCourse();
		delete m_institutes.back();
		m_institutes.pop_back();
	}
}

teacher* college::queryTeacherBasicsByName(string name){
	vector<department*>::iterator iter1;
	teacher* tmp;
	for(iter1 = m_departments.begin(); iter1 < m_departments.end(); iter1++){
		tmp = (*iter1)->queryTeacherBasicsByName(name);
		if(tmp)
			return tmp;
	}
	vector<institute*>::iterator iter2;
	for(iter2 = m_institutes.begin(); iter2 < m_institutes.end(); iter2++){
		tmp = (*iter2)->queryTeacherBasicsByName(name);
		if((*iter2)->queryTeacherBasicsByName(name))
			return tmp;
	}
	return NULL;
}

bool college::queryCourseBasicsByName(string name, ostream &os){
	vector<department*>::iterator iter1;
	for(iter1 = m_departments.begin(); iter1 < m_departments.end(); iter1++){
		if((*iter1)->queryCourseBasicsByName(name, os))
			return true;
	}
	vector<institute*>::iterator iter2;
	for(iter2 = m_institutes.begin(); iter2 < m_institutes.end(); iter2++){
		if((*iter2)->queryCourseBasicsByName(name, os))
			return true;
	}
	return false;
}

department* college::queryDepartmentBasicsByName(string name){
	vector<department*>::iterator iter;
	for(iter = m_departments.begin(); iter < m_departments.end(); iter++){
		if((*iter)->queryDepartmentBasicsByName(name))
			return (*iter)->queryDepartmentBasicsByName(name);
	}
	return false;
}

institute* college::queryInstituteBasicsByName(string name){
	vector<institute*>::iterator iter;
	for(iter = m_institutes.begin(); iter < m_institutes.end(); iter++){
		if((*iter)->queryInstituteBasicsByName(name))
			return (*iter)->queryInstituteBasicsByName(name);
	}
	return false;
}

bool college::queryCourseBasicsById(string ID, ostream &os){
	vector<department*>::iterator iter1;
	for(iter1 = m_departments.begin(); iter1 < m_departments.end(); iter1++){
		if((*iter1)->queryCourseBasicsById(ID, os))
			return true;
	}
	vector<institute*>::iterator iter2;
	for(iter2 = m_institutes.begin(); iter2 < m_institutes.end(); iter2++){
		if((*iter2)->queryCourseBasicsById(ID, os))
			return true;
	}
	return false;
}