// A program to test multithreading issues

#include "threadfunctions.h"
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main (int argc, char *argv[])
{
    std::cout << "MultiThreading test: "
              << "Called from: " << argv[0] << std::endl
              << "Number of arguments: " << argc << std::endl;
    std::cout << std::endl;

    const size_t n_threads = GetHardwareConcurrency();
    std::cout << "Hardware concurrency: " << n_threads << std::endl;

    std::vector<std::unique_ptr<std::thread>> threads;
    std::vector<double> results;
    results.resize(n_threads, 0.0);

    // Initialize threads
    for (size_t i_thread = 0; i_thread < n_threads; ++i_thread) {
        threads.emplace_back(new std::thread([i_thread, &results] {
            results[i_thread] = SingleThreadCalculation(i_thread);
        }));
    }

    // Wait for threads to complete
    for (auto& thread : threads)
        thread->join();

    double result = std::accumulate(results.begin(), results.end(), 0.0);
    std::cout << "Sum of individual results: " << result << std::endl;

    return 0;
}
