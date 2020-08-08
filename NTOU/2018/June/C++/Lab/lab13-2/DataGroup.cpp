#include "DataGroup.h"

#include <iostream>


DataGroup::DataGroup(int numberOfNames, char *names[], 
                        int sizeOfArray, 
                        int numberOfData, double dataArray[])
    : m_numberOfNames(numberOfNames), 
        m_dataArraySize(sizeOfArray), 
        m_numberOfData(numberOfData)
{
    int i, len;
    m_names = new char*[numberOfNames];
    for (i=0; i<numberOfNames; i++)
    {
        len = strlen(names[i]);
        m_names[i] = new char[len+1];
        strcpy(m_names[i], names[i]);
    }
    m_dataArray = new double[m_dataArraySize];
    for (i=0; i<numberOfData; i++)
        m_dataArray[i] = dataArray[i];
}

DataGroup::DataGroup()
	:m_names(0), m_numberOfNames(0), m_dataArray(0), m_dataArraySize(0), m_numberOfData(0)
{
}
    
DataGroup::~DataGroup()
{
    freeMemory();
}

void DataGroup::serialize(bool bOutput)
{
    int i, j, len;
    unsigned char *ptr;

    openStream(bOutput);
    if (bOutput) // output
    {
        ptr = (unsigned char *) &m_numberOfNames;
        for (i=0; i<sizeof(int); i++)
            writeByte(ptr[i]);
        
        for (i=0; i<m_numberOfNames; i++)
        {
            len = strlen(m_names[i]);
            ptr = (unsigned char *) &len;
            for (j=0; j<sizeof(int); j++)
                writeByte(ptr[j]);
            for (j=0; j<len; j++)
                writeByte(m_names[i][j]);
        }
        
        ptr = (unsigned char *) &m_numberOfData;
        for (i=0; i<sizeof(int); i++)
            writeByte(ptr[i]);
        
        ptr = (unsigned char *) &m_dataArraySize;
        for (i=0; i<sizeof(int); i++)
            writeByte(ptr[i]);
        
        for (i=0; i<m_numberOfData; i++)
        {
            ptr = (unsigned char *) &m_dataArray[i];
            for (j=0; j<sizeof(double); j++)
                writeByte(ptr[j]);
        }
    }
    else // input
    {
		if(m_numberOfNames)
			freeMemory();
        ptr = (unsigned char *) &m_numberOfNames;
        for (i=0; i<sizeof(int); i++)
            ptr[i] = readByte();
        m_names = new char*[m_numberOfNames];
        for (i=0; i<m_numberOfNames; i++)
        {
            ptr = (unsigned char *) &len;
            for (j=0; j<sizeof(int); j++)
                ptr[j] = readByte();			
            m_names[i] = new char[len+1];
            for (j=0; j<len; j++)
                m_names[i][j] = readByte();
            m_names[i][len] = 0;
        }

		ptr = (unsigned char *) &m_numberOfData;
        for (i=0; i<sizeof(int); i++)
            ptr[i] = readByte();
        ptr = (unsigned char *) &m_dataArraySize;
        for (i=0; i<sizeof(int); i++)
            ptr[i] = readByte();
        m_dataArray = new double[m_dataArraySize];
        for (i=0; i<m_numberOfData; i++)
        {
            ptr = (unsigned char *) &m_dataArray[i];
            for (j=0; j<sizeof(double); j++)
                ptr[i] = readByte();
        }
    }
    
    closeStream(bOutput);
}

void DataGroup::freeMemory(){
	int i;
    for (i=0; i<m_numberOfNames; i++)
        delete[] m_names[i];
    delete[] m_names;
    delete[] m_dataArray;
}