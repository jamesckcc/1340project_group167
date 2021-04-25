#ifndef MSP_H
#define MSP_H

#include <string>
using namespace std;

void SaveGame(int** board, int size, int bombs);

int GetSize(int& size, int& bombs, string& filename);

void LoadGame(int** board, int size, string filename);

void PrintBoard(int** board, int size);

void GenerateBoard(int** board, int size, int bombs);

void runboard2(int** board, int size, int x, int y, int& sum);

void runboard(int** board, int size, int x, int y, int& sum);

void inputboard(int** board, int& sum, int size, int bombs, int& sumf);

#endif
