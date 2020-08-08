#pragma once
#include "Grade.h"
#include<fstream>

class Student
{
public:
	Student(void);
	~Student(void);
public:
	void addNewStudent(const string &inName, const string &s);//�W�[�@�ǥ�
	void addGrade(const int &score);//��@�ǥͼW�[�@���Z�A�|�Ψ�grade
	void printGrade(void);// const;//�L�X�ӥͥ������Z�A�|�Ψ�grade
	void changeGrade(const int &index) ;//��令�Z�A�|�Ψ�grade
	bool sameName(const string &inName) const;//��ǥͥΪ�(�R���B���......)
	bool sameId(const string &s) const;
	void printNameIdGrade(void);
	void printAll(void);
	static bool cmpId(Student * a, Student * b);//�e���X�{static �����const
	void inputComment(const int &index, const string &comment);
	void outputNameToFile(ofstream &outFile);
	void outputGradeToFile(ofstream &outFile);
	void addCommentsFromFile(string &str);
private:
	Grade grade;
	string name;//string include in "Grade.h"
	string id;
};

