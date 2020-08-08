#include"ForeignGraduateStudent.h"

ForeignGraduateStudent::ForeignGraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *advisor, const char* nationality)
			:GraduateStudent(name, ID, phone, department, advisor), m_nationality(nationality)
{
}

void ForeignGraduateStudent::display(ostream &os)const
{
	GraduateStudent::display(os);
	os << "\t\t" << m_nationality;
}