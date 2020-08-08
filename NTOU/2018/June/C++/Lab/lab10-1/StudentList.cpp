#include "StudentList.h"
#include "Student.h"


StudentList::StudentList(void)
	:m_head(0), m_tail(0)
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
}

Student* StudentList::find(char *ID){
	Node *ptr;
	for(ptr = m_head; ptr != m_tail; ptr = ptr->m_next){
		if(ptr->m_data->equal(ID))
			return ptr->m_data;
	}
	return 0;
}

bool StudentList::deleteEntry(char *id){
	Node *ptr1 = m_head;
	if(ptr1->m_data->equal(id)){//頭就是尋找的student
		if(m_head = m_tail){//頭尾相等
			delete m_head;
			m_head = m_tail = 0;
			return true;
		}
		m_head = ptr1->m_next;
		delete ptr1;
		return true;
	}

	for(; ptr1->m_next != m_tail; ptr1 = ptr1->m_next){
		if(ptr1->m_next->m_data->equal(id)){
			Node *ptr2 = ptr1->m_next;
			ptr1->m_next = ptr2->m_next;
			delete ptr2->m_data;
			return true;
		}
	}
	return false;
}