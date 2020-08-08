#include <fstream>

#include "LoggedStudentList.h"
#include "Iterator.h"

LoggedStudentList::LoggedStudentList(ostream &os):m_ofs(os){}

void LoggedStudentList::appendEntry(Student *student){
	m_ofs <<  "LoggedStudentList::appendEntry()\n\t" ;
	student->display(m_ofs);
	StudentList::appendEntry(student);
	m_ofs << '\n';
}

bool LoggedStudentList::deleteEntry(char *id){
	m_ofs <<  "LoggedStudentList::deleteEntry()  " ;
	m_ofs << "id=" << id << '\n';
	return StudentList::deleteEntry(id);	
	m_ofs << '\n';
}

void LoggedStudentList::insertEntry(Iterator &iter, Student *student){
	m_ofs <<  "LoggedStudentList::insertEntry()\n\t" ;
	student->display(m_ofs);
	StudentList::insertEntry(iter, student);
	m_ofs << '\n';
}

void LoggedStudentList::dump(){
	m_ofs << "List dumping\n";
	int count;
	for(count = 0; count < size(); count++){
		m_ofs << "Element[" << count << "]: ";
		StudentList::operator[](count)->display(m_ofs);
		m_ofs << '\n';
	}
}