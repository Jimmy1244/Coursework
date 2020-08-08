#include "Student.h"


Student::Student(const char *name, const char *ID, 
                const char *phone, const char *department)
				:m_name(name), m_ID(ID), m_phone(phone), m_department(department)
{
}


Student::~Student(void)
{
}

void Student::display(ostream &os)const{
	os << m_name << ' ' << m_ID << ' ' << m_phone << ' ' << m_department << '\n';
}

bool Student::equal(char *ID)const{
	int i;
	for(i = 0; ID[i]!='\0'; i++){
		if(ID[i] != m_ID[i])
			return false;
	}
	return true;
}