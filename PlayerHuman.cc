#include "PlayerHuman.h"

using namespace std;

// Parses and makes human move
// It could be coordinate, undo or quit
int PlayerHuman::makeMove(Ui& ui, Board& b, bool firstPlayer) {
    return ui.makeMove(b, firstPlayer);
}
