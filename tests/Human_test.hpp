#include "gtest/gtest.h"

#include "../header/global.h"
#include "../header/Human.hpp"

TEST(HumanTest, GetTeam) {
    Human p1 (WHITE);
    Human p2 (BLACK);

    EXPECT_EQ(p1.getTeam(), WHITE);
    EXPECT_EQ(p2.getTeam(), BLACK);
}
