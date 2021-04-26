#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
#include "msp.h"
using namespace std;

//function for saving the game
void SaveGame(int** board, int size, int bombs) {
    ifstream fin;
    ofstream fout;
    string filename;
    int check = 0;
    cout << "Do you want to save game?" << endl;
    cout << "1 Yes" << endl;
    cout << "2 No and return to Main Menu" << endl;
    char input;
    cin >> input;
    while (input != '2') {
        switch (input) {
        case '1':

            cout << "Input new/existing file name: " << endl;
            cin >> filename;
            fin.open(filename + ".txt");
            if (fin.fail()) {
                fout.open(filename + ".txt");
                fin.close();
            }


            else {
                fout.open(filename + ".txt");
                fin.close();
                check = 1;
            }

            fout << size << " " << bombs << endl;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    fout << board[i][j] << " ";
                }
                fout << endl;
            }
            system("clear");

            if (check == 0)
                cout << "New file saved!" << endl;

            else
                cout << "File replaced!" << endl;
            //\:(;
            fout.close();
            input = '2';
            break;

        default:
            system("clear");
            cout << "Invalid Input: " << endl;
            cout << "Do you want to save game?" << endl;
            cout << "1 Yes" << endl;
            cout << "2 No and return to Main Menu" << endl;
            cout << "Your Input: ";
            cin >> input;
            break;
        }
    }
}

//function for getting the saved file for playing minesweeper
int GetSize(int& size, int& bombs, string& filename) {
    char input = '0';
    ifstream fin;
    system("clear");
    cout << "1 Load Game" << endl;
    cout << "2 Return to Main Menu" << endl;
    cout << "Your Input: ";
    cin >> input;
    while (input != '2') {
        switch (input) {
        case '1':
            system("clear");
            cout << "Enter file name: " << endl;
            cout << "Your Input: ";
            cin >> filename;
            fin.open(filename + ".txt");
            if (fin.fail()) {
                input = '0';
            }

            else {
                fin >> size >> bombs;
                input = '2';
                fin.close();
                return 1;
                break;
            }
        default:
            system("clear");
            cout << "Invalid Input: " << endl;
            cout << "1 Load Game" << endl;
            cout << "2 Return to Main Menu" << endl;
            cout << "Your Input: ";
            cin >> input;
            break;
        }
    }
    fin.close();
    return 0;
}

//function for loading the game
void LoadGame(int** board, int size, string filename) {
    ifstream fin;
    int null;
    fin.open(filename + ".txt");
    fin >> null >> null;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int num;
            fin >> num;
            board[i][j] = num;
        }
    }
    fin.close();
}

// function for printing the board 
void PrintBoard(int** board, int size) {
    system("clear");
    cout << " Input example: p 1 a \n";
    cout << "     ";
    for (int i = 0; i < size; ++i) {
        cout << char(97 + i) << " ";
    }

    cout << endl << "    ";
    for (int i = 0; i < (size * 2) + 1; ++i) {
        cout << "-";
    }

    for (int i = 0; i < size; ++i) {
        if (i > 8)
            cout << "\n" << " " << i + 1 << "|";

        else
            cout << "\n" << "  " << i + 1 << "|";

        for (int j = 0; j < size; ++j) {
            if (board[i][j] < -10) {
                cout << " F";
            }

            if (board[i][j] > -10 and board[i][j] < 10) {
                cout << " *";
            }

            else if (board[i][j] > 9)
                cout << " " << board[i][j] - 10;

            else if (board[i][j] == -10)
                cout << " *";
        }
        cout << " |" << i + 1;
    }

    cout << endl << "    ";
    for (int i = 0; i < (size * 2) + 1; ++i) {
        cout << "-";
    }

    cout << endl << "     ";
    for (int i = 0; i < size; ++i) {
        cout << char(97 + i) << " ";
    }
    cout << endl;
}

//fucntion for generate the board
void GenerateBoard(int** board, int size, int bombs) {
    int* arr = new int[bombs];
    int count = 0;
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i][j] = 0;
        }
    }


    while (count != bombs) {
        int num = rand() % (size * size);
        int check = 0;
        for (int i = 0; i < bombs; ++i) {
            if (num == arr[i]) {
                check += 1;
            }
        }
        if (check == 0) {
            arr[count] = num;
            count++;
        }
    }


    for (int i = 0; i < bombs; ++i) {
        board[arr[i] / size][arr[i] % size] = -10;
    }



    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == 0) {
                int n = 0;
                if (i + 1 < size) {
                    if (board[i + 1][j] == -10) n++;
                    if (j + 1 < size) {
                        if (board[i + 1][j + 1] == -10) n++;
                    }
                    if (j - 1 >= 0) {
                        if (board[i + 1][j - 1] == -10) n++;
                    }
                }
                if (i - 1 >= 0) {
                    if (board[i - 1][j] == -10) n++;
                    if (j + 1 < size) {
                        if (board[i - 1][j + 1] == -10) n++;
                    }
                    if (j - 1 >= 0) {
                        if (board[i - 1][j - 1] == -10) n++;
                    }
                }
                if (j + 1 < size) {
                    if (board[i][j + 1] == -10) n++;
                }
                if (j - 1 >= 0) {
                    if (board[i][j - 1] == -10) n++;
                }
                board[i][j] = n;
            }
        }
    }
    delete[] arr;
}

