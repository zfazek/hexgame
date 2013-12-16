#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "Ui.h"
#include "Board.h"

class ConsoleUi : public Ui {

    public:
        ConsoleUi() {
        }

        ~ConsoleUi() {
        }

        void printWelcome() const;
        void printBoard(const Board& b) const;
        void printMove(const Board& b, int idx) const;
        void gameEnd(bool firstPlayer) const;
        int makeMove(Board& b, bool firstPlayer);
        virtual bool askIfPlayerStarts();

};

#endif
