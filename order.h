#pragma once
#include<iostream>
using namespace std;

class Order {
public:
	Order(int num, string name, string status, int date, int time);


	int m_computerhome_num;
	string m_name;
	string m_status;
	int m_date;
	int m_time;

};