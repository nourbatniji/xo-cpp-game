# XO Game (Tic-Tac-Toe) Using C++

A simple console-based XO (Tic-Tac-Toe) game built in C++.  
Two players play in the terminal: **Player 1 = X** and **Player 2 = O**.  
Players take turns entering the **row** and **column** to place their symbol.  
After each move, the board is displayed. The game ends when a player wins (row/column/diagonal) or when the board is full (draw).

---

## Features
- 2-player game in the terminal (X vs O)
- 3×3 board displayed after every move
- Win detection (row, column, diagonal)
- Draw detection when all cells are filled

---

## Functions Used
- `initializeBoard()`  
  Initializes the 3×3 game board with empty spaces.
- `displayBoard()`  
  Displays the current state of the board in the terminal.
- `checkWin(char symbol)`  
  Checks if the given player symbol has a winning condition.
- `checkDraw()`  
  Checks if the game ends in a draw (board full and no winner).

---

## Use of Arrays and Pointers
- The board is represented using a 2D character array:
  ```cpp
  char board[3][3];
