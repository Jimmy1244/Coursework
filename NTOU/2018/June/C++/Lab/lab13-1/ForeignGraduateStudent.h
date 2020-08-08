#pragma once

#include"GraduateStudent.h"

class ForeignGraduateStudent: public GraduateStudent
{
public:
	ForeignGraduateStudent(const char *name, const char *ID, 
            const char *phone, const char *department, const char *advisor, const char* nationality);
	void display(ostream &os)const override;
private:
	const char *m_nationality;
};