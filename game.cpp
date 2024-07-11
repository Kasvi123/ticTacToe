#include <iostream>
using namespace std;

int choice;
int row, column;
char playerTurn = 'X';
bool draw = false;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};


void printBoard() {
    cout << endl;
    cout << "TIC TAC TOE   " << endl;
    cout << "      |      |     " <<endl;
    cout << "   "<< board[0][0] << "  |   " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << " _____|______|______" << endl;
    cout << "      |      |     " << endl;
    cout << "   " << board[1][0] << "  |   " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << " _____|______|______" << endl;
    cout << "      |      |     " << endl;
    cout << "   " << board[2][0] << "  |   " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "      |      |     " << endl;
}

void playerSelectionOfMove() {
    if (playerTurn == 'X') {
        cout << "Enter number choice based on location of where you want your mark" << endl;
        cout << "Player 1 (X) turn : ";
    }
    else if (playerTurn == 'O') {
        cout << "Enter number choice based on location of where you want your mark" << endl;
        cout << "Player 2 (O) turn : ";
    }
    
    cin >> choice;
 

    if (choice == 1) {
        row = 0;
        column = 0;
    }
    else {
        if (choice == 2) {
            row = 0;
            column = 1;
        }
        else {
            if (choice == 3) {
                row = 0;
                column = 2;
            }
            else {
                if (choice == 4) {
                    row = 1;
                    column = 0;
                }
                else {
                    if (choice == 5) {
                        row = 1;
                        column = 1;
                    }
                    else {
                        if (choice == 6) {
                            row = 1;
                            column = 2;
                        }
                        else {
                            if (choice == 7) {
                                row = 2;
                                column = 0;
                            }
                            else {
                                if (choice == 8) {
                                    row = 2;
                                    column = 1;
                                }
                                else {
                                    if (choice == 9) {
                                        row = 2;
                                        column = 2;
                                    }
                                    else {
                                        if (choice > 9) {
                                            cout << "INVALID MOVE";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }



    if (playerTurn == 'X' && board[row][column] != 'O' && board[row][column] != 'X') {
        board[row][column] = 'X';
        playerTurn = 'O';
    }
    else {
        if (playerTurn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
            board[row][column] = 'O';
            playerTurn = 'X';
        }
        else {
            if (board[row][column] == 'X' || board[row][column] == 'O') {
                cout << "BOX IS FILLED";
                playerSelectionOfMove();
            }
            printBoard();
        }
    }
}
bool checkWin() {
    
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2] || board[0][0] == board[1][0] && board[0][0] == board[2][0])
        return false;
    if (board[1][0] == board[1][1] && board[1][0] == board[1][2] || board[0][1] == board[1][1] && board[0][1] == board[2][1])
        return false;
    if (board[2][0] == board[2][1] && board[2][0] == board[2][2] || board[0][2] == board[1][2] && board[0][2] == board[2][2])
        return false;
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int y = 0; y < 3; y++)
            if (board[i][y] != 'X' && board[i][y] != 'O')
                return true;
    draw = true;
    return false;
}

int main() {
    while (checkWin()) {
        printBoard();
        playerSelectionOfMove();
        checkWin();
    }

    if (playerTurn == 'X' && draw == false) {
        printBoard();
        cout << "Player 2 has won the game!!!!";
    }
    else if (playerTurn == 'O' && draw == false) {
        printBoard();
        cout << "Player 1 won the game!!!";
    }
    else
        cout << "Draw";
}

