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



void print(int row, int col, int size, int board[]){
     for(int i = 0; i < size; i++){
         cout << board[i] << " ";
         if (i%col == col-1) cout << endl;
     } 
}

int main() {
    int ROW = 6;
    int COL = 7;
    int size = ROW*COL;
    int ALIVE = 1;
    int DEAD = 0;

    int board[size];
    int newBoard[size];
    int numOfAliveCells = 0;
    
    // collecting input in array
    for (int i = 0; i < size; i++) {
        cin >> board[i];
        newBoard[i] = 0;    // initializing newBoard
    }

    cout <<  "\nInput board: " << endl;
    print(ROW, COL, size, board);

    int generations;
    while (true){
        cout << "How many new generations would you like to print (enter 0 to end)? " << endl;
        cin >> generations;
        if (generations == 0){
            cout << "End of program." << endl;
            break;
        }
        for(int g = 0; g < generations; g++){
            cout << "Generation: " << g << endl;
    
            for(int idx = 0; idx < size; idx++){
                int i = idx/COL;
                int j = idx%COL;
                int neighbor;
                int alive = 0;
                // check how many neighbors are alive
                if (i > 0 && j > 0){
                    neighbor = (i-1)*COL + (j-1);
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (i > 0){
                    neighbor = (i-1)*COL + j;
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (i > 0 && j < COL - 1){
                    neighbor = (i-1)*COL + (j+1);
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (i > 0 && j < COL - 1){
                    neighbor = (i)*COL + (j+1);
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (i < ROW - 1 && COL - 1){
                    neighbor = (i+1)*COL + (j+1);
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (i < ROW -1){
                    neighbor = (i+1)*COL + (j);
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (i < ROW - 1 && j > 0){
                    neighbor = (i+1)*COL + (j-1);
                    if (board[neighbor] == ALIVE) alive++;
                }
                if (j > 0){
                    neighbor = (i)*COL + (j-1);
                    if (board[neighbor] == ALIVE) alive++;
                }
            
        
                if (alive == 3) {
                    newBoard[idx] = ALIVE;
                }
                else if(alive == 2){
                    newBoard[idx] = board[idx];
                }
                else if (board[idx] == ALIVE) {
                    newBoard[idx] = DEAD;
                }

                //cout <<  "\n\nNew board: " << endl;
                //sleep(3);
                
                
            }
            sleep(3);
            //print(ROW, COL, size, newBoard); 
            for(int i = 0; i < ROW; i++){
                for(int j = 0; j < COL; j++)
                    cout << newBoard[i*COL + j] << " "; 
                cout << endl;
            }   
            for(int idx = 0; idx < size; idx++){
                board[idx] = newBoard[idx];
            }
        }
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


