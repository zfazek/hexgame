#ifndef PLAYER_HUMAN_H
#define PLAYER_HUMAN_H

#include "Player.h"
#include "Board.h"
#include "Ui.h"


class PlayerHuman : public Player {

    public:
    int makeMove(Ui& ui, Board& b, bool firstPlayer);
};

#endif
