#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class Grade
{
public:
	Grade(void);
	~Grade(void);
public:
	bool sameGrade(const int &index, const int &score) const;
	void addGrade(const int &score);
	void changeGrade(const int &index);
	void printGrade(void);//改const 會出錯，因為裡面會用到comment()，comment會改變值
	void printGradeAverage(void) const;
	void inputComment(const int &index, const string &str);
	void outputGradeToFile(ofstream &outFile);
	void addCommentsFromFile(const string &str);
private:
	bool isFull(void) const;
	bool isEmpty(void) const;
	string comment(const int &index);
private:
	int *grades;
	string *comments;
	int gradeNum;
	int commentNum;
};

