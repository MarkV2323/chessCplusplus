#include "../header/Timer.hpp"

Timer::Timer(int startTime) {
    time = startTime*CLOCKS_PER_SEC;
}

float Timer::getTime() {
    return (float) time/CLOCKS_PER_SEC;
}

void Timer::startTimer() {
    t0 = clock();
}

void Timer::tick() {
    clock_t t = clock();
    time -= t - t0;
    t = t0;
}
