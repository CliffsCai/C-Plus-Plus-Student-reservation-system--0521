#include<iostream>
using namespace std;
#include"workManager.h"
#include"globalFIle.h"
int main()
{
	WorkManager wm;
	while (true)
	{
		wm.showMenu();
		int num_showmenu;
		cin >> num_showmenu;
		switch (num_showmenu)
		{
		case 1:
			wm.logIn(STDUENTFILE, 1);
			break;
		case 2:
			wm.logIn(TEACHERFILE, 2);
			break;
		case 3:
			wm.logIn(MANAGERFILE, 3);
			break;
		case 4:
			wm.exit();
			break;

		default:
			break;
		}
	}
	
	
	return 0;
}