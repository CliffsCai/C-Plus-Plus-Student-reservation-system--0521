#include<iostream>
#include"teacher.h"
using namespace std;

Teacher::Teacher(int num, string name, string password)
{
	this->m_num = num;
	this->m_name = name;
	this->m_password = password;
}

void Teacher::showOperatMenu()
{
	cout << "1.view all information" << endl;
	cout << "2.check reserve" << endl;
	cout << "3.exit" << endl;

}


