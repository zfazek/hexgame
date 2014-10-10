#include <cassert>
#include <iostream>
#include "Test.h"
#include "HexGame.h"
#include <map>

using namespace std;

// unit tests
void Test::test() {
    {
        Board b(3);
        assert(true == b.move('b', 2, Cell::X));
        assert(true == b.move('B', 2, Cell::EMPTY));
        assert(true == b.move('B', 2, Cell::X));
        assert(true == b.move('A', 2, Cell::O));
        assert(true == b.move('a', 1, Cell::X));
        assert(false == b.move('A', 1, Cell::X));
        assert(false == b.move('A', 1, Cell::O));
        assert(false == b.move('C', 3, Cell::EMPTY));
        assert(false == b.move('a', 1, Cell::X));
        assert(false == b.move('A', 0, Cell::X));
        assert(false == b.move('D', 1, Cell::X));
        assert(true == b.remove());
        assert(true == b.remove());
        assert(true == b.remove());
        assert(false == b.remove());
    }

    {
        HexGame hx(7);
        assert(true == hx.getBoard()->move('A', 1, Cell::X));
        assert(true == hx.getBoard()->remove());
        assert(false == hx.getBoard()->remove());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('A', 1, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('A', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 1, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('c', 1, Cell::X));
        assert(true == hx.isGameEnd());
        assert(true == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('A', 1, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('A', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 1, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('c', 2, Cell::X));
        assert(true == hx.isGameEnd());
        assert(true == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('c', 1, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('A', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('c', 2, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('c', 3, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('c', 1, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 3, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('c', 2, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 2, Cell::O));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('a', 3, Cell::X));
        assert(false == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(false == hx.getBoard()->isSecondPlayerWon());
        hx.changePlayer();
        assert(true == hx.getBoard()->move('b', 1, Cell::O));
        assert(true == hx.isGameEnd());
        assert(false == hx.getBoard()->isFirstPlayerWon());
        assert(true == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('a', 3, Cell::O));
        assert(false == hx.getBoard()->isSecondPlayerWon());
        assert(true == hx.getBoard()->move('a', 1, Cell::O));
        assert(false == hx.getBoard()->isSecondPlayerWon());
        assert(true == hx.getBoard()->move('a', 2, Cell::O));
        assert(true == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('c', 3, Cell::O));
        assert(false == hx.getBoard()->isSecondPlayerWon());
        assert(true == hx.getBoard()->move('c', 1, Cell::O));
        assert(false == hx.getBoard()->isSecondPlayerWon());
        assert(true == hx.getBoard()->move('c', 2, Cell::O));
        assert(true == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(true == hx.getBoard()->move('c', 3, Cell::O));
        assert(false == hx.getBoard()->isSecondPlayerWon());
        assert(true == hx.getBoard()->move('a', 1, Cell::O));
        assert(false == hx.getBoard()->isSecondPlayerWon());
        assert(true == hx.getBoard()->move('b', 2, Cell::O));
        assert(true == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::O, Cell::X, Cell::O,
            Cell::O, Cell::X, Cell::X,
            Cell::X, Cell::X, Cell::O
        };
        hx.getBoard()->setNodes(nodes);
        assert(false == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::X, Cell::O, Cell::X,
            Cell::X, Cell::O, Cell::O,
            Cell::X, Cell::X, Cell::O
        };
        hx.getBoard()->setNodes(nodes);
        assert(true == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::O, Cell::X, Cell::X,
            Cell::O, Cell::O, Cell::X,
            Cell::X, Cell::O, Cell::X
        };
        hx.getBoard()->setNodes(nodes);
        assert(true == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::O, Cell::X, Cell::X,
            Cell::O, Cell::X, Cell::X,
            Cell::X, Cell::O, Cell::O
        };
        hx.getBoard()->setNodes(nodes);
        assert(false == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::X, Cell::X, Cell::X,
            Cell::O, Cell::X, Cell::X,
            Cell::O, Cell::O, Cell::O
        };
        hx.getBoard()->setNodes(nodes);
        assert(false == hx.getBoard()->isSecondPlayerWon());
    }

    {
        HexGame hx(3);
        assert(9 == hx.getBoard()->getNumEmptyNodes());
        hx.getBoard()->fillBoard(hx.getBoard()->getEmptyNodeIndices(), true);
        assert(0 == hx.getBoard()->getNumEmptyNodes());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::EMPTY, Cell::EMPTY, Cell::O,
            Cell::X, Cell::O, Cell::X,
            Cell::O, Cell::EMPTY, Cell::X
        };
        hx.getBoard()->setNodes(nodes);
        assert(Cell::EMPTY == hx.getBoard()->getNodes()[0]);
        assert(Cell::EMPTY == hx.getBoard()->getNodes()[1]);
        assert(Cell::O == hx.getBoard()->getNodes()[2]);
        assert(Cell::X == hx.getBoard()->getNodes()[3]);
        assert(Cell::O == hx.getBoard()->getNodes()[4]);
        assert(Cell::X == hx.getBoard()->getNodes()[5]);
        assert(Cell::O == hx.getBoard()->getNodes()[6]);
        assert(Cell::EMPTY == hx.getBoard()->getNodes()[7]);
        assert(Cell::X == hx.getBoard()->getNodes()[8]);
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::O, Cell::X, Cell::O,
            Cell::EMPTY, Cell::X, Cell::O,
            Cell::X, Cell::EMPTY, Cell::EMPTY
        };
        hx.getBoard()->setNodes(nodes);
        assert(false == hx.isGameEnd());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::O, Cell::X, Cell::O,
            Cell::X, Cell::O, Cell::EMPTY,
            Cell::X, Cell::EMPTY, Cell::EMPTY
        };
        hx.getBoard()->setNodes(nodes);
        hx.setPlayerToMove(hx.secondPlayer);
        assert(false == hx.isGameEnd());
    }

    {
        HexGame hx(3);
        vector<Cell> nodes = {
            Cell::O, Cell::X, Cell::O,
            Cell::EMPTY, Cell::X, Cell::O,
            Cell::X, Cell::EMPTY, Cell::EMPTY
        };
        hx.getBoard()->setNodes(nodes);
        vector<int> empty = hx.getBoard()->getEmptyNodeIndices();
        assert(3 == empty.size());
        assert(3 == empty[0]);
        assert(7 == empty[1]);
        assert(8 == empty[2]);
    }

    {
        Board b(3);
        b.initBoard();
        vector<Cell> nodes = {
            Cell::X, Cell::X, Cell::X,
            Cell::EMPTY, Cell::EMPTY, Cell::EMPTY,
            Cell::O, Cell::O, Cell::O
        };
        b.setNodes(nodes);
        vector<Cell> r = b.rotateBoard();
        assert(Cell::X == r[0]);
        assert(Cell::EMPTY == r[1]);
        assert(Cell::O == r[2]);
        assert(Cell::X == r[3]);
        assert(Cell::EMPTY == r[4]);
        assert(Cell::O == r[5]);
        assert(Cell::X == r[6]);
        assert(Cell::EMPTY == r[7]);
        assert(Cell::O == r[8]);
    }

    /*
     * Add bad move test
     * The good move (4) likelihood is about 50% with pure Monte Carlo
     * It should be almost 100% with MCTS. Let's see!
     */
    {
        HexGame hx(5);
        hx.getBoard()->setNumSamples(1000);
        Board b(5);
        b.initBoard();
        vector<Cell> nodes = {
            Cell::X, Cell::EMPTY, Cell::X, Cell::X, Cell::EMPTY,
            Cell::X, Cell::X, Cell::O, Cell::EMPTY, Cell::EMPTY,
            Cell::O, Cell::O, Cell::O, Cell::X, Cell::O,
            Cell::O, Cell::X, Cell::X, Cell::O, Cell::EMPTY,
            Cell::O, Cell::X, Cell::O, Cell::EMPTY, Cell::EMPTY
        };
        hx.getBoard()->setNodes(nodes);
        hx.setPlayerToMove(hx.secondPlayer);
        map<int, int> stat;
        int N = 1000;
        for (int i = 0; i < N; i++) {
            int moveIdx = hx.playerToMove->makeMove(*hx.ui, *hx.b, false);
            stat[moveIdx]++;
        }
        /*
        hx.ui->printBoard(*hx.b);
        for (const auto& s : stat) {
            printf("%2d: %3d\n", s.first, s.second);
        }
        printf("move 4: %.0f%%\n", 100 * (double)stat[4] / N);
        */
        assert(100 * (double)stat[4] / N > 40);
    }

    cout << endl;
}
