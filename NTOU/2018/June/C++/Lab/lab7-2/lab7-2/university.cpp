#include "university.h"
#include "teacher.h"
#include <cstring>


university::university(ifstream &infile)
{
	infile >> m_name;
	infile >> collegeNum;
	int i;
	m_colleges.resize(collegeNum);
	for(i = 0; i < collegeNum; i++){
		m_colleges[i] = new college(infile);
	}
}


university::~university(void)
{
}


void university::printUniversity(ostream &os)
{
	cout << "�ǮզW��: " << m_name << '\n';
	int i;
	for(i = 0;i < collegeNum; i++){
		m_colleges[i]->printCollege(os);
	}
}

void university::deleteDepartmentOfAllCollege(void)
{
	int i;
	for(i = collegeNum - 1; i >= 0; i--){
		m_colleges[i]->deleteAllDepartment();
		delete m_colleges[i];
		m_colleges.pop_back();
	}
}

teacher* university::queryTeacherBasicsByName(string name){
	vector<college*>::iterator iter;
	teacher *tmp;
	for(iter = m_colleges.begin(); iter < m_colleges.end(); iter++){
		tmp = (*iter)->queryTeacherBasicsByName(name);
		if(tmp)
			return tmp;
	}
	return NULL;
}

bool university::queryCourseBasicsByName(string name, ostream &os){
	vector<college*>::iterator iter;
	for(iter = m_colleges.begin(); iter < m_colleges.end(); iter++){
		if((*iter)->queryCourseBasicsByName(name, os))
			return true;
	}
	return false;
}

department* university::queryDepartmentBasicsByName(string name){
	vector<college*>::iterator iter;
	department *tmp;
	for(iter = m_colleges.begin(); iter < m_colleges.end(); iter++){
		if(tmp = (*iter)->queryDepartmentBasicsByName(name))
			return tmp;
	}
	return NULL;
}

institute* university::queryInstituteBasicsByName(string name){
	vector<college*>::iterator iter;
	institute *tmp;
	for(iter = m_colleges.begin(); iter < m_colleges.end(); iter++){
		if(tmp = (*iter)->queryInstituteBasicsByName(name))
			return tmp;
	}
	return NULL;
}

bool university::queryCourseBasicsById(string ID, ostream &os){
	vector<college*>::iterator iter;
	for(iter = m_colleges.begin(); iter < m_colleges.end(); iter++){
		if((*iter)->queryCourseBasicsById(ID, os))
			return true;
	}
	return false;
}

void university::unitTest()
    {
        ifstream infile("ntou2.txt");
        if (!infile)
            std::cout << "Cannot open ntou2.txt!!\n";
        else
        {
            university ntou(infile);
            ntou.printUniversity(cout);
        }
    }

bool university::query(ostream &os)
{
    using namespace std;
    int option;
    char buf[50];
	cout << "\n   -----------------------\n";
    cout << "   1. �������{��\n";
    cout << "   2. �d�߱Юv�򥻸��\n";
    cout << "   3. �d�߽ҵ{�򥻸��\n";
    cout << "   4. �d�߱Юv�}�½ҵ{\n";
    cout << "   5. �d�ߨt�ҽҵ{\n";
    cout << "   6. �d�ߨt�ұЮv\n";
    cout << "   7. �s�W�ҵ{\n";
    cout << "   8. �s�W�Юv\n";
    cout << "�п�ܥ\�� : ";
    cin >> option;
	if(cin.fail()){
		cin.clear();
		cerr << "�п�J���T���Ʀr\n";
	}
    cin.getline(buf, 50, '\n');
    
    switch (option)
    {
    case 1:
        return false;
    case 2: /* �C�L�Юv�򥻸�� */
        os << "�п�J�Юv�m�W: ";
        cin.getline(buf, 50, '\n');
		teacher* tmp;
		if(!strlen(buf))
			os << "����J���!!\n";
		else{
			if(!(tmp = queryTeacherBasicsByName(string(buf))))
				os << "      �S�����ҿ�J���Юv\n";
			else{
				tmp->printTeacher(os);
			}
		}
        break;
	case 3:
		os << "�п�J�ҵ{�W��: ";
        cin.getline(buf, 50, '\n');
		if(!strlen(buf)){
			os << "�п�J�ҵ{�N�X: ";
			cin.getline(buf, 50, '\n');
			if(!strlen(buf))
				os << "����J���!!\n";
			else {
				if(!queryCourseBasicsById(string(buf), os))//���|�ۤv�L
				os << "      �S�����ҫ��w���ҵ{\n";
			}
		}
		else{
			if(!queryCourseBasicsByName(string(buf), os))//���|�ۤv�L
				os << "      �S�����ҫ��w���ҵ{\n";
		}
		break;
	case 4:
		os << "�п�J�Юv�m�W: ";
        cin.getline(buf, 50, '\n');
		if(!strlen(buf))
			os << "����J���!!\n";
		else {
			if(!(tmp = queryTeacherBasicsByName(string(buf))))
				os << "      �S�����ҿ�J���Юv\n";
			else{
				tmp->printCourse(os);
			}
		}
		break;
	case 5:
		os << "�п�J�t�ҦW��: ";
        cin.getline(buf, 50, '\n');
		department* tmp1;
		institute* tmp2;
		if(!strlen(buf))
			os << "����J���!!\n";
		else {
			if(tmp1 = queryDepartmentBasicsByName(buf)){
				tmp1->printName(os);
				tmp1->printCourses(os);
			}
			else if(tmp2 = queryInstituteBasicsByName(buf)){
				tmp2->printName(os);
				tmp2->printCourses(os);
			}
			else
				os<<"      �S�����ҫ��w���t��\n";
		}
		break;
	case 6:
		os << "�п�J�t�ҦW��: ";
        cin.getline(buf, 50, '\n');
		if(!strlen(buf))
			os << "����J���!!\n";
		else {
			if(tmp1 = queryDepartmentBasicsByName(buf)){
				tmp1->printName(os);
				tmp1->printTeachersName(os);
			}
			else if(tmp2 = queryInstituteBasicsByName(buf)){
				tmp2->printName(os);
				tmp2->printTeachersName(os);
			}
			else
				os<<"      �S�����ҫ��w���t��\n";
			break;
		}
	default:
		break;
    }
	return true;
}
