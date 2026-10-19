#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print a player's symbol in their color
void printPlayerSymbol(char player) {
    const char* color = (player == 'X') ? "\033[31m" : "\033[34m";
    cout << color << player << "\033[0m";
}

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<char>& board) {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int row = 0; row < 3; row++) {
        cout << " ";
        for (int column = 0; column < 3; column++) {
            char cell = board[row * 3 + column];
            if (cell == 'X' || cell == 'O') {
                printPlayerSymbol(cell);
            } else {
                cout << cell;
            }
            if (column < 2) {
                cout << " | ";
            }
        }
        cout << "\n";
        if (row < 2) {
            cout << "---|---|---\n";
        }
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWinner(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) {
            return true; // Row win
        }
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true; // Column win
        }
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true; // Diagonal win
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true; // Diagonal win
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // Board is not full
        }
    }
    return true; // All cells are filled, it's a draw
}

// Function to check if the chosen move is valid
bool isValidMove(const vector<char>& board, int move) {
    if (move < 1 || move > 9) {
        return false; // Invalid position
    }
    return board[move - 1] != 'X' && board[move - 1] != 'O'; // Check if cell is empty
}

// Function to play the game
void playGame() {
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int move;
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        cout << "Player ";
        printPlayerSymbol(currentPlayer);
        cout << ", it's your turn.\n";
        cout << "Enter a move (1-9): ";
        cin >> move;

        // Validate the move
        if (!isValidMove(board, move)) {
            cout << "Invalid move! Please try again.\n";
            continue;
        }

        // Make the move
        board[move - 1] = currentPlayer;

        // Check for winner or draw
        if (checkWinner(board, currentPlayer)) {
            printBoard(board);
            cout << "Player ";
            printPlayerSymbol(currentPlayer);
            cout << " wins!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        }

        // Switch player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Main function
int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing Tic-Tac-Toe!\n";

    return 0;
}
