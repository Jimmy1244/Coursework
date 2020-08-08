#include "StudentList.h"
#include "Student.h"
#include "Iterator.h"


StudentList::StudentList(void)
	:m_head(0), m_tail(0), m_size(0)
{

}


StudentList::~StudentList(void)
{
	delete m_head;
}

void StudentList::appendEntry(Student *student){
	if(!m_head){
		m_head = new Node(student);
		m_tail = m_head;
	}
	else {
		m_tail->m_next = new Node(student);
		m_tail = m_tail->m_next;
	}
	m_size++;
}

Student* StudentList::find(char *ID){
	Node *ptr;
	for(ptr = m_head; ptr != m_tail; ptr = ptr->m_next){
		if(ptr->m_data->equalID(ID))
			return ptr->m_data;
	}
	return 0;
}

bool StudentList::deleteEntry(char *id){
	Node *ptr1 = m_head;
	if(ptr1->m_data->equalID(id)){//頭就是尋找的student
		if(m_head = m_tail){//頭尾相等
			delete m_head;
			m_head = m_tail = 0;
			m_size--;
			return true;
		}
		m_head = ptr1->m_next;
		delete ptr1;
		m_size--;
		return true;
	}

	for(; ptr1->m_next != m_tail; ptr1 = ptr1->m_next){
		if(ptr1->m_next->m_data->equalID(id)){
			Node *ptr2 = ptr1->m_next;
			ptr1->m_next = ptr2->m_next;
			delete ptr2->m_data;
			m_size--;
			return true;
		}
	}
	return false;
}

int StudentList::size(){
	return m_size;
}

Student *&StudentList::operator[](int slot){
	int index = 0;
	Node *ptr;
	for(ptr = m_head; ptr != 0 ; ptr = ptr->m_next, index++){
		if(index == slot)
			return ptr->m_data;
	}
	return ptr->m_data;
}

void StudentList::insertEntry(Iterator &iter, Student * student){
	if(iter.m_iterator){
		Node *ptr = iter.m_iterator->m_next;
		iter.m_iterator->m_next = new Node(student);
		iter.m_iterator->m_next->m_next = ptr;
		m_size++;
	}
}