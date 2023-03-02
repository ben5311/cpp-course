#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

int main() {
    mutex cout_mutex;
    condition_variable cv;

    thread t1([&cout_mutex, &cv]() {
        unique_lock<mutex> lock(cout_mutex);
        cout << "Thread t1: started. Waiting for notify..." << endl;
        cv.wait(lock);
        cout << "Thread t1: received notification." << endl;
        this_thread::sleep_for(chrono::seconds(5));     //5s, damit man die Ausgaben besser lesen kann
        cout << "Thread t1: notifying next thread..." << endl;
        cv.notify_one();
        cout << "Thread t1: finished." << endl;
    });
    thread t2([&cout_mutex, &cv]() {
        unique_lock<mutex> lock(cout_mutex);
        cout << "Thread t2: started. Waiting for notify..." << endl;
        cv.wait(lock);
        cout << "Thread t2: received notification." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Thread t2: notifying next thread..." << endl;
        cv.notify_one();
        cout << "Thread t2: finished." << endl;
    });
    thread t3([&cout_mutex, &cv]() {
        unique_lock<mutex> lock(cout_mutex);
        cout << "Thread t3: started. Waiting for notify..." << endl;
        cv.wait(lock);
        cout << "Thread t3: received notification." << endl;
        cout << "Thread t3: finished." << endl;
    });

    this_thread::sleep_for(chrono::seconds(5));
    cout << "Main thread: notifying next thread..." << endl;
    cv.notify_one();
    t1.join();
    t2.join();
    t3.join();
}