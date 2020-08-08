#pragma once
#include"Student.h"
#include<iostream>
#include<string>
using namespace std;
class Class
{
public:
	Class(void);
	~Class(void);
private:
	int studentNum;
	Student *students[100];
	int findStudent(const string &inName) const;
	bool inputFromFile(const string & fileName);
	void outputAFile(const string &fileName);
	void inputGrade(const int &studentPos);
public:
	static void uniTest();
	void query(void);
	void addNewStudent(void);
	void addGrade(void);
	void printGrade(void);
	void changeGrade(void);
	void deleteStudent(void);
	void printAll(void);
	void sortStudent(void);
	void serialInputGrade(void);
	void inputComment(void);
};