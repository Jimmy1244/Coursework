#include "UndergraduateStudent.h"

UndergraduateStudent::UndergraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *academicAdvisor)
			:Student(name, ID, phone, department), m_academicAdvisor(academicAdvisor)
{
}

void UndergraduateStudent::display(ostream &os) const
{
	Student::display(os);
	os << "\t\t" << m_academicAdvisor;
}