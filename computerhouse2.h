#pragma once
#include<iostream>
using namespace std;
#include"computerHouse.h"

class ComputerHouse2 :public ComputerHouse
{
public:
	ComputerHouse2(int name, int num);

	void showComputerSpareSeat();


};