#include <iostream>
#include <thread>
#include <mutex>
#include <exception>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    long long n;  //program will sum up all numbers from 1 to n
    int thread_count;   //the number of threads to use for computation
    cout << "Calculating sum of numbers in interval 1..n" << endl;
    cout << "Input n: ";
    cin >> n;
    if (n <= 0) { throw invalid_argument("n must be greater 0"); }
    cout << "Input number of threads: ";
    cin >> thread_count;
    if (thread_count <= 0) { throw invalid_argument("thread count must be greater 0"); }
    long long numbers_per_thread = n / thread_count;  //the count of numbers each thread has to compute (last thread may differ)
    chrono::steady_clock::time_point timestamp_start = chrono::steady_clock::now();

    long long sum = 0;
    mutex sum_mutex;
    auto func_calc_sum = [&sum, &sum_mutex](long long beginning, long long end) -> void {   //function that calculates sum of all numbers from beginning to end and appends it to sum variable;
        long long part_sum = 0;
        for (long long l = beginning; l <= end; l++) {
            part_sum += l;
        }
        sum_mutex.lock();
        sum += part_sum;
        sum_mutex.unlock();
    };
    vector<thread*> threads;
    for (int i = 1; i <= thread_count; i++) {   //calculate bounds for each thread and start them 
        long long beginning = (i-1)*numbers_per_thread + 1;
        long long end = (i < thread_count) ? i*numbers_per_thread : n;    //end for last thread shall be n, so that all numbers are covered 
        threads.push_back(new thread(func_calc_sum, beginning, end));
    }
    for (thread* t : threads) {
        t->join();
        delete t;
    }
    chrono::steady_clock::time_point timestamp_end = chrono::steady_clock::now();
    cout << "Result = " << sum << endl;
    cout << "Computation took " << chrono::duration_cast<chrono::milliseconds>(timestamp_end - timestamp_start).count() << "ms" << endl;
}