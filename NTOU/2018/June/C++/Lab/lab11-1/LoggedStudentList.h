#include "StudentList.h"

class LoggedStudentList : public StudentList
{
public:
	LoggedStudentList(ostream &os);//不知道為甚麼可以用ofstream;
	void appendEntry(Student *student);
	bool deleteEntry(char *id);
	void insertEntry(Iterator &iter, Student *student);
	void dump();
private:
	ostream &m_ofs;
};