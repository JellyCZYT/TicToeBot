// JellyCZYT Copyright 2023
// Tic Toe Bot
// GNU GPL LICENCE

#include <iostream>

// For Linux Compiling COMMENT IT IF YOU ARE USING WINDOWS!!!
#include <unistd.h>

// For Windows Compiling COMMENT IT IF YOU ARE USING LINUX!!!
#include <windows.h> 
using namespace std;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void clear() {
  system("clear");
}

void printBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

bool isMoveValid(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

bool checkWin(char player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int getBotMove(char botSymbol, char playerSymbol) {
    // check if the bot can win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = botSymbol;
                if (checkWin(botSymbol)) {
                    board[i][j] = ' ';
                    return i * 3 + j + 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    // check if the player can win
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = playerSymbol;
                if (checkWin(playerSymbol)) {
                    board[i][j] = ' ';
                    return i * 3 + j + 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    // pick a random move
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!isMoveValid(row, col));
    board[row][col] = botSymbol;
return row * 3 + col + 1;
}

int main() {
  clear();
char playerSymbol, botSymbol;
cout << "Welcome to Tic Tac Toe!" << endl;
cout << "Choose your symbol (X/O): ";
cin >> playerSymbol;
if (playerSymbol == 'X') {
botSymbol = 'O';
} else {
botSymbol = 'X';
}
cout << "You are " << playerSymbol << ". The bot is " << botSymbol << "." << endl;
cout << "Enter the number of the cell where you want to make a move." << endl;
cout << "1 | 2 | 3 " << endl;
cout << "--+---+--" << endl;
cout << "4 | 5 | 6 " << endl;
cout << "--+---+--" << endl;
cout << "7 | 8 | 9 " << endl;
int turn = 1;
while (true) {
cout << "Turn " << turn << endl;
if (turn % 2 == 1) {
// player's turn
int cell;
cout << "Your move: ";
cin >> cell;
int row = (cell - 1) / 3;
int col = (cell - 1) % 3;
if (!isMoveValid(row, col)) {
cout << "Invalid move. Try again." << endl;
continue;
}
board[row][col] = playerSymbol;
printBoard();
if (checkWin(playerSymbol)) {
cout << "You win!" << endl;
break;
}
} else {
// bot's turn
cout << "Bot's move: ";
int cell = getBotMove(botSymbol, playerSymbol);
cout << cell << endl;
int row = (cell - 1) / 3;
int col = (cell - 1) % 3;
board[row][col] = botSymbol;
printBoard();
if (checkWin(botSymbol)) {
cout << "Bot wins!" << endl;
break;
}
}
turn++;
if (turn > 9) {
cout << "Draw!" << endl;
break;
}
}
return 0;
}