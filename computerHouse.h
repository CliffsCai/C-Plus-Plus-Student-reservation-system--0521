#pragma once
#include<iostream>
using namespace std;

class ComputerHouse {
public:
	ComputerHouse();
	
	virtual void showComputerSpareSeat() = 0;

	int m_computerhome_name;
	int m_hold_num;

};