#pragma once
#pragma once
#include<iostream>
#include"function.h"
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
#include"Start02.h"
using namespace std;
const int MAX_SIZE = 10;

bool placeShip(int** game, int shipSize) {
    int rows = MAX_SIZE;
    int cols = MAX_SIZE;

    srand(time(NULL));
    int row = 1 + rand() % rows;
    int col = 1 + rand() % cols;

    if (col + shipSize > cols) {
        cout << "can not replace " << row << " and " << col << endl;
        cout << "Cannot place ship in the given gaming ground.\n";
        return false;
    }

    for (int i = 0; i <= shipSize; i++) {
        if (game[row][col + i] != 0 && game[row + 1][col + i] != 0 && game[row - 1][col + i] != 0 && game[row][col - 1] != 0 && game[row + 1][col - 1] != 0 && game[row - 1][col - 1] != 0) {
            cout << "can not replace " << row << " and " << col << endl;
            cout << "Cannot place ship in the given gaming ground.\n";
            return false;
        }
    }

    for (int i = 0; i < shipSize; i++) {
        game[row][col + i] = 1;
    }
}

void AutoGame() {
    int** game = CreateArray(15);
    int count = 0;

}
