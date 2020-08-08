#pragma once

#include"Student.h"

class GraduateStudent: public Student
{
public:
	GraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *dvisor);
	virtual void display(ostream &os) const override;//在compile時確定是不是override
private:
	const char* m_advisor;
};