#include "gtest/gtest.h"
#include "CoordTests.hpp"
#include "PawnTests.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}