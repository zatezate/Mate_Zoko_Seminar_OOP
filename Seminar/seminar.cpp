#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
protected:
    char symbol;
public:
    Player(char s) : symbol(s) {}

    char getSymbol() const {
        return symbol;
    }

    virtual int chooseColumn() const {
        int column;
        cout << "Igraè " << symbol << ", odaberite stupac (0-6): ";
        cin >> column;
        return column;
    }
};

class HumanPlayer : public Player {
public:
    HumanPlayer(char s) : Player(s) {}
};

class Game {
private:
    vector<vector<char>> board;
    const int rows = 6, cols = 7;

    bool isValidMove(int col) const {
        return col >= 0 && col < cols && board[0][col] == ' ';
    }

    bool makeMove(int col, char symbol) {
        if (!isValidMove(col)) return false;
        for (int row = rows - 1; row >= 0; --row) {
            if (board[row][col] == ' ') {
                board[row][col] = symbol;
                return true;
            }
        }
        return false;
    }

    bool checkWin(char symbol) const {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (c + 3 < cols && board[r][c] == symbol && board[r][c + 1] == symbol && board[r][c + 2] == symbol && board[r][c + 3] == symbol) return true;
                if (r + 3 < rows && board[r][c] == symbol && board[r + 1][c] == symbol && board[r + 2][c] == symbol && board[r + 3][c] == symbol) return true;
                if (r + 3 < rows && c + 3 < cols && board[r][c] == symbol && board[r + 1][c + 1] == symbol && board[r + 2][c + 2] == symbol && board[r + 3][c + 3] == symbol) return true;
                if (r + 3 < rows && c - 3 >= 0 && board[r][c] == symbol && board[r + 1][c - 1] == symbol && board[r + 2][c - 2] == symbol && board[r + 3][c - 3] == symbol) return true;
            }
        }
        return false;
    }

    bool isFull() const {
        return all_of(board[0].begin(), board[0].end(), [](char cell) { return cell != ' '; });
    }

    void printBoard() const {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << "|" << (cell == ' ' ? '.' : cell);
            }
            cout << "|\n";
        }
        for (int c = 0; c < cols; ++c) cout << " " << c;
        cout << endl;
    }

public:
    Game() {
        board = vector<vector<char>>(rows, vector<char>(cols, ' '));
    }

    void playGame(Player& p1, Player& p2) {
        Player* players[] = { &p1, &p2 };
        int currentPlayer = 0;

        while (true) {
            printBoard();
            int col = players[currentPlayer]->chooseColumn();
            if (makeMove(col, players[currentPlayer]->getSymbol())) {
                if (checkWin(players[currentPlayer]->getSymbol())) {
                    printBoard();
                    cout << "Igraè " << players[currentPlayer]->getSymbol() << " pobjeðuje!\n";
                    break;
                }
                if (isFull()) {
                    printBoard();
                    cout << "Ploèa je puna! Neriješeno.\n";
                    break;
                }
                currentPlayer = 1 - currentPlayer;
            }
            else {
                cout << "Neispravan potez. Pokušajte ponovno.\n";
            }
        }
    }
};

int main() {
    HumanPlayer p1('X');
    HumanPlayer p2('O');
    Game game;
    game.playGame(p1, p2);

    return 0;
}
