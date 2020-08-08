#include "Class.h"
#include<fstream>
#include<algorithm>
#include<fstream>

Class::Class(void)
	: students()
	, studentNum(0)
{
}


Class::~Class(void)
{
}

bool Class::inputFromFile(const string &fileName){
	/*
	studentNum
		studentName
		studentId
		gradeNum
			grade
			comments
	*/
	ifstream inputFile(fileName, ifstream::binary);
	if(!inputFile){
		cerr << "不能讀取檔案\n\n";
		return false;
	}
	inputFile.read((char*)&studentNum, sizeof(int));
	int i;
	for(i = 0; i < studentNum; i++){
		string name, id;
		inputFile >> name;//試試看能不能這樣讀string
		inputFile >> id;
		inputFile.ignore(1,'\n');
		students[i] = new Student;
		students[i]->addNewStudent(name, id);
		int gradeNum;
		inputFile.read((char*)&gradeNum, sizeof(int));
		int j;
		for(j = 0; j < gradeNum; j++){
			int grade;
			inputFile.read((char*)&grade, sizeof(int));
			students[i]->addGrade(grade);
			string comments;
			if(inputFile.peek() != '\n'){
				inputFile >> comments;
				students[i]->addCommentsFromFile(comments);
			}
			inputFile.ignore(1,'\n');
		}
	}
	inputFile.close();
	return true;
}

void Class::outputAFile(const string &fileName){
	/*
	studentNum
		studentName
		studentId
		gradeNum
			grade
			comments
	*/
	ofstream outFile(fileName, ofstream::binary);
	if(!outFile){
		cerr<<"不能寫入檔案\n";
		return;
	}
	outFile.write((char*) &studentNum, sizeof(int));
	int i;
	for(i = 0; i < studentNum; i++){
		students[i]->outputNameToFile(outFile);
		students[i]->outputGradeToFile(outFile);
	}
	outFile.close();
}

int Class::findStudent(const string &inName) const{
	int i;
	for(i = 0; i < studentNum; i++){
		if(students[i]->sameName(inName))
			return i;
	}
	return -1;
}

void Class::inputGrade(const int &studentPos){
	int score;
	cout << "請輸入成績：";
	cin >> score;
	students[studentPos]->addGrade(score);
}

void Class::addGrade(void){
	cout << "請輸入學生姓名:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if(studentPos == -1){
		cout << ">>資料庫內找不到此學生\n";
		return;
	}
	inputGrade(studentPos);
}

void Class::addNewStudent(void){
	if(studentNum == 100) {
		cout << "人滿\n";
		return;
	}
	cout << "請輸入學生姓名：";
	string inName;
	cin >> inName;
	if(inName.size() > 10){
		cout << "名字太長了!\n";
		return;
	}
	if(findStudent(inName) == -1) {
		cout << "請輸入學生學號：";
		string s;
		cin >> s;
		if(s.size() > 4){
			cout << "學號太長了!\n";
			return;
		}
		int i;
		for(i = 0; i < studentNum; i++){
			if(students[i]->sameId(s)){
				cout << "學號重複了!\n";
				return;
			}
		}
		students[studentNum] = new Student[1];
		students[studentNum++]->addNewStudent(inName, s);
	}
	else
		cout << ">>資料庫內已經有此一學生\n";
}


void Class::printGrade(void){
	cout << "請輸入學生姓名:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if (studentPos == -1){
		cout << ">>資料庫內找不到此學生\n";
		return;
	}
	students[studentPos]->printGrade();
}

void Class::changeGrade(void){
	cout << "請輸入學生姓名:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if (studentPos == -1){
		cout << ">>資料庫內找不到此學生\n";
		return;
	}
	students[studentPos]->printNameIdGrade();
	cout << "請問要修改第幾筆成績：";
	int index, score;
	cin >> index;
	students[studentPos]->changeGrade(index);
}

