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
		cerr << "����Ū���ɮ�\n\n";
		return false;
	}
	inputFile.read((char*)&studentNum, sizeof(int));
	int i;
	for(i = 0; i < studentNum; i++){
		string name, id;
		inputFile >> name;//�ոլݯण��o��Ūstring
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
		cerr<<"����g�J�ɮ�\n";
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
	cout << "�п�J���Z�G";
	cin >> score;
	students[studentPos]->addGrade(score);
}

void Class::addGrade(void){
	cout << "�п�J�ǥͩm�W:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if(studentPos == -1){
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
		return;
	}
	inputGrade(studentPos);
}

void Class::addNewStudent(void){
	if(studentNum == 100) {
		cout << "�H��\n";
		return;
	}
	cout << "�п�J�ǥͩm�W�G";
	string inName;
	cin >> inName;
	if(inName.size() > 10){
		cout << "�W�r�Ӫ��F!\n";
		return;
	}
	if(findStudent(inName) == -1) {
		cout << "�п�J�ǥ;Ǹ��G";
		string s;
		cin >> s;
		if(s.size() > 4){
			cout << "�Ǹ��Ӫ��F!\n";
			return;
		}
		int i;
		for(i = 0; i < studentNum; i++){
			if(students[i]->sameId(s)){
				cout << "�Ǹ����ƤF!\n";
				return;
			}
		}
		students[studentNum] = new Student[1];
		students[studentNum++]->addNewStudent(inName, s);
	}
	else
		cout << ">>��Ʈw���w�g�����@�ǥ�\n";
}


void Class::printGrade(void){
	cout << "�п�J�ǥͩm�W:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if (studentPos == -1){
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
		return;
	}
	students[studentPos]->printGrade();
}

void Class::changeGrade(void){
	cout << "�п�J�ǥͩm�W:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if (studentPos == -1){
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
		return;
	}
	students[studentPos]->printNameIdGrade();
	cout << "�аݭn�ק�ĴX�����Z�G";
	int index, score;
	cin >> index;
	students[studentPos]->changeGrade(index);
}

void Class::deleteStudent(void){
	cout << "�п�J�ǥͩm�W:";
	string s;
	cin >> s;
	int studentPos = findStudent(s);
	if (studentPos == -1){
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
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
		cout << ">>��Ʈw���S��������\n";
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
			if (Student::cmpId(students[minPos], students[j])) {//����j true
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
	cout << "�п�J�ǥͩm�W:";
	string comment, studentName;
	cin >> studentName;
	int studentPos = findStudent(studentName);
	students[studentPos]->printNameIdGrade();
	cout << "�п�J����:";
	cin >> comment;
	cout << "�п�J���Ѧ�m(�Ĥ@�Ӧ��Z��0):";
	cin >> index;
	students[studentPos]->inputComment(index, comment);
}

void Class::query(void)
{
	int operation = 0;
	while(operation != 2) {
		cout << "---�п�ܤU�C�\��G\n1�G��J��Ʈw�ɮצW��\n2�G�����ާ@\n";
		if((cin >> operation).fail()){
			cin.clear();
			cin.ignore(128, '\n');
			continue;
		}
		getchar();
		if(operation == 2)
			break;
		cout << "�п�J�ɮצW�١G";
			string filename;
			cin >> filename;
			if(!inputFromFile(filename))
				continue;
		while (operation == 1) {
			cout << "---\n";
			cout <<	"<" << filename << ">�п�ܤU�C�\��G\n"
					"1�G�W�[�@�s�ǥ�\n"
					"2�G��@�ǥͼW�[�@�s���Z\n"
					"3�G�d�ߤ@�ǥͤ��Ҧ����Z\n"
					"4�G���@�ǥͤ����Z\n"
					"5�G�R���Y�@�ǥ�\n"
					"6�G�C�L��ܩҦ���Ʈw�������\n"
					"7�G�s���J�h��P�Ǧ��Z\n"
					"8�G�[�W���Z����\n";
			cout <<	"9�G�s�ɨ�����" << filename << "�ɮ�\n"
					"10�G�����ާ@\n";
			operation = 0;//�קKoperationŪ�����ѡAoperation ���M��1
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
			case 7://�s���J�h��P�Ǧ��Z
				sortStudent();
				serialInputGrade();
				operation = 1;
				break;
			case 8://�[�W���Z����
				inputComment();
				operation = 1;
				break;
			case 9:
				outputAFile(filename);
				operation = 0;//�^��Ĥ@�Ӱ��D
				break;
			case 10:
				operation = 2;//��������
				break;
			default://�ÿ�J�B�z
				string buf;
				cin.clear();//���e��cin >> operation �|�ߤ@�ӿ��~��flag�A��clear�M��
				do{
					cout << "�п�J���T���Ʀr�A��0�~��...";
					cin >> buf;
				}while(buf != "0");
				getchar();
				operation = 1;//���}switch��^��j��
			}
		}
		int i;
		for(i = 0; i < studentNum; i++){
			delete students[i];
		}
	}
}