#include "gtest/gtest.h"

#include "Coord_test.hpp"
#include "Board_test.hpp"
#include "PawnTests.hpp"
#include "KingTests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
