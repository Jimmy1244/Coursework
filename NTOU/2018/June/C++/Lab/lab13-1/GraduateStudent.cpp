#include"GraduateStudent.h"

GraduateStudent::GraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *advisor)
	:Student(name, ID, phone, department), m_advisor(advisor)
{
}

void GraduateStudent::display(ostream &os) const{
	Student::display(os);
	os << "\t\t" << m_advisor;
}