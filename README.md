# Tic-Tac-Toe

A simple two-player Tic-Tac-Toe game for the terminal, written in C++. Players
take turns placing X and O on a numbered 3 × 3 board.

## Features

- Two-player, turn-based gameplay.
- X is displayed in red and O in blue in terminals that support ANSI colors.
- Detects wins across rows, columns, and diagonals.
- Detects a draw when the board is full.
- Prompts players to choose a numbered cell and prevents occupied or out-of-range
  moves.
- Offers another round when a game ends.

## Requirements

- A C++11-compatible compiler, such as GCC/MinGW or Microsoft Visual C++.
- A terminal that supports ANSI color escape sequences for colored markers.

## Build and run

Open a terminal in the directory containing `main.cpp`.

### Windows (PowerShell with MinGW/GCC)

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o TicTacToe.exe
.\TicTacToe.exe
```

### Linux or macOS

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o tictactoe
./tictactoe
```

## How to play

The board positions are numbered from 1 to 9:

```text
1 | 2 | 3
--|---|--
4 | 5 | 6
--|---|--
7 | 8 | 9
```

On each turn, enter the number of an available position. The first player to
place three matching symbols in a row, column, or diagonal wins. If all nine
positions are filled without a winner, the game is a draw. After a round, enter
`y` to play again or `n` to quit.
