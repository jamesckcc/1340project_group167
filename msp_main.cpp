#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
#include "msp.h"
using namespace std;


int main() {
    int size, bombs, check;
    int sum = 0, sumf = 0;
    int** board = 0;
    string filename;
    char input = '0';
    while (input != '3') {
        switch (input) {
        case '0':
            system("clear");
            cout << " ******** Welcome to Minesweeper! ******** " << endl;
            cout << "1 New Game" << endl;
            cout << "2 Save Games" << endl;
            cout << "3 Exit" << endl;
            cout << "Your input: ";
            while (!(cin >> input)) {
                cout << endl << "Error! Please enter a number: ";
                cin.clear();
                cin.ignore(22, '\n');
            }
            break;

        case '1': {
            char diff = '0';
            system("clear");
            cout << "Select difficulty: " << endl;
            cout << "1 Beginner" << endl;
            cout << "2 Intermediate" << endl;
            cout << "3 Expert" << endl;
            cout << "4 Return to Main Menu" << endl;
            cout << "Your Input: ";
            cin >> diff;
            while (diff != '4') {
                switch (diff) {
                case '1':
                    int count;
                    size = 9;
                    bombs = 10;
                    board = new int* [size];
                    for (int i = 0; i < size; ++i) {
                        board[i] = new int[size];
                    }
                    GenerateBoard(board, size, bombs);
                    PrintBoard(board, size);
                    inputboard(board, sum, size, bombs, sumf);
                    diff = '4';
                    break;
                case '2':
                    size = 16;
                    bombs = 40;
                    board = new int* [size];
                    for (int i = 0; i < size; ++i) {
                        board[i] = new int[size];
                    }
                    GenerateBoard(board, size, bombs);
                    PrintBoard(board, size);
                    inputboard(board, sum, size, bombs, sumf);
                    diff = '4';
                    break;
                case '3':
                    size = 24;
                    bombs = 120;
                    board = new int* [size];
                    for (int i = 0; i < size; ++i) {
                        board[i] = new int[size];
                    }
                    GenerateBoard(board, size, bombs);
                    PrintBoard(board, size);
                    inputboard(board, sum, size, bombs, sumf);
                    diff = '4';
                    break;
                default:
                    system("clear");
                    cout << "Invalid Input! " << endl;
                    cout << "Select difficulty: " << endl;
                    cout << "1 Beginner" << endl;
                    cout << "2 Intermediate" << endl;
                    cout << "3 Expert" << endl;
                    cout << "Your Input: ";
                    cin >> diff;
                }
            }
            input = '0';
            break;
        }
        case '2':
            check = GetSize(size, bombs, filename);
            if (check == 0) {
                input = '0';
                break;
            }
            board = new int* [size];
            for (int i = 0; i < size; ++i) {
                board[i] = new int[size];
            }
            LoadGame(board, size, filename);
            PrintBoard(board, size);
            inputboard(board, sum, size, bombs, sumf);
            input = '0';
            break;
        case '3':
            break;
        default:
            system("clear");
            cout << "Invalid Input!" << endl;
            cout << " ******** Welcome to Minesweeper! ******** " << endl;
            cout << "1 New Game" << endl;
            cout << "2 Save Games" << endl;
            cout << "3 Exit" << endl;
            cout << "Your input: ";
            while (!(cin >> input)) {
                cout << endl << "Error! Please enter a number: ";
                cin.clear();
                cin.ignore(22, '\n');
            }
            break;
        }
    }
    delete[] board;
}
