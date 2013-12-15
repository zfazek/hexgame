#include <iostream>
#include "ConsoleUi.h"

using namespace std;

void ConsoleUi::printWelcome() const {
    cout << "Welcome to Game of Hex strategy board game play!" << endl;
    cout << "Firt player is with 'X' and should create a path ";
    cout << "horizontally." << endl;
    cout << "Second player is with 'O' and should create a path ";
    cout << "vertically." << endl;
    cout << endl;
}

void ConsoleUi::printMove(const Board& b, int idx) const {
    cout << "Move: " << (char)('A' + idx % b.getSize()) << b.getSize() - idx / b.getSize() << endl;
}

// Prints the board by ASCII characters
void ConsoleUi::printBoard(const Board& b) const {
    vector<Cell> nodes = b.getNodes();
    int size = b.getSize();
    std::cout << "   ";

    // Prints coordinates
    for (int t = 0; t < size; t++) std::cout << char('A' + t) << "   ";
    std::cout << std::endl;

    // loop for each row
    for (int i = 0; i < size; i++) {

        // prints y row number first
        if (size - i < 10)
            std::cout << " " << size - i << " ";
        else
            std::cout << size - i << " ";

        // prints proper spaces
        for (int t = 0; t < i; t++) std::cout << "  ";

        // loop for each column
        for (int j = 0; j < size; j++) {
            switch(nodes[i * size + j]) {
                case Cell::EMPTY:
                    std::cout << '.';
                    break;
                case Cell::X:
                    std::cout << 'X';
                    break;
                case Cell::O:
                    std::cout << 'O';
                    break;
            }
            if (j != size - 1) std::cout << " - ";
        }
        std::cout << std::endl;
        std::cout << "   ";

        // prints proper spaces
        for (int t = 0; t < i * 2 + 1; t++) std::cout << " ";

        // prints edges
        if ( i < size - 1) {
            for (int j = 0; j < size; j++) {
                if (j < size - 1) std::cout << "\\ / ";
                else std::cout << "\\";
            }
        }
        std::cout << std::endl;
    }

    // prints proper spaces
    std::cout << "   ";
    for (int t = 0; t < (size - 1) * 2; t++) std::cout << " ";

    // Prints coordinates
    for (int t = 0; t < size; t++) std::cout << char('A' + t) << "   ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void ConsoleUi::gameEnd(bool firstPlayer) const {
    if (firstPlayer) {
        cout << "X won!" << endl;
    } else {
        cout << "O won!" << endl;
    }
}

// Parses and makes human move
// It could be coordinate, undo or quit
int ConsoleUi::makeMove(Board& b, bool firstPlayer) {
    string line;
    Cell c;
    bool invalid = true;
    int idx;
    while (invalid) {
        if (firstPlayer)
            cout << "First player's move? eg. a2, B3, U(ndo), Q(uit): ";
        else
            cout << "Second player's move? (eg. a2, B3, U(ndo), Q(uit): ";
        cin >> line;
        if (line == "q" || line == "Q") {
            exit(0);
        } else if (line == "u" || line == "U") {
            if (b.remove()) {
                return -1;
            } else {
            }
        } else if (line.size() == 2 || line.size() == 3) {
            if (firstPlayer) c = Cell::X;
            else c = Cell::O;

            if (line.size() == 2) {
                idx = b.getIdx(line[0], line[1] - '0');
                invalid = ! b.move(idx, c);
            }
            else if (line.size() == 3) {
                idx = b.getIdx(line[0], 10*(line[1]-'0')+line[2]-'0'); 
                invalid = ! b.move(idx, c);
            }
        }
    }
    return idx;
}
