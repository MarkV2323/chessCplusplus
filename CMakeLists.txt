CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(finalProject)

ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(chess
    src/main.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Timer.cpp
    src/Game.cpp
    src/Draw.cpp
    src/Human.cpp
    src/Knight.cpp
    src/Rook.cpp
    src/Bishop.cpp
    src/Queen.cpp
    src/Idiot.cpp
)

TARGET_LINK_LIBRARIES(chess ncurses)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Rook.cpp
    src/Bishop.cpp
    src/Queen.cpp
    src/Timer.cpp
    src/Game.cpp
    src/Human.cpp
    src/Draw.cpp
)

ADD_EXECUTABLE(visual_test
    src/visual_tests/Board_visual_test.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Rook.cpp
    src/Bishop.cpp
    src/Queen.cpp
    src/Timer.cpp
    src/Game.cpp
    src/Human.cpp
    src/Draw.cpp
)

TARGET_LINK_LIBRARIES(visual_test ncurses)

ADD_EXECUTABLE(pawn_visual_test
    src/visual_tests/Pawn_Visual_Tester.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Rook.cpp
    src/Bishop.cpp
    src/Queen.cpp
    src/Timer.cpp
    src/Human.cpp
    src/Draw.cpp
    src/Game.cpp
)

TARGET_LINK_LIBRARIES(pawn_visual_test ncurses)

ADD_EXECUTABLE(timer_visual_test
    src/visual_tests/Timer_visual_test.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Rook.cpp
    src/Bishop.cpp
    src/Queen.cpp
    src/Timer.cpp
    src/Game.cpp
    src/Human.cpp
    src/Draw.cpp
)

TARGET_LINK_LIBRARIES(timer_visual_test ncurses)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON NO_GRAPHICS)
