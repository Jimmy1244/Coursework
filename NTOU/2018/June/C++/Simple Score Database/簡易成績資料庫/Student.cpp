#include "Student.h"


Student::Student(void)
{
}


Student::~Student(void)
{
}

void Student::addGrade(const int &score)
{
	grade.addGrade(score);
}

void Student::printGrade(void){
	grade.printGrade();
}

void Student::addNewStudent(const string &InName, const string &s){
	name = InName;
	id = s;
}

void Student::changeGrade(const int &index){
	grade.changeGrade(index);
}

bool Student::sameName(const string &inName) const{
	if(name == inName)
		return true;
	return false;
}

bool Student::sameId(const string &s) const{
	if(id == s)
		return true;
	return false;
}

void Student::printNameIdGrade(void){
	cout << ">>姓名：" << name << "\n>>學號：" << id << "\n>>成績：";
	grade.printGrade();
}

void Student::printAll(void){
	printNameIdGrade();
	grade.printGradeAverage();
	cout << "\n";
}

bool Student::cmpId(Student * a, Student * b) {
	return (a->id.compare(b->id) < 0 ? true : false);
}

void Student::inputComment(const int &index, const string &comment){
	grade.inputComment(index, comment);
}

void Student::outputNameToFile(ofstream &outFile){
	string tempName = name + "\n", tmpId = id + "\n";
	outFile << tempName;
	outFile << tmpId;
}

void Student::outputGradeToFile(ofstream &outFile){
	grade.outputGradeToFile(outFile);
}

void Student::addCommentsFromFile(string &str){
	grade.addCommentsFromFile(str);
}