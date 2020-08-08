#include <iostream>

using namespace std;

#include "Fred.h"

int Fred::m_serialID = 0;

Fred::Fred()
	:m_objectID(m_serialID++)
{
	cout << "Fred::ctor ID=" << m_objectID << endl;
}

Fred::Fred(Fred &rhs)
	:m_objectID(m_serialID++)
{
	cout << "Fred::copy ctor ID=" << m_objectID << endl;
}

Fred::~Fred(){
	cout << "Fred::dtor ID=" << m_objectID << endl;
}

void Fred::service()
{
    cout << "Fred::service() ID=" << m_objectID << endl; 
}