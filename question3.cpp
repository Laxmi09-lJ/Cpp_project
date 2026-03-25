#include <iostream>
using namespace std;

char board[3][3];

// Initialize board
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Display board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check win
bool checkWin(char player) {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Game logic
void playGame() {
    char currentPlayer = 'X';
    int row, col;

    initializeBoard();

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << "'s turn\n";

        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;

        row--; col--;

        // Validate input
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        if (board[row][col] != ' ') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        // Update board
        board[row][col] = currentPlayer;

        // Check win
        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << " Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check draw
        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    char choice;

    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}