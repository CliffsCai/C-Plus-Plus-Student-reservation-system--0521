#include<iostream>
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include"workManager.h"
#include<fstream>
#include"globalFIle.h"
using namespace std;

Manager::Manager(int num ,string name, string password)
{
	this->m_num = num;
	this->m_name = name;
	this->m_password = password;
}

void Manager::showOperatMenu()
{
	cout << "1.add people" << endl;
	cout << "2.view student and teacher" << endl;
	cout << "3.view computer room information" << endl;
	cout << "4.log out" << endl;
}




