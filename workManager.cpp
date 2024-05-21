#include<iostream>
using namespace std;
#include"workManager.h"
#include"globalFIle.h"
#include"manager.h"
#include"teacher.h"
#include"student.h"
#include"globalFIle.h"
#include<fstream>




WorkManager::WorkManager() 
{
	
	this->init_people();
	this->init_order();
	this->init_computerhouse();
}

void WorkManager::init_order()
{
	ifstream ifs;
	ifs.open(ORDERFILE, ios::in);
	int m_computerhome_num;
	string m_name;
	string m_status;
	int m_date;
	int m_time;
	while (ifs >> m_computerhome_num && ifs >> m_name && ifs >> m_date && ifs >> m_time && ifs >> m_status)
	{
		Order order(m_computerhome_num, m_name, m_status, m_date, m_time);
		this->m_order.push_back(order);
	}
	ifs.close();
}

void WorkManager::init_computerhouse()
{
	this->computerhouse1 = new ComputerHouse1(1, 20);
	this->computerhouse2 = new ComputerHouse2(2, 50);
	//this->computerhouse3 = new ComputerHouse3(3, 100);
	for (vector<Order>::iterator it = this->m_order.begin(); it != this->m_order.end(); it++)
	{
		if (it->m_computerhome_num == computerhouse1->m_computerhome_name)
		{
			computerhouse1->m_hold_num--;
		}
		else if (it->m_computerhome_num == computerhouse2->m_computerhome_name)
		{
	
			computerhouse2->m_hold_num--;
		}
	
	/*	else if (it->m_computerhome_num == computerhouse3->m_computerhome_name)
		{
			computerhouse3->m_hold_num--;
		}*/
		
	}
	this->saveComputerHouseFile();
}

void WorkManager::init_people()
{
	ifstream ifs;
	ifs.open(STDUENTFILE, ios::in);
	int num1;
	string name1;
	string password1;
	while (ifs >> num1 && ifs >> name1 && ifs >> password1)
	{
		Student student(num1, name1, password1);
		this->m_student.push_back(student);

	}
	ifs.close();


	ifs.open(TEACHERFILE, ios::in);
	int num2;
	string name2;
	string password2;
	while (ifs >> num2 && ifs >> name2 && ifs >> password2)
	{
		Teacher teacher(num2, name2, password2);
		this->m_teacher.push_back(teacher);
	
	}
	ifs.close();


	ifs.open(MANAGERFILE, ios::in);
	int num3;
	string name3;
	string password3;
	while (ifs >> num3 && ifs >> name3 && ifs >> password3)
	{
		Manager manager(num3, name3, password3);
		this->m_manager.push_back(manager);

	}
	ifs.close();

}

void  WorkManager::addPerson()
{
	system("cls");
	cout << "please choose people you want to add !" << endl;
	cout << "1. student" << endl;
	cout << "2. teacher" << endl;
	cout << "3. manager" << endl;
	int choose_num;
	string name;
	string password;
	cin >> choose_num;

	cout << "please input the name !" << endl;
	cin >> name;
	cout << "please input the password !" << endl;
	cin >> password;
	if (choose_num == 1)
	{
		int sort_num = this->m_student.size();
		Student student(sort_num, name, password);
		student.m_num = sort_num + 1;
		this->m_student.push_back(student);
		this->save_people_file(STDUENTFILE);
	}
	else if (choose_num == 2)
	{
		int sort_num = this->m_teacher.size();
		Teacher teacher(sort_num, name, password);
		teacher.m_num = sort_num + 1;
		this->m_teacher.push_back(teacher);
		this->save_people_file(TEACHERFILE);
	}
	else if (choose_num == 3)
	{
		int sort_num = this->m_manager.size();
		Manager manager(sort_num, name, password);
		manager.m_num = sort_num + 1;
		this->m_manager.push_back(manager);
		this->save_people_file(MANAGERFILE);
	}

}

void WorkManager::viewStudentAndTeacherInformation()
{
	cout << "all students : " << endl;
	for (vector<Student>::iterator it = this->m_student.begin(); it != this->m_student.end(); it++)
	{
		cout << it->m_num << "   " << it->m_name << endl;
	}
	cout << "all teachers : " << endl;
	for (vector<Teacher>::iterator it = this->m_teacher.begin(); it != this->m_teacher.end(); it++)
	{
		cout << it->m_num << "   " << it->m_name << endl;
	}
}

void  WorkManager::viewComputerhome()
{
	cout << "computerhouse1 : " << endl;
	cout << computerhouse1->m_hold_num << endl;
	cout << "computerhouse2 : " << endl;
	cout << computerhouse2->m_hold_num << endl;
}

