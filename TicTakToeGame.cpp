#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;


// Enum to represent cell type
enum CellType {
    EMPTY,
    X,
    O
};

// Class to represent each cell
class Cell {
public:
    CellType cellType;
    Cell() : cellType(EMPTY) {}
};

// Class to represent a Player
class Player {
public:
    std::string name;
    CellType cellType;
    Player(const std::string& name, CellType cellType) : name(name), cellType(cellType) {}
};

// Class to represent the board
class Board {
    int size;
    vector<vector<Cell>> grid;
public:
    Board(int size) : size(size), grid(size, vector<Cell>(size)) {}

    bool isFull() const {
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell.cellType == EMPTY) return false;
            }
        }
        return true;
    }

    bool placeSymbol(int row, int col, CellType cellType) {
        if (grid[row][col].cellType == EMPTY) {
            grid[row][col].cellType = cellType;
            return true;
        }
        return false;
    }

    void print() const {
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell.cellType == X) std::cout << "X ";
                else if (cell.cellType == O) std::cout << "O ";
                else std::cout << ". ";
            }
            std::cout << std::endl;
        }
    }

    bool checkWin(int row, int col, CellType cellType) const {
        return checkRow(row, cellType) || checkCol(col, cellType) || checkDiagonals(cellType);
    }
    
private:
    bool checkRow(int row, CellType cellType) const {
        for (int j = 0; j < size; ++j)
            if (grid[row][j].cellType != cellType) return false;
        return true;
    }

    bool checkCol(int col, CellType cellType) const {
        for (int i = 0; i < size; ++i)
            if (grid[i][col].cellType != cellType) return false;
        return true;
    }

    bool checkDiagonals(CellType cellType) const {
        bool primaryDiagonal = true;
        bool secondaryDiagonal = true;

        for (int i = 0; i < size; ++i) {
            if (grid[i][i].cellType != cellType) primaryDiagonal = false;
            if (grid[i][size - i - 1].cellType != cellType) secondaryDiagonal = false;
        }

        return primaryDiagonal || secondaryDiagonal;
    }
};

// Class to manage the game
class Game {
    deque<Player> players;
    Board board;
public:
    Game(int size) : board(size) {
        players.emplace_back("Player 1", X);
        players.emplace_back("Player 2", O);
    }

    string play() {
        while (true) {
            Player currentPlayer = players.front();
            players.pop_front();
            board.print();

            if (board.isFull()) return "It's a draw";

            int row, col;
            cout << currentPlayer.name << " (" << (currentPlayer.cellType == X ? "X" : "O") << "), enter your move (row and column): ";
            cin >> row >> col;

            if (!board.placeSymbol(row, col, currentPlayer.cellType)) {
                cout << "Invalid move. Try again.\n";
                players.push_front(currentPlayer);
                continue;
            }

            if (board.checkWin(row, col, currentPlayer.cellType)) return currentPlayer.name + " wins!";

            players.push_back(currentPlayer);
        }
    }
};

int main() {
    Game game(3);
    string result = game.play();
    cout << result << endl;
    return 0;
}
