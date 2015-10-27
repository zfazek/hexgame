project(hexgame)

cmake_minimum_required(VERSION 3.4)

set (CMAKE_CXX_FLAGS "-std=c++11 -O2 -Werror -Wall")

add_executable(hexgame
    main.cc
    Board.cc
    ConsoleUi.cc
    PlayerHuman.cc
    PlayerComputer.cc
    HexGame.cc
    )
add_executable(test_hexgame
    Board.cc
    ConsoleUi.cc
    PlayerHuman.cc
    PlayerComputer.cc
    HexGame.cc
    Test.cc
    )

enable_testing()
add_test(test_hexgame test_hexgame)

