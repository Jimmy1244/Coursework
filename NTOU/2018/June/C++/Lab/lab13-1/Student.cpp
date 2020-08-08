#include "Student.h"
#include<iomanip>


Student::Student()
	:m_name(0), m_ID(0), m_phone(0), m_department(0)
{
}

Student::Student(const char *name, const char *ID, 
                const char *phone, const char *department)
				:m_name(name), m_ID(ID), m_phone(phone), m_department(department)
{
}


Student::~Student(void)
{
}

void Student::display(ostream &os)const{
	os << left << setw(10) << m_name << '\t' << m_ID << '\t' << m_phone <<'\t' << m_department;
}

bool Student::equalID(char *ID)const{
	int i;
	for(i = 0; ID[i]!='\0'; i++){
		if(ID[i] != m_ID[i])
			return false;
	}
	return true;
}

bool Student::ofTheSameDepartment(Student &student2){
	int i;
	for(i = 0; m_department[i] != '\0'; i++){
		if(student2.m_department[i] != m_department[i])
			return false;
	}
	return true;
}