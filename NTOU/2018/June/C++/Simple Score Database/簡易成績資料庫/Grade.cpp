#include "Grade.h"
#include "statistic.h"


Grade::Grade(void)
	: grades(new int[6])
	, comments(new string[6])
	, gradeNum(0)
	, commentNum(0)
{
}


Grade::~Grade(void)
{
	delete[] grades;
	delete[] comments;
}

bool Grade::isFull(void) const{
	return gradeNum == 6? true : false;
}

bool Grade::isEmpty(void) const {
	return !gradeNum;
}

void Grade::addGrade(const int &score){
	if(isFull()){
		cout<< " 該學生成績不能再多了!\n";
		return;
	}
	grades[gradeNum++] = score;
}

void Grade::changeGrade(const int &index){
	if(index > gradeNum || index < 0){
		cout << "亂改，成績才" << gradeNum << "筆而已!\n";
		return;
	}
	cout << "請輸入成績：";
	int score;
	cin >> score;
	grades[index - 1] = score;
}

void Grade::printGrade(void){
	int i;
	if(!gradeNum){
		cout << "No grades" << endl;
		return;
	}
	for(i = 0; i < gradeNum; i++){
		cout << grades[i] << comment(i);
	}
	cout << endl;
}

void Grade::printGradeAverage(void) const{
	double ave = average(grades, gradeNum);
	cout << ">>平均成績是：";
	if(ave)
		cout << ave;
	else
		cout << "No grades";
	cout << endl;
}

string Grade::comment(const int &index){
	string str = " ";
	if(comments[index].size()){
		str = "(" + comments[index] + ") ";
		return str;
	}
	return str;
}

void Grade::inputComment(const int &index, const string &str){
	if(index >= gradeNum){
		cout << "註記位置大於成績數量\n";
		return;
	}
	comments[index] = str;
}

void Grade::outputGradeToFile(ofstream &outFile){
	outFile.write((char*) &gradeNum, sizeof(int));
	int i;
	for(i = 0; i < gradeNum; i++){
		outFile.write((char*) (grades + i), sizeof(int));
		outFile << comments[i] << "\n";
	}
}

void Grade::addCommentsFromFile(const string &str){
	comments[commentNum++] = str;
}