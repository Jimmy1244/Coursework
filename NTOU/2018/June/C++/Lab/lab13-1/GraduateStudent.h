#pragma once

#include"Student.h"

class GraduateStudent: public Student
{
public:
	GraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *dvisor);
	virtual void display(ostream &os) const override;//�bcompile�ɽT�w�O���Ooverride
private:
	const char* m_advisor;
};