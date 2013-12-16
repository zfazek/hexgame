#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Ui.h"

class Player {

    public:
        virtual ~Player() {};
        virtual int makeMove(Ui& ui, Board& b, bool firstPlayer) = 0;
};

#endif
