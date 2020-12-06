#include "gtest/gtest.h"

#include "Coord_test.hpp"
#include "Board_test.hpp"
#include "PawnTests.hpp"
#include "KingTests.hpp"
#include "KnightTests.hpp"
#include "RookTests.hpp"
#include "BishopTests.hpp"
#include "QueenTests.hpp"
#include "PieceTests.hpp"
#include "Game_test.hpp"
#include "Human_test.hpp"

// keep this one included last since it pauses the test for over a
// second to see that timer is functioning properly
#include "Timer_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
