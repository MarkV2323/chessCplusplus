#include "gtest/gtest.h"

#include <thread>
#include <chrono>

#include "../header/Timer.hpp"

TEST(TimerTest, Timer) {
    int start = 600;
    Timer t (start);
    EXPECT_EQ(t.getTime(), start);
    t.startTimer();
    std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    EXPECT_EQ(t.getTime(), start);
    t.tick();
    EXPECT_NE(t.getTime(), start);
}
