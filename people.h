#pragma once
#include<iostream>
using namespace std;

class People {
public:
	People();

	virtual void showOperatMenu() = 0 ;


	int m_num;
	string m_name;
	string m_password;

};