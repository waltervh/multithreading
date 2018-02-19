#include "threadfunctions.h"

#include <thread>

unsigned GetHardwareConcurrency()
{
    return std::thread::hardware_concurrency();
}

double SingleThreadCalculation(size_t i_thread)
{
    unsigned result = 0u;
    while(true) {
        result += i_thread + 1;
    }
    return 1.0;
}
