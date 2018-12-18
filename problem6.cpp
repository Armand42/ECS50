#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

/*
Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.        cell < 2 = DEAD
Any live cell with two or three live neighbours lives on to the next generation.                cell = 2 or 3   ALIVE
Any live cell with more than three live neighbours dies, as if by overpopulation.               cell > 3    DEAD

Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.    dead cell 3 = ALIVE
*/

void nextGen(int board[], int row, int col, int newBoard[]){
    int idx = 0, neighbor, alive;
    int size = row*col;
    while (idx < size){
        alive = 0;
        // check how many neighbors are alive
        neighbor = idx - col - 1;
        if (neighbor >= 0) alive += board[neighbor];
        neighbor++;
        if (neighbor >= 0) alive += board[neighbor];
        neighbor++;
        if (neighbor > 0 && neighbor % col != 0) alive += board[neighbor];
        
        neighbor = idx - 1;
        if (neighbor >= 0 && neighbor % col != col - 1) alive += board[neighbor];
        neighbor = idx + 1;
        if (neighbor%col != 0) alive += board[neighbor];

        neighbor = idx + col - 1;
        if (neighbor < size && neighbor%col != col - 1) alive += board[neighbor];
        neighbor++;
        if (neighbor < size) alive += board[neighbor];
        neighbor++;
        if (neighbor < size && neighbor%col != 0) alive += board[neighbor];
        
        if (alive == 3) {
            newBoard[idx] = 1;   
        } else if(alive == 2){
            newBoard[idx] = board[idx];
        } else if (board[idx] == 1) {
            newBoard[idx] = 0;
        }
        idx++;
    }
}

int main() {
    int ROW = 6;
    int COL = 7;
    int ALIVE = 1;
    int DEAD = 0;
    int size = ROW*COL;
    int board[size];
    int newBoard[size];
    
    // collecting input in array
    for (int i = 0; i < size; i++) {
        cin >> board[i];
        newBoard[i] = 0;    // initializing newBoard
    }

    cout <<  "\nInput board: " << endl;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            cout << board[i*COL + j] << " "; 
        cout << endl;
    }

    nextGen(board, ROW, COL, newBoard);

    cout <<  "\nResult board: " << endl;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            cout << newBoard[i*COL + j] << " "; 
        cout << endl;
    }   
    
/*
0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 1 0 0 0
0 1 1 1 0 0 0 
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/

    return 0;
}


