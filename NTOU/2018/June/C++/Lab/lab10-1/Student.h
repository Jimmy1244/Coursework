#pragma once

#include<iostream>

using namespace std;

class Student
{
public:
    Student(const char *name, const char *ID, 
            const char *phone, const char *department);
    ~Student();
    void display(ostream &os) const;
	bool equal(char *ID)const;
private:
    const char *m_name;
    const char *m_ID;
    const char *m_phone;
    const char *m_department;
};