void WorkManager::showMenu()
{

	cout << "choose the character you want to log in !" << endl;
	cout << "1.student " << endl;
	cout << "2.teacher " << endl;
	cout << "3.manager " << endl;
	cout << "4.exit " << endl;
}

bool WorkManager::verify_people(int type, string name, string password)
{

	switch (type)
	{
	case 1:
		
		for (vector<Student>::iterator it = this->m_student.begin(); it != this->m_student.end(); it++)
		{
			if (it->m_name == name && it->m_password == password)
			{
				cout << "veify successcuflly !" << endl;

				return true;
			}
		}
		
		cout << "verify failed" << endl;
		return false;
		
		break;
	case 2:
		for (vector<Teacher>::iterator it = this->m_teacher.begin(); it != this->m_teacher.end(); it++)
		{
			if (it->m_name == name && it->m_password == password)
			{
				cout << "veify successcuflly !" << endl;

				return true;
			}
		}
		cout << "verify failed" << endl;
		return false;

		break;
	case 3:
		for (vector<Manager>::iterator it = this->m_manager.begin(); it != this->m_manager.end(); it++)
		{
			if (it->m_name == name && it->m_password == password)
			{
				cout << "veify successcuflly !" << endl;

				return true;
			}
		}
		cout << "verify failed" << endl;
		return false;

		break;
	default:
		cout << "please input correct number! " << endl;
		return false;
	}
	return false;
}

void WorkManager::logIn(string filename, int people_type)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "file not found ! " << endl;
		ifs.close();
	}
	ifs.close();
	string name;
	string password;
	bool ifverify;
	bool sigh_out = false;
	switch (people_type)
	{
		case 1:
			cout << "welcome student !" << endl;
			cout << "pleasae input your name ! " << endl;
			cin >> name;
			cout << "pleasae input your password ! " << endl;
			cin >> password;

			ifverify = verify_people(people_type, name, password);

			if (ifverify)
			{
				while (!sigh_out)
				{
					sigh_out = function_student(name, password);
				}
				
			}
			break;
		case 2:
			cout << "welcome teacher !" << endl;
			cout << "pleasae input your name ! " << endl;
			cin >> name;
			cout << "pleasae input your password ! " << endl;
			cin >> password;

			ifverify = verify_people(people_type, name, password);

			if (ifverify)
			{
				while (!sigh_out)
				{
					sigh_out = function_teacher(name, password);
				}
				
			}
			break;
		case 3:
			cout << "welcome manager !" << endl;
			cout << "pleasae input your name ! " << endl;
			cin >> name;
			cout << "pleasae input your password ! " << endl;
			cin >> password;

			ifverify = verify_people(people_type, name, password);


			

			if (ifverify)
			{
				
				while (!sigh_out)
				{
					
					sigh_out = function_manager(name, password);
				}
				
			}

			break;
		default:
			cout << "don not have this type" << endl;
			break;
	}



}
bool WorkManager::function_manager(string name,string password)
{

	Manager* manager = nullptr;
	
	manager = new Manager(1, name, password);

	manager->showOperatMenu();
	int manager_menu_num;
	cin >> manager_menu_num;
	switch (manager_menu_num)
	{
	case 1:
		this->addPerson();
		break;
	case 2:
		this->viewStudentAndTeacherInformation();
		break;
	case 3:
		this->viewComputerhome();
		break;

	case 4:
		return true;
	default:
		break;
	}



	if (manager != nullptr)
	{
		manager = NULL;
		delete manager;
	}
	return false;
	
}



bool WorkManager::function_student(string name, string password)
{
	Student* student = nullptr;
	student = new Student(1,name, password);
	student->showOperatMenu();
	int choose_num;
	cin >> choose_num;
	switch (choose_num)
	{
	case 1:
		applyOrder(student);
		break;
	case 2:
		showOwnOrderInformation(student,this->m_order);
		break;
	case 3:
		showOrderInformation(this->m_order);
		break;
	case 4:
		cancelOrder(student);
		break;
	case 5:
		return true;

	default:
		break;
	}
	return false;
}

void WorkManager::applyOrder(Student* student)
{

	cout << "please choose the name of computer home !" << endl;
	cout << "1 or 2 or 3" << endl;
	int computer_house_name;
	cin >> computer_house_name;
	int date;
	cout << "please choose the date " << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	
	cin >> date;
	cout << "please choose the time " << endl;
	cout << "1. morning" << endl;
	cout << "2. afternoon" << endl;
	int time;
	cin >> time;
	Order order(computer_house_name, student->m_name, "daishenhe", date, time);
	this->m_order.push_back(order);
	this->saveOrderFile(this->m_order);
	
	switch (computer_house_name)
	{
	case 1:
		this->computerhouse1->m_hold_num--;
		break;
	case 2:
		this->computerhouse2->m_hold_num--;
		break;
	case 3:
		//this->computerhouse3->m_hold_num--;
		break;
	default:
		break;
	}
}

