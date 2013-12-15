#include <set>
#include <map>
#include <vector>
#include "Board.h"

using namespace std;

Board::Board(int s): size(s), numNodes(s * s) {
    srand(time(NULL));
    initBoard();
}

Board::~Board() {
}

std::vector<Cell> Board::getNodes() const { return nodes; }

void Board::setNodes(const vector<Cell>& n) {
    for (size_t i = 0; i < nodes.size(); ++i)
        nodes[i] = n[i];
}

// Inits the board before a game
void Board::initBoard() {
    clearNodes();
    history.clear();
}

// Removes the last move from the board and from move history
// return true if success, false otherwise
bool Board::remove() {
    if (history.empty()) return false;
    if (move(history.back(), Cell::EMPTY)) {
        history.pop_back();
        return true;
    }
    return false;
}

int Board::getHistorySize() const { return history.size(); }

int Board::getNumEmptyNodes() const {
    int n = 0;
    for (auto i : nodes)
        if (i == Cell::EMPTY) ++n;
    return n;
}

vector<int> Board::getEmptyNodeIndices() const {
    vector<int> result;
    for (int i = 0; i < numNodes; ++i) {
        if (nodes[i] == Cell::EMPTY) {
            result.push_back(i);
        }
    }
    return result;
}

int Board::getIdx(char c, int r) {
    if (c >= 'a') c -= 32;
    int column = c - 'A';
    int row = size - r;
    if (row < 0 || row >= size) return -1;
    if (column < 0 || column >= size) return -1;
    return row * size + column;
}

// Makes a move on the board
// param c x coord
// param r y coord
// return true if move can be moved, false otherwised
bool Board::move(char c, int r, Cell color) {
    int idx = getIdx(c, r);
    if (idx == -1) return false;
    return move(idx, color);
}

// makes a move
// param i x * size + y coord
// color X or O
// return true if move is legal, false otherwise
bool Board::move(int i, Cell color, bool updateHistory) {
    switch(color) {
        case Cell::EMPTY:
            if (nodes[i] == Cell::EMPTY) return false;
            nodes[i] = Cell::EMPTY;
            break;
        case Cell::X:
            if (nodes[i] != Cell::EMPTY) return false;
            nodes[i] = Cell::X;
            if (updateHistory)
                history.push_back(i);
            break;
        case Cell::O:
            if (nodes[i] != Cell::EMPTY) return false;
            nodes[i] = Cell::O;
            if (updateHistory)
                history.push_back(i);
            break;
    }
    return true;
}

// removes X and O cells from the board
void Board::clearNodes() {
    nodes.clear();
    for (int i = 0; i < size * size; i++)
        nodes.push_back(Cell::EMPTY);
}

// returns true if first player won
// false otherwise
bool Board::isFirstPlayerWon() const {
    return isWon(rotateBoard(), Cell::X);
}

bool Board::isSecondPlayerWon() const {
    return isWon(nodes, Cell::O);
}

bool Board::isWon(const vector<Cell>& nodes, const Cell& cell) const {
    vector<bool> row;
    vector<bool> newRow(size, false);
    bool rowHasColor = false;
    // fill first row
    for (auto i = 0; i < size; ++i) {
        if (nodes[i] == cell) {
            row.push_back(true);
            rowHasColor = true;
        } else {
            row.push_back(false);
        }
    }
    if (! rowHasColor)
        return false;
    for (auto i = 1; i < size; ++i) {
        rowHasColor = false;
        for (auto j = 0; j < size - 1; ++j) {
            if (nodes[i * size + j] == cell) {
                if (row[j] || row[j + 1]) {
                    newRow[j] = true;
                    rowHasColor = true;
                } else if (j > 0 && newRow[j - 1]) {
                    newRow[j] = true;
                    rowHasColor = true;
                } else {
                    newRow[j] = false;
                }
            } else {
                newRow[j] = false;
            }
        }
        if (nodes[i * size + size - 1] == cell) {
            if (row[size - 1] || newRow[size - 2]) {
                newRow[size - 1] = true;
                rowHasColor = true;
            } else {
                newRow[size - 1] = false;
            }
        } else {
            newRow[size - 1] = false;
        }
        for (auto a = 0; a < size; ++a) { row[a] = newRow[a]; }
        if (! rowHasColor)
            return false;
    }
    return true;
}

vector<Cell> Board::rotateBoard() const {
    vector<Cell> ret;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ret.push_back(nodes[j * size + i]);
    return ret;
}

// Fills the board with random moves
void Board::fillBoard(const vector<int>& emptyNodeIndices, bool firstPlayer) {
    int n = emptyNodeIndices.size();
    for (int i = 0; i < n; ++i) {
        if (firstPlayer) {
            move(emptyNodeIndices[i], Cell::X, false);
        } else {
            move(emptyNodeIndices[i], Cell::O, false);
        }
        firstPlayer = ! firstPlayer;
    }
}