// the recursion function use in run board for checking for the 0 value next the 0 value grid
void runboard2(int** board, int size, int x, int y, int& sum) {
    board[x][y] += 10;
    sum += 1;
    
    
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < size && j >= 0 && j < size) {
                if (board[i][j] < 9 && board[i][j] >= 0) {
                    if (board[i][j] == 0) {
                        runboard2(board, size, i, j, sum);
                    }

                    else {
                        board[i][j] += 10;
                        sum += 1;
                    }
                }

                else if (board[i][j] < -10 && board[i][j] >= -100) {
                    if (board[i][j] == -100) {
                        board[i][j] = 0;
                        runboard2(board, size, i, j, sum);
                    }

                    else {
                        board[i][j] += 110;
                        sum += 1;
                    }
                }
            }
        }
    }
}

//checking for the 0 vaule next to the selected grid
void runboard(int** board, int size, int x, int y, int& sum) {
    board[x][y] += 10;
    sum += 1;
    
    //for checking the adjacent grid to the selected grid is 0 or not and open it
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < size && j >= 0 && j < size) {
                //check for the grid is opened or not and is a bomb or not
                if (board[i][j] < 9 && board[i][j] >= 0) {
                    if (board[i][j] == 0) {
                        runboard2(board, size, i, j, sum);
                    }
                }

                else if (board[i][j] < -10 && board[i][j] >= -100) {
                    if (board[i][j] == -100) {
                        board[i][j] = 0;
                        runboard2(board, size, i, j, sum);
                    }
                }
            }
        }
    }
}

// input function for running the minesweeper
void inputboard(int** board, int& sum, int size, int bombs, int& sumf) {
    int x, y;
    int countf = 0;
    // looping for running the minesweeper
    while ((sum != size * size - bombs) && (sumf != bombs)) {
        char a, b;
        cout << "Number of Flags left: " << bombs - sumf << endl;
        cout << "please input : ";
        cin >> b;

        // selection for play and input x,y coordinate for grid
        if (b == 'p') {
            cin >> x >> a;
            x -= 1;
            y = (a - 97);

            // check for input validation
            //run the board and open the grid if the input is valid
            //output "invalid input" if the input is invalid
            if (x < size && x >= 0 && y < size && y >= 0) {
                if (board[x][y] < 10 && board[x][y] >= 0) {
                    runboard(board, size, x, y, sum);
                    PrintBoard(board, size);
                }

                //check whether the selection is the bomb or not
                else if (board[x][y] == -10) {
                    sum = 0;
                    sumf = 0;
                    cout << "GAMEOVER! You stepped on a bomb" << endl;
                    break;
                }

                else {
                    cout << "invalid input!" << endl;
                    cin.clear();
                }

            }
            else {
                cout << "invalid input!" << endl;
                cin.clear();
            }
        }


        // s -> saving mode
        else if (b == 's') {
            SaveGame(board, size, bombs);
            return;
            break;
        }

        // f-> flag the selected minesweeper grid 
        else if (b == 'f') {
            cin >> x >> a;
            x -= 1;
            y = (a - 97);
            
            // check for input validation
            if (x < size && x >= 0 && y < size && y >= 0 && countf != bombs) {
                if (board[x][y] < 9) {
                    if (board[x][y] < -10) {
                        board[x][y] += 100;
                        countf -= 1;
                        if (board[x][y] == -10)
                            sumf -= 1;
                    }


                    else {
                        board[x][y] -= 100;
                        countf += 1;
                        if (board[x][y] == -110)
                            sumf += 1;
                    }
                    PrintBoard(board, size);
                }


                else {
                    cout << "invalid input!" << endl;
                    cin.clear();
                }
            }


            else {
                cout << "invalid input!" << endl;
                cin.clear();
            }
        }
        else if (b != 'f' || b != 's' || b != 'p') {
            cout << "invalid input!" << endl;
            cin.clear();
        }
        cin.ignore(1024, '\n');
        cin.clear();
    }
    //when the game is over, reset the sum of grid that is opened and the sum of flag into 0
    sum = 0;
    sumf = 0;
}
