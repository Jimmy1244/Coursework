#pragma once

class Student;

class StudentList
{
public:
    StudentList();
    ~StudentList();
    void appendEntry(Student *student);
    bool deleteEntry(char *id);
    Student *find(char *id);
private:

	class Node
    {
	friend void StudentList::appendEntry(Student *student);
	friend Student* StudentList::find(char *id);
	friend bool StudentList::deleteEntry(char *id);
	friend StudentList::~StudentList();
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
};

