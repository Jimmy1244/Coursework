#pragma

#include"DataGroup.h"


class ScreenDataGroup : public DataGroup
{
public:
    ScreenDataGroup(int numberOfNames, char *names[], 
                    int sizeOfArray, 
                    int numberOfData, double dataArray[])
        : DataGroup(numberOfNames, names, sizeOfArray, 
                    numberOfData, dataArray) {}
	ScreenDataGroup()
		{serialize(false);}	
private:
    void openStream(bool bOutput);
    void closeStream(bool bOutput);
    void writeByte(unsigned char data);
	unsigned char readByte();
}; 