#pragma once
#include<iostream>
#include"people.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<vector>
using namespace std;

class Manager :public People {
public:
	Manager(int num, string name, string password);


	void showOperatMenu();



};