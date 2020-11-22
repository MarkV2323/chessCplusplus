CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(chess
    src/main.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
)

TARGET_LINK_LIBRARIES(chess ncurses)

ADD_EXECUTABLE(test
    src/test.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
)

ADD_EXECUTABLE(visual_test
    src/Board_visual_test.cpp
    src/Coord.cpp
    src/Board.cpp
    src/Piece.cpp
)

TARGET_LINK_LIBRARIES(visual_test ncurses)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON NO_GRAPHICS)
