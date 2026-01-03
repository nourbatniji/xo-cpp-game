#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard();
void displayBoard();
bool checkWin(char symbol);
bool checkDraw();

int main() {
    initializeBoard();

    char player = 'X';
    int row, col;

    while (true) {
        displayBoard();

        cout << "Player " << player << ", enter row and column (1-3): ";
        cin >> row >> col;

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        if (board[row][col] != ' ') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[row][col] = player;

        if (checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char symbol) {
    char *ptr = &board[0][0];

    for (int i = 0; i < 3; i++) {
        if (ptr[i * 3] == symbol &&
            ptr[i * 3 + 1] == symbol &&
            ptr[i * 3 + 2] == symbol)
            return true;
    }

    for (int i = 0; i < 3; i++) {
        if (ptr[i] == symbol &&
            ptr[i + 3] == symbol &&
            ptr[i + 6] == symbol)
            return true;
    }

    if (ptr[0] == symbol && ptr[4] == symbol && ptr[8] == symbol)
        return true;

    if (ptr[2] == symbol && ptr[4] == symbol && ptr[6] == symbol)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
