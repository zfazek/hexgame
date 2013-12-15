#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class Cell {EMPTY, X, O};
//enum class PlayerType {HUMAN, COMPUTER};
//enum class Player {FIRST, SECOND};

// Class represents the game board
class Board {

    // size of the side of the borad
    int size;

    // number of nodes
    int numNodes;

    // cells of the board
    std::vector<Cell> nodes;

    // stores the moves in order to be able to undo moves
    std::vector<int> history;

    int numSamples;

    public:
    Board(int s);

    ~Board();

    std::vector<Cell> getNodes() const;

    int getIdx(char c, int r);

    int getSize() const { return size; }

    void setNodes(const std::vector<Cell>& n);

    // Inits the board before a game
    void initBoard();

    int getNumSamples() const { return numSamples; }

    void setNumSamples(int sample) { numSamples = sample; }

    // Makes a move on the board
    // param c x coord
    // param r y coord
    // return true if move can be moved, false otherwised
    bool move(char c, int r, Cell color);

    // Removes the last move from the board and from move history
    // return true if success, false otherwise
    bool remove();

    std::vector<int> getHistory() const { return history; }

    int getHistorySize() const;

    int getNumEmptyNodes() const;
    std::vector<int> getEmptyNodeIndices() const;

    // makes a move
    // param i x * size + y coord
    // color X or O
    // return true if move is legal, false otherwise
    bool move(int i, Cell color, bool updateHistory = true);

    bool isFirstPlayerWon() const;
    bool isSecondPlayerWon() const;
    bool isWon(const std::vector<Cell>& nodes, const Cell& cell) const;

    std::vector<Cell> rotateBoard() const;

    void fillBoard(const std::vector<int>& emptyNodeIndices, bool firstPlayer);

    private:

    // removes X and O cells from the board
    void clearNodes();

};


#endif
