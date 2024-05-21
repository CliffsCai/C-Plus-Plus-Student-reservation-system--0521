#pragma once
#include<iostream>
#include"people.h"
#include<map>
using namespace std;

class Student :public People {
public:
	
	Student(int num, string name, string password);

	void showOperatMenu();


};