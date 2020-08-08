#ifndef Fred_H
#define Fred_H

class Fred
{
public:
	Fred();
	Fred(Fred &);
	~Fred();
	void service();
private:
	static int m_serialID;
	const int m_objectID;
};
#endif