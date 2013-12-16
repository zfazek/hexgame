// Game of Hex strategy board game
//
// cmake . or g++ -std=c++11 -O2 Board.cc Hexgame.cc Test.cc -o hexgame

#include <cstdlib>
#include "HexGame.h"
#include "Test.h"

using namespace std;

// Constructor
// param s size of the side of the board
HexGame::HexGame(int s) {
    b = new Board(s);
    ui = new ConsoleUi();
    b->setNumSamples(1);
    firstPlayer = new PlayerHuman();
    secondPlayer = new PlayerComputer();
    playerToMove = firstPlayer;
}

// Destructor
HexGame::~HexGame() {
    delete ui;
    delete b;
    delete firstPlayer;
    delete secondPlayer;
}

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
    if (ui->askIfPlayerStarts()) {
    } else {
        Player* temp = firstPlayer;
        firstPlayer = secondPlayer;
        secondPlayer = temp;
    }
    ui->printBoard(*b);
    while (true) {
        setPlayerToMove(firstPlayer);
        moveIdx = firstPlayer->makeMove(*ui, *b, true);
        if (moveIdx == Ui::QUIT) break;
        if (moveIdx == Ui::UNDO) {
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
        if (moveIdx == Ui::QUIT) break;
        if (moveIdx == Ui::UNDO) {
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
    return;
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
    HexGame hx(3);
    hx.getBoard()->setNumSamples(100);
    hx.getUi()->printWelcome();

    // and play
    hx.play();

    return 0;
}

