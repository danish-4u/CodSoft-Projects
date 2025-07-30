#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_board() {
    system("clear"); // Use "cls" for Windows
    cout << "Tic Tac Toe
";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }
}

bool gameover() {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
            return true;

    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    draw = true;
    return true;
}

void player_turn() {
    cout << "Player " << turn << ", enter your choice: ";
    cin >> choice;
    row = (choice - 1) / 3;
    column = (choice - 1) % 3;
    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Try again.
";
        player_turn();
    }
}

int main() {
    while (!gameover()) {
        display_board();
        player_turn();
    }
    display_board();
    if (draw)
        cout << "It's a draw!
";
    else {
        turn = (turn == 'X') ? 'O' : 'X';
        cout << "Player " << turn << " wins!
";
    }
    return 0;
}
