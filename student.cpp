#include<iostream>
#include"student.h"
using namespace std;

Student::Student(int num, string name, string password)
{
	this->m_num = num;
	this->m_name = name;
	this->m_password = password;
}

void Student::showOperatMenu()
{
	cout << "1.reserve" << endl;
	cout << "2.view own information" << endl;
	cout << "3.view all information" << endl;
	cout << "4.cancel reserve" << endl;
	cout << "5.exit" << endl;

}
