#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"people.h"
#include"order.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"computerhouse1.h"
#include"computerhouse2.h"
#include"computerhouse3.h"
#include"computerHouse.h"
class WorkManager
{
public:
	WorkManager();

	vector<Student> m_student;
	vector<Teacher> m_teacher;
	vector<Manager> m_manager;

	void init_computerhouse();
	void init_people();
	void init_order();


	void showMenu();
	void viewComputerhome();

	void save_people_file(string filename);
	void viewStudentAndTeacherInformation();
	void addPerson();
	bool verify_people(int type, string name, string password);
	void logIn(string filename, int people);

	bool function_student(string name, string password);

	bool function_teacher(string name, string password);

	bool function_manager(string name, string password);

	void applyOrder(Student* student);
	void cancelOrder(Student* student);
	vector<Order> m_order;
	ComputerHouse* computerhouse1 = nullptr;
	ComputerHouse* computerhouse2 = nullptr;
	//ComputerHouse* computerhouse3 =nullptr;
	void showOwnOrderInformation(Student* student, vector<Order>& v);
	void showOrderInformation(vector<Order>& v);

	void checkReserve(vector<Order>& v);



	void exit();
	void saveOrderFile(vector<Order>& v);
	void saveComputerHouseFile();
};