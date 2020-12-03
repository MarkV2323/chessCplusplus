#ifndef __TIMER_H__
#define __TIMER_H__

#include <ctime>

class Timer {
private:
    int startTime;
    clock_t time;
    clock_t t0;
public:
    Timer(int start_time);
    // returns time in seconds
    float getTime();
    void startTimer();
    void tick();
};

#endif //__TIMER_H__
