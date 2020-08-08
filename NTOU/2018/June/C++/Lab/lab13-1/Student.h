#pragma once

#include<iostream>

using namespace std;

class Student
{
public:
	Student();
    Student(const char *name, const char *ID, 
            const char *phone, const char *department);
    ~Student();
    virtual void display(ostream &os)const;
	bool equalID(char *ID)const;
	bool ofTheSameDepartment(Student &student2);
private:
    const char *m_name;
    const char *m_ID;
    const char *m_phone;
    const char *m_department;
};