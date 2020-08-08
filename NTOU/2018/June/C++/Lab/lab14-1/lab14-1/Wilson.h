#ifndef Wilson_H
#define Wilson_H

class Wilson
{
public:
    Wilson();
    Wilson(Wilson &);
    ~Wilson();
    void service();
private:
    static int m_serialID;
    const int m_objectID;
};

#endif