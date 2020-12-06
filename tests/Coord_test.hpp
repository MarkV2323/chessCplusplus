#include "gtest/gtest.h"

#include "../header/Coord.hpp"

TEST(CoordTest, Constructor) {
    Coord c (1, 2);
    EXPECT_EQ(c.x, 1);
    EXPECT_EQ(c.y, 2);
}

TEST(CoordTest, Equality) {
    Coord c (1, 2);
    Coord d (1, 2);
    EXPECT_TRUE(c==d);
}

TEST(CoordTest, Copy) {
    Coord c (1, 2);
    Coord d = c;
    d.x = 0;
    EXPECT_EQ(c, Coord(1,2));
    EXPECT_EQ(d, Coord(0,2));
}

TEST(CoordTest, Add) {
    Coord c (1, 2);
    Coord d (-1, 8);
    Coord e = c;
    Coord f = d;
    Coord expected (0, 10);
    c.add(d);
    e += f;
    EXPECT_EQ(c, expected);
    EXPECT_EQ(e, expected);
}

TEST(CoordTest, AddWrapped) {
    Coord c (1, 2);
    Coord d (-2, 8);
    Coord expected (7, 2);
    c.addWrapped(d);
    EXPECT_EQ(c, expected);
}

TEST(CoordTest, BinaryAdd) {
    Coord c (1, 2);
    Coord d (-1, 8);
    Coord expected (0, 10);
    EXPECT_EQ(c+d, expected);
    // ensure original objects are untouched
    EXPECT_EQ(c, Coord(1,2));
    EXPECT_EQ(d, Coord(-1,8));
}

TEST(CoordTest, isInBounds) {
    Coord c1 (0, 0);
    Coord c2 (7, 7);
    Coord c3 (1, 4);
    Coord c4 (-1, 0);
    Coord c5 (0, -1);
    Coord c6 (-1, -1);
    Coord c7 (8, 7);
    Coord c8 (7, 8);
    Coord c9 (8, 8);
    EXPECT_TRUE(c1.isInBounds());
    EXPECT_TRUE(c2.isInBounds());
    EXPECT_TRUE(c3.isInBounds());
    EXPECT_FALSE(c4.isInBounds());
    EXPECT_FALSE(c5.isInBounds());
    EXPECT_FALSE(c6.isInBounds());
    EXPECT_FALSE(c7.isInBounds());
    EXPECT_FALSE(c8.isInBounds());
    EXPECT_FALSE(c9.isInBounds());
}
