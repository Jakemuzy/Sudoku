#pragma once
#include <iostream>
#include <unordered_map>
#include <time.h>
#include "Sudoku_Functions.h"

void printBoard(int board[9][9]);

bool checkValidity(int board[9][9], int row, int col, int num);

bool solveBoard(int board[9][9], int row, int col);

bool generateBoard(int board[9][9], int difficulty);
