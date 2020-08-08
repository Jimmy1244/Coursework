#pragma once

#include"StudentList.h"
#include"Student.h"
class Node;

 class Iterator
{
friend void StudentList::insertEntry(Iterator &iter, Student *student);
public:
    Iterator(StudentList &list);
	~Iterator();
    void reset();
    void next();
    Student &operator*() const;
    Student *operator->() const;
    bool hasMoreData() const;
private:
    StudentList::Node *m_iterator;
    StudentList *m_list;
	static Student m_dummy;
};
