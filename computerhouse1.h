#pragma once
#include<iostream>
using namespace std;
#include"computerHouse.h"

class ComputerHouse1 :public ComputerHouse 
{
public:
	ComputerHouse1(int name, int num);

	void showComputerSpareSeat();
	

};