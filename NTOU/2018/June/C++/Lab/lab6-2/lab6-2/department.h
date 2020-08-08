#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class department
{
public:
	department(ifstream &infile);
	~department(void);
private:
	string m_name;
public:
	void printDepartment(void);
};