void WorkManager::cancelOrder(Student* student)
{
	cout << "please choose the date you want to cancel " << endl;
	this->showOwnOrderInformation(student, this->m_order);
	int data_number;
	int time_number;
	cin >> data_number;
	cout << "please choose the time you want to cancel " << endl;
	cin >> time_number;
	for (vector<Order>::iterator it = this->m_order.begin(); it != this->m_order.end(); it++)
	{
		if (it->m_date == data_number && it->m_time == time_number)
		{

			this->m_order.erase(it);
			cout << "cancel successfully ! " << endl;
			break;
		}
	}
	this->saveOrderFile(this->m_order);
}


void WorkManager::save_people_file( string filename)
{
	ofstream ofs;
	ofs.open(filename, ios::out);
	if(filename == STDUENTFILE)
	{
		for (vector<Student>::iterator it = this->m_student.begin(); it != this->m_student.end(); it++)
		{
			ofs << it->m_num << "  "
				<< it->m_name << "  "
				<< it->m_password << endl;
		}
	}
	else if (filename == TEACHERFILE)
	{
		for (vector<Teacher>::iterator it = this->m_teacher.begin(); it != this->m_teacher.end(); it++)
		{
			ofs << it->m_num << "  "
				<< it->m_name << "  "
				<< it->m_password << endl;
		}
	}
	else
	{
		cout << "save failed" << endl;
	}


	ofs.close();
}



void WorkManager::saveOrderFile(vector<Order>& v)
{
	ofstream ofs;
	ofs.open(ORDERFILE, ios::out);
	for (vector<Order>::iterator it = v.begin(); it != v.end(); it++)
	{
		ofs << it->m_computerhome_num << "  "
			<< it->m_name << "  "
			<< it->m_date << "  "
			<< it->m_time << "  "
			<< it->m_status << endl;
		
	}
	ofs.close();
	
}

void WorkManager::saveComputerHouseFile()
{
	ofstream ofs;
	ofs.open(COMPUTERFILE, ios::out);
	ofs << this->computerhouse1->m_computerhome_name << ": " << "  "
		<< this->computerhouse1->m_hold_num << " "<< endl
		<< this->computerhouse2->m_computerhome_name << ": " << "  "
		<< this->computerhouse2->m_hold_num << endl;

}


void WorkManager::showOwnOrderInformation(Student *student,vector<Order>& v)
{

	ifstream ifs;
	ifs.open(ORDERFILE, ios::in);
	for (vector<Order> ::iterator it = v.begin(); it != v.end(); it++)
	{
		if (student->m_name == it->m_name)
		{
			cout << it->m_computerhome_num << "  "
				<< it->m_name << "  "
				<< it->m_date << "  "
				<< it->m_time << "  "
				<< it->m_status << endl;
		}
	}
	system("pause");
	ifs.close();
	
}

void WorkManager::showOrderInformation(vector<Order>& v)
{

	ifstream ifs;
	ifs.open(ORDERFILE, ios::in);
	int index = 1;
	for (vector<Order> ::iterator it = v.begin(); it != v.end(); it++,index++)
	{
		cout << index << ". " << "  "
			<< it->m_computerhome_num << "  "
			<< it->m_name << "  "
			<< it->m_date << "  "
			<< it->m_time << "  "
			<< it->m_status << endl;
		
	}
	system("pause");
	ifs.close();
}

bool WorkManager::function_teacher(string name, string password)
{
	Teacher* teacher = nullptr;
	teacher = new Teacher(1, name, password);
	teacher->showOperatMenu();
	int choose_num;
	cin >> choose_num;
	switch (choose_num)
	{
	case 1:
		this->showOrderInformation(this->m_order);
		break;
	case 2:
		this->checkReserve(this->m_order);
		break;
	case 3:
		return true;

	default:
		break;
	}
	return false;
}

void WorkManager::checkReserve(vector<Order>& v)
{
	this->showOrderInformation(v);
	cout << "choose the num you want to check !" << endl;
	int num;
	cin >> num;
	int index = 1;
	for (vector<Order> ::iterator it = v.begin(); it != v.end(); it++,index++)
	{
		if (num == index)
		{
			it->m_status = "pass";
			cout << "change successfully !" << endl;
		}

	}
	this->saveOrderFile(v);
}

void WorkManager::exit()
{
	return;
}