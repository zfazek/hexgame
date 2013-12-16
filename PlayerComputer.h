#ifndef PLAYER_COMPUTER_H
#define PLAYER_COMPUTER_H

#include "Player.h"
#include "Board.h"
#include "Ui.h"

class HexGame;

class PlayerComputer : public Player {

    public:
        ~PlayerComputer() {};
        int makeMove(Ui& ui, Board& b, bool firstPlayer);
};

#endif
