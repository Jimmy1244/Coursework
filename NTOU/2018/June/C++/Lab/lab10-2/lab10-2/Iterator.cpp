#include "Iterator.h"
#include "Student.h"


Iterator::Iterator(StudentList &list)
{
	m_list = &list;
	m_iterator = m_list->m_head;
}

Student Iterator::m_dummy;

Iterator::~Iterator(void)
{
}

void Iterator::reset(){
	m_iterator = m_list->m_head;
}

void Iterator::next(){
	m_iterator = m_iterator->m_next;
}

Student &Iterator::operator*()const{
	if(m_iterator->m_data)
		return *m_iterator->m_data;
	return m_dummy;
}

Student *Iterator::operator->()const{
	if(m_iterator->m_data)
		return m_iterator->m_data;
	return &m_dummy;
}

bool Iterator::hasMoreData()const{
	if(m_iterator)
		return true;
	return false;
}