#include <fstream>

#include "LoggedStudentList.h"
#include "Iterator.h"

LoggedStudentList::LoggedStudentList(const char* filename) throw(const char*)//­n¤£­n¼gthrow©O??
{
	m_ofs.open(filename);
	if(!m_ofs.is_open())
		throw filename;
}

void LoggedStudentList::appendEntry(Student *student){
	m_ofs <<  "LoggedStudentList::appendEntry()\n\t" ;
	student->display(m_ofs);
	StudentList::appendEntry(student);
}

bool LoggedStudentList::deleteEntry(char *id){
	m_ofs <<  "LoggedStudentList::deleteEntry()  " ;
	m_ofs << "id=" << id << '\n';
	return StudentList::deleteEntry(id);	
}

void LoggedStudentList::insertEntry(Iterator &iter, Student *student){
	m_ofs <<  "LoggedStudentList::insertEntry()s\n\t" ;
	student->display(m_ofs);
	StudentList::insertEntry(iter, student);
}

void LoggedStudentList::dump(){
	m_ofs << "List dumping\n";
	int count;
	for(count = 0; count < size(); count++){
		m_ofs << "Element[" << count << "]: ";
		StudentList::operator[](count)->display(m_ofs);
	}
}