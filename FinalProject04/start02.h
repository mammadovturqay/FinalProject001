#pragma once
#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include"function.h"
using namespace std;

bool player1Turn = true;

void StartTheGame(int** p1, int** p2) {
	while (player1Turn)
	{
		cout << "PLAYER 1 TURN " << endl << endl;
		int row = 0, col = 0;
		cout << "Enter row which you wanna hit : "; cin >> row;
		cout << "Enter column which you wanna hit : "; cin >> col;
		while (p2[row][col] == 1)
		{
			p2[row][col] = 5;
			system("cls");
			ShowArea(p2, 10);

			player1Turn = true;
			break;
		}
		if (p2[row][col] == 0) {
			player1Turn = false;
			cout << "Missed" << endl;
			continue;
		}
	}
	while (!player1Turn)
	{
		cout << "PLAYER 2 TURN " << endl << endl;
		srand(time(0));
		int row = 1 + rand() % 10;
		int col = 1 + rand() % 10;
		while (p1[row][col] == 1)
		{
			p1[row][col] = 5;
			system("cls");
			ShowArea(p1, 10);

			player1Turn = false;
			break;
		}
		if (p1[row][col] == 0) {
			player1Turn = true;
			cout << "Missed" << endl;
			continue;
		}
	}

	if (player1Turn) {
		int row = 0, col = 0;
		while (true)
		{
			cout << "enter row which you wanna hit : "; cin >> row;
			cout << "enter column which you wanna hit : "; cin >> col;
			if (p2[row][col] == 1) {
				player1Turn = true;
				p2[row][col] = 5;
				system("cls");
				ShowArea(p1, 10);
				ShowArea(p2, 10);
				continue;
			}
			else {
				p2[row][col] = 13;
				player1Turn = false;
				cout << "Missed " << endl;
				Sleep(1000);
				break;
			}

		}
	}
	else {
		while (true)
		{
			srand(time(0));
			int row = 1 + rand() % 10;
			int col = 1 + rand() % 10;
			if (p1[row][col] == 1) {
				player1Turn = false;
				p1[row][col] = 5;
				system("cls");
				ShowArea(p1, 10);
				ShowArea(p2, 10);
				continue;
			}
			else {
				p1[row][col] = 13;
				player1Turn = true;
				cout << "Missed " << endl;
				Sleep(1000);
				break;
			}
		}


	}

	int count1 = 0; int count2 = 0;
	while (true)
	{
		if (player1Turn) {
			int row = 0; int col = 0;
			cout << "====>>P L A Y E R    1    T U R N " << endl;
			cout << "====>> enter row which you wanna hit : "; cin >> row;
			cout << "====>>> enter column which you wanna hit : "; cin >> col;
			if (p2[row][col] == 1) {
				p2[row][col] = 5;
				player1Turn = true;
				++count1;
				if (count1 == 20) {
					cout << "====>>P L A Y E R   1   W O N   T H E    G A M E   ! ! ! ! ! ! " << endl << endl;
					break;
				}
				system("cls");
				ShowArea(p1, 10);
				ShowArea(p2, 10);
				continue;
			}
			else {
				player1Turn = false;
				cout << "====================Missed=================" << endl;
				Sleep(500);
				system("cls");
				ShowArea(p1, 10);
				ShowArea(p2, 10);
				continue;
			}
		}
		else if (!player1Turn) {
			srand(time(0));
			cout << "==== P L A Y E R   2    T U T N ========" << endl;
			int row = 1 + rand() % 10;
			int col = 1 + rand() % 10;
			if (p1[row][col] == 1) {
				p1[row][col] = 5;
				cout << "====== COMPUTER HITTED YOUR SHIP ! ======= " << endl;
				Sleep(1000);
				player1Turn = false;
				++count2;
				if (count2 == 20) {
					cout << "========> P L A Y E R   2    W O N   T H E    G A M E   !  !!  ! ! " << endl << endl;
					break;
				}
				system("cls");
				ShowArea(p1, 10);
				ShowArea(p2, 10);
				continue;
			}
			else {
				player1Turn = true;
				cout << "============Missed========================" << endl;
				Sleep(500);
				system("cls");
				ShowArea(p1, 10);
				ShowArea(p2, 10);
				continue;
			}
		}
	}

}
