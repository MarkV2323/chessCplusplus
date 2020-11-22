CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(finalProject)
ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(pieceMain
        src/main.cpp
        src/Piece.cpp
        src/Pawn.cpp
        src/Coord.cpp
        )

ADD_EXECUTABLE(tests
        tests/tests.cpp
        src/Piece.cpp
        src/Pawn.cpp
        src/Coord.cpp
        )

TARGET_LINK_LIBRARIES(tests gtest)
TARGET_COMPILE_DEFINITIONS(tests PRIVATE gtest_disable_pthreads=ON)