add_executable(hexgame Board.cc ConsoleUi.cc PlayerHuman.cc PlayerComputer.cc HexGame.cc Test.cc)

set (CMAKE_CXX_FLAGS "-std=c++11 -O2 -Werror -Wall")
