#include "Wilson.h"

#include <iostream>
using namespace std;

int Wilson::m_serialID = 0;

Wilson::Wilson():m_objectID(m_serialID++)
{
    cout << "Wilson::ctor ID=" << m_objectID << endl; 
}

Wilson::~Wilson()
{
    cout << "Wilson::dtor ID=" << m_objectID << endl;
}

Wilson::Wilson(Wilson&):m_objectID(m_serialID++)
{
    cout << "Wilson::copy ctor ID=" << m_objectID << endl; 
}

void Wilson::service()
{
    cout << "Wilson::service() ID=" << m_objectID << endl; 
}