#pragma once

#include"Student.h"
class Iterator;

class StudentList
{
	class Node;
friend class Iterator;
public:
    StudentList();
    ~StudentList();
    void appendEntry(Student *student);
    bool deleteEntry(char *id);
    Student *find(char *id);
	int size();
	Student* &operator[](int slot);
	void insertEntry(Iterator &iter, Student *studnent);
private:
	class Node
    {
	friend void StudentList::appendEntry(Student *student);
	friend Student* StudentList::find(char *id);
	friend bool StudentList::deleteEntry(char *id);
	friend StudentList::~StudentList();
	friend class Iterator;
	friend Student *&StudentList::operator[](int slot);
	friend void StudentList::insertEntry(Iterator &iter, Student *student);
    public:
        Node(Student *data){
			m_next = 0;
			m_data = data;
		}
        ~Node(){
			delete m_data;
			if(m_next)
				delete m_next;
		}
    private:
        Student *m_data;
        Node *m_next;
    };

Node *m_head, *m_tail;
int m_size;
};

