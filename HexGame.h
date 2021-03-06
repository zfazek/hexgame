#ifndef HEXGAME_H
#define HEXGAME_H

#include "Ui.h"
#include "ConsoleUi.h"
#include "PlayerHuman.h"
#include "PlayerComputer.h"

// Hex Game class
class HexGame {

    private:

    public:

    // Constructor
    // param s size of the side of the board
    HexGame(int s);

    // Destructor
    ~HexGame();

    Player* firstPlayer;
    Player* secondPlayer;
    Player* playerToMove;
    Ui* ui;
    Board* b;

    Ui* getUi() const { return ui; };

    Board* getBoard() const { return b; }

    // Returns if game is over or not
    // Checks if there is path from one side of the board to the opposite one
    // Cell by cell
    bool isGameEnd() const;

    void printBoard() const { ui->printBoard(*b); }

    /*
    PlayerType getFirstPlayerType() const { return firstPlayerType; }

    void setFirstPlayerType(PlayerType p) { firstPlayerType = p; }

    PlayerType getSecondPlayerType() const { return secondPlayerType; }

    void setSecondPlayerType(PlayerType p) { secondPlayerType = p; }
    */

    // Main play loop
    void play();

    // Changes the nex player
    void changePlayer();

    void setPlayerToMove(Player* p);

    protected:

    // Parses and makes human move
    // It could be coordinate, undo or quit
    void makeHumanMove();

    void makeComputerMove();

};


#endif
