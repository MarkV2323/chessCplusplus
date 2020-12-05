#include "../header/Timer.hpp"

Timer::Timer(int startTime): startTime(startTime), time(0) {}

float Timer::getTime() {
    return startTime - ((float) time/CLOCKS_PER_SEC);
}

void Timer::startTimer() {
    t0 = clock();
}

// Count up because clock_t is unsigned, counting down will most likely overflow
// before reaching 0
void Timer::tick() {
    clock_t t = clock();
    time += t - t0;
    t0 = t;
}
