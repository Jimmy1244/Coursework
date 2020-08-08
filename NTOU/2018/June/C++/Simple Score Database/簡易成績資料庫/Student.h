#pragma once
#include "Grade.h"
#include<fstream>

class Student
{
public:
	Student(void);
	~Student(void);
public:
	void addNewStudent(const string &inName, const string &s);//增加一學生
	void addGrade(const int &score);//對一學生增加一成績，會用到grade
	void printGrade(void);// const;//印出該生全部成績，會用到grade
	void changeGrade(const int &index) ;//更改成績，會用到grade
	bool sameName(const string &inName) const;//找學生用的(刪除、更改......)
	bool sameId(const string &s) const;
	void printNameIdGrade(void);
	void printAll(void);
	static bool cmpId(Student * a, Student * b);//前面出現static 不能用const
	void inputComment(const int &index, const string &comment);
	void outputNameToFile(ofstream &outFile);
	void outputGradeToFile(ofstream &outFile);
	void addCommentsFromFile(string &str);
private:
	Grade grade;
	string name;//string include in "Grade.h"
	string id;
};

