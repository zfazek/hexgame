#ifndef UI_H
#define UI_H

#include "Board.h"


class Ui {

    public:
        const int static UNDO = -1;
        const int static QUIT = -2;
        virtual void printWelcome() const = 0;
        virtual void printBoard(const Board& b) const = 0;
        virtual void printMove(const Board& b, int idx) const = 0;
        virtual void gameEnd(bool firstPlayer) const = 0;
        virtual int makeMove(Board& b, bool firstPlayer) = 0;
        virtual bool askIfPlayerStarts() = 0;

};

#endif

