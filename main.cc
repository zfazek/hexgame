#include "HexGame.h"

int main(int argc, char** argv) {

    // init game
    HexGame hx(9);
    hx.getBoard()->setNumSamples(1000);
    hx.getUi()->printWelcome();

    // and play
    hx.play();

    return 0;
}


