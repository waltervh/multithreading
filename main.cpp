// A program to test multithreading issues

#include "threadfunctions.h"
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main (int argc, char *argv[])
{
    std::cout << "MultiThreading test: "
              << "Called from: " << argv[0] << std::endl << std::endl;
    std::cout << "Usage: MultiThreading [num]" << std::endl;
    std::cout << "  num: number of threads to launch" << std::endl;
    std::cout << "       default: std::thread::hardware_concurrency()" << std::endl;
    std::cout << std::endl;

    // Get number of threads to launch
    unsigned n_threads = GetHardwareConcurrency();
    if (argc > 1) {
        n_threads = static_cast<unsigned>(std::atoi(argv[1]));
    }
    std::cout << "Number of threads that will be launched: " << n_threads << std::endl;

    // Thread and result vector
    std::vector<std::unique_ptr<std::thread>> threads;
    std::vector<double> results;
    results.resize(n_threads, 0.0);

    // Initialize threads
    for (unsigned i_thread = 0; i_thread < n_threads; ++i_thread) {
        threads.emplace_back(new std::thread([i_thread, &results] {
            results[i_thread] = SingleThreadCalculation(i_thread);
        }));
    }

    // Wait for threads to complete
    for (auto& thread : threads)
        thread->join();

    // Accumulate results from different threads
    double result = std::accumulate(results.begin(), results.end(), 0.0);
    std::cout << "Sum of individual results: " << result << std::endl;

    return 0;
}
