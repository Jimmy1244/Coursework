#include "StudentList.h"

class LoggedStudentList : public StudentList
{
public:
	LoggedStudentList(ostream &os);//�����D���ƻ�i�H��ofstream;
	void appendEntry(Student *student);
	bool deleteEntry(char *id);
	void insertEntry(Iterator &iter, Student *student);
	void dump();
private:
	ostream &m_ofs;
};