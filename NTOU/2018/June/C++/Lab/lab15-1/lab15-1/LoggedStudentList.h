#include "StudentList.h"

class LoggedStudentList : public StudentList
{
public:
	LoggedStudentList(const char * filename);
	LoggedStudentList(){};
	void appendEntry(Student *student);
	bool deleteEntry(char *id);
	void insertEntry(Iterator &iter, Student *student);
	void dump();
private:
	ofstream m_ofs;
};