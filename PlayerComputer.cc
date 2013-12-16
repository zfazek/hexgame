#include "PlayerComputer.h"
#include <algorithm>
#include <vector>

using namespace std;

// makes "best" computer move
int PlayerComputer::makeMove(Ui& ui, Board& b, bool firstPlayer) {
    int bestMoveIdx = -1;
    int maxWon = -1;
    int numWon;
    int temp;
    vector<int> emptyNodeIndices;
    vector<Cell> origNodes = b.getNodes();
    size_t size = b.getEmptyNodeIndices().size();
    for (size_t i = 0; i < size; ++i) {
        emptyNodeIndices = b.getEmptyNodeIndices();
        temp = emptyNodeIndices[i];
        emptyNodeIndices[i] = emptyNodeIndices[0];
        emptyNodeIndices[0] = temp;
        numWon = 0;
        for (int n = 0; n < b.getNumSamples(); ++n) {
            random_shuffle(++emptyNodeIndices.begin(), emptyNodeIndices.end());
            b.fillBoard(emptyNodeIndices, firstPlayer);
            if (firstPlayer) {
                if (! b.isSecondPlayerWon()) {
                    ++numWon;
                }
            } else {
                if (b.isSecondPlayerWon()) {
                    ++numWon;
                }
            }
            b.setNodes(origNodes);
        }
        if (numWon > maxWon) {
            maxWon = numWon;
            bestMoveIdx = emptyNodeIndices[0];
        }
    }
    return bestMoveIdx;
}

