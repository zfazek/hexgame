// Game of Hex strategy board game
//
// cmake . or g++ -std=c++11 -O2 Board.cc Hexgame.cc Test.cc -o hexgame

#include <cstdlib>
#include "HexGame.h"
#include "Test.h"

using namespace std;

// Returns if game is over or not
// Checks if there is path from one side of the board to the opposite one
// Cell by cell
bool HexGame::isGameEnd() const {
    if (playerToMove == firstPlayer) {
        return b->isFirstPlayerWon();
    } else { 
        return b->isSecondPlayerWon();
    }
    return false;
}

// Main play loop
void HexGame::play() {
    int moveIdx;
    ui->printBoard(*b);
    while (true) {
        setPlayerToMove(firstPlayer);
        moveIdx = firstPlayer->makeMove(*ui, *b, true);
        if (moveIdx == -1) {
            Player* temp = secondPlayer;
            secondPlayer = firstPlayer;
            firstPlayer = temp;
        } else {
            ui->printMove(*b, moveIdx);
            b->move(moveIdx, Cell::X);
        }
        ui->printBoard(*b);
        if (isGameEnd()) {
            ui->gameEnd(true);
            break;
        }
        setPlayerToMove(secondPlayer);
        moveIdx = secondPlayer->makeMove(*ui, *b, false);
        if (moveIdx == -1) {
            Player* temp = secondPlayer;
            secondPlayer = firstPlayer;
            firstPlayer = temp;
        } else {
            ui->printMove(*b, moveIdx);
            b->move(moveIdx, Cell::O);
        }
        ui->printBoard(*b);
        if (isGameEnd()) {
            ui->gameEnd(false);
            break;
        }
    }

    // Game is over!
    exit(0);
}

// Changes the next player
void HexGame::changePlayer() {
    if (playerToMove == firstPlayer) playerToMove = secondPlayer;
    else playerToMove = firstPlayer;
}

void HexGame::setPlayerToMove(Player* p) { 
    playerToMove = p; 
}

// MAIN
int main() {

    // test first
    Test t;
    t.test();

    // init game
    HexGame hx(7);
    hx.getBoard()->setNumSamples(1000);
    hx.getUi()->printWelcome();

    // and play
    hx.play();

    return 0;
}

