#include <iostream>
#include <unordered_map>

using namespace std;

//Prints board
void printBoard(int board[9][9]) {
    std::cout << "Printing Board: \n";
    for (int i = 0; i < 9; i++ ) {
        for (int j = 0; j < 9; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//Check how many times it occurs in board
bool checkValidity(int board[9][9], int row, int col, int num) {
    unordered_map<int, int> occurencesRow;
    unordered_map<int, int> occurrencesCol;
    unordered_map<int, int> occurencesBox;

    board[row][col] = num;

    //Row 
    for (int i = 0; i < 9; i++) {
        if (occurencesRow.find(board[row][i]) != occurencesRow.end()){
            board[row][col] = 0;
            return false;
        }
        if(board[row][i] != 0)
            occurencesRow[board[row][i]] = 1;
    }
    //Col
    for (int i = 0; i < 9; i++) {
        if (occurrencesCol.find(board[i][col]) != occurrencesCol.end()) {
            board[row][col] = 0;
            return false;
        }
        if(board[i][col] != 0)
            occurrencesCol[board[i][col]] = 1;
    }
    
    //Determine quad    //Essentially normalizes values for the box check
    int horizontal, vertical;
    horizontal = (row / 3)*3;   
    vertical = (col / 3)*3;
    
    //Box
    for (int i = horizontal; i < (horizontal + 3); i++) {
        for (int j = vertical; j < vertical + 3; j++) {
            if (occurencesBox.find(board[i][j]) != occurencesBox.end()) {
                board[row][col] = 0;
                return false;
            }
            if(board[i][j] != 0)
                occurencesBox[board[i][j]] = 1;
        }
    }

    //If valid 
    return true;
}

//Recursive algorithm for solving board, uses backtracking
bool solveBoard(int board[9][9], int row, int col) {

    //End of matrix
    if (row == 8 && col == 9)
        return true;

    //End of row, move to next
    if (col == 9) {
        row ++;
        col = 0;
    }

    //If already contains a num, move next col
    if (board[row][col] > 0)
        return solveBoard(board, row, col + 1);

    //Check for each num, if it's valid
    for (int num = 1; num <= 9; num++) {
        //If valid spot, set and move to next col
        if (checkValidity(board, row, col, num)) {
            board[row][col] = num;                          //Redundent cuz function sets but I'm too lazy to change
            if (solveBoard(board, row, col + 1))        //If all 
                return true;
        }
        board[row][col] = 0;    //If not valid, set back to 0
    }
    return false;
}

int main()
{
    int board[9][9] = {
    {1,0,6,0,0,0,0,0,0},
    {0,0,0,0,0,0,3,0,0},
    {0,0,0,0,9,0,0,0,0},
    {0,0,4,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,7,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,2,0,0,0,0,0,0,0}
    };

    if (solveBoard(board, 0, 0)) 
        printBoard(board);
    else
        cout << "No solutions for board";
        
    return 0;
    
}

