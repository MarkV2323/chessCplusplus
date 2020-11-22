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

#ADD_EXECUTABLE(pieceTest
#        src/main.cpp
#        src/Piece.cpp
#        )
#
#TARGET_LINK_LIBRARIES(pieceTest gtest)
#TARGET_COMPILE_DEFINITIONS(pieceTest PRIVATE gtest_disable_pthreads=ON)