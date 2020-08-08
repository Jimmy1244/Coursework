#pragma once

#include "Student.h"

class UndergraduateStudent: public Student
{
public:
	UndergraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *academicAdvisor);
	void display(ostream &os) const override;
private:
	const char * m_academicAdvisor;
};