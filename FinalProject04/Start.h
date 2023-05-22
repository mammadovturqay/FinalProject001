#pragma once
#pragma once
#include<iostream>
#include"function.h"
#include"auto.h"
#include"manual.h"
using namespace std;
void Start() {
	while (true)
	{
		MainMenu();
		int select = 0;
		cin >> select;
		cout << endl << endl;
		if (select == 1) {
			system("cls");
			ManualGame();
			break;
		}
		else if (select == 2) {
			system("cls");
			AutoGame();
		}
		else if (select == 3) {
			system("cls");
			AboutGame();
			system("pause");
			system("cls");
		}
		else if (select == 4) {
			system("cls");
			cout << "E X I T E D " << endl;
			break;
		}
		else {
			system("cls");
			cout << "Some error occured ! " << endl;
			system("pause");
			system("cls");
		}
	}
}
