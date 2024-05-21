#pragma once
#include<iostream>
#include"people.h"
#include<map>
using namespace std;

class Teacher :public People {
public:
	Teacher(int num, string name, string password);
	void showOperatMenu();



};