void Class::deleteStudent(void){
	cout << "請輸入學生姓名:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if (studentPos == -1){
		cout << ">>資料庫內找不到此學生\n";
		return;
	}
	int i;
	delete students[studentPos];
	for(i = studentPos; i < studentNum - 1; i++){
		students[i] = students[i + 1];
	}
	studentNum--;
	students[studentNum] = NULL;
}


void Class::printAll(void){
	int i;
	if(!studentNum){
		cout << ">>資料庫內沒有任何資料\n";
	}
	for(i = 0; i < studentNum; i++){
		students[i]->printAll();
	}
}

void Class::sortStudent(){
	if(!studentNum)
		return;
	sort(students, students + studentNum, Student::cmpId);
	/*int i, j, minPos, minGrade;
	for(i = 0; i < studentNum; i++){
		minGrade == 100;
		for(j = i + 1, minPos = i; j < studentNum; j++) {
			if (Student::cmpId(students[minPos], students[j])) {//左邊大 true
				minPos = j;
			}
		}
		students[i]  = students[minPos];
	}*/
}

void Class::serialInputGrade(void){
	int i;
	for(i = 0; i < studentNum; i++){
		students[i]->printNameIdGrade();
		inputGrade(i);
	}
}

void Class::inputComment(){
	int index;
	cout << "請輸入學生姓名:";
	string comment, studentName;
	cin >> studentName;
	int studentPos = findStudent(studentName);
	students[studentPos]->printNameIdGrade();
	cout << "請輸入註解:";
	cin >> comment;
	cout << "請輸入註解位置(第一個成績為0):";
	cin >> index;
	students[studentPos]->inputComment(index, comment);
}

void Class::query(void)
{
	int operation = 0;
	while(operation != 2) {
		cout << "---請選擇下列功能：\n1：輸入資料庫檔案名稱\n2：結束操作\n";
		if((cin >> operation).fail()){
			cin.clear();
			cin.ignore(128, '\n');
			continue;
		}
		getchar();
		if(operation == 2)
			break;
		cout << "請輸入檔案名稱：";
			string filename;
			cin >> filename;
			if(!inputFromFile(filename))
				continue;
		while (operation == 1) {
			cout << "---\n";
			cout <<	"<" << filename << ">請選擇下列功能：\n"
					"1：增加一新學生\n"
					"2：對一學生增加一新成績\n"
					"3：查詢一學生之所有成績\n"
					"4：更改一學生之成績\n"
					"5：刪除某一學生\n"
					"6：列印顯示所有資料庫中之資料\n"
					"7：連續輸入多位同學成績\n"
					"8：加上成績註解\n";
			cout <<	"9：存檔並關閉" << filename << "檔案\n"
					"10：結束操作\n";
			operation = 0;//避免operation讀取失敗，operation 仍然為1
			cin >> operation;
			switch (operation) {
			case 1:
				addNewStudent();
				operation = 1;
				break;
			case 2:
				addGrade();
				operation = 1;
				break;
			case 3:
				printGrade();
				operation = 1;
				break;
			case 4:
				changeGrade();
				operation = 1;
				break;
			case 5:
				deleteStudent();
				operation = 1;
				break;
			case 6:
				printAll();
				operation = 1;
				break;
			case 7://連續輸入多位同學成績
				sortStudent();
				serialInputGrade();
				operation = 1;
				break;
			case 8://加上成績註解
				inputComment();
				operation = 1;
				break;
			case 9:
				outputAFile(filename);
				operation = 0;//回到第一個問題
				break;
			case 10:
				operation = 2;//直接關閉
				break;
			default://亂輸入處理
				string buf;
				cin.clear();//之前的cin >> operation 會立一個錯誤的flag，用clear清除
				do{
					cout << "請輸入正確的數字，按0繼續...";
					cin >> buf;
				}while(buf != "0");
				getchar();
				operation = 1;//離開switch後回到迴圈
			}
		}
		int i;
		for(i = 0; i < studentNum; i++){
			delete students[i];
		}
	}
}