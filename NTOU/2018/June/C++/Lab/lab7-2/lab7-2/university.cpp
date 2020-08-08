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
	cout << "學校名稱: " << m_name << '\n';
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
    cout << "   1. 結束本程式\n";
    cout << "   2. 查詢教師基本資料\n";
    cout << "   3. 查詢課程基本資料\n";
    cout << "   4. 查詢教師開授課程\n";
    cout << "   5. 查詢系所課程\n";
    cout << "   6. 查詢系所教師\n";
    cout << "   7. 新增課程\n";
    cout << "   8. 新增教師\n";
    cout << "請選擇功能 : ";
    cin >> option;
	if(cin.fail()){
		cin.clear();
		cerr << "請輸入正確的數字\n";
	}
    cin.getline(buf, 50, '\n');
    
    switch (option)
    {
    case 1:
        return false;
    case 2: /* 列印教師基本資料 */
        os << "請輸入教師姓名: ";
        cin.getline(buf, 50, '\n');
		teacher* tmp;
		if(!strlen(buf))
			os << "未輸入資料!!\n";
		else{
			if(!(tmp = queryTeacherBasicsByName(string(buf))))
				os << "      沒有找到所輸入的教師\n";
			else{
				tmp->printTeacher(os);
			}
		}
        break;
	case 3:
		os << "請輸入課程名稱: ";
        cin.getline(buf, 50, '\n');
		if(!strlen(buf)){
			os << "請輸入課程代碼: ";
			cin.getline(buf, 50, '\n');
			if(!strlen(buf))
				os << "未輸入資料!!\n";
			else {
				if(!queryCourseBasicsById(string(buf), os))//找到會自己印
				os << "      沒有找到所指定的課程\n";
			}
		}
		else{
			if(!queryCourseBasicsByName(string(buf), os))//找到會自己印
				os << "      沒有找到所指定的課程\n";
		}
		break;
	case 4:
		os << "請輸入教師姓名: ";
        cin.getline(buf, 50, '\n');
		if(!strlen(buf))
			os << "未輸入資料!!\n";
		else {
			if(!(tmp = queryTeacherBasicsByName(string(buf))))
				os << "      沒有找到所輸入的教師\n";
			else{
				tmp->printCourse(os);
			}
		}
		break;
	case 5:
		os << "請輸入系所名稱: ";
        cin.getline(buf, 50, '\n');
		department* tmp1;
		institute* tmp2;
		if(!strlen(buf))
			os << "未輸入資料!!\n";
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
				os<<"      沒有找到所指定的系所\n";
		}
		break;
	case 6:
		os << "請輸入系所名稱: ";
        cin.getline(buf, 50, '\n');
		if(!strlen(buf))
			os << "未輸入資料!!\n";
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
				os<<"      沒有找到所指定的系所\n";
			break;
		}
	default:
		break;
    }
	return true;
}
