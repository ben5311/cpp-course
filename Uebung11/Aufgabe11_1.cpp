#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

int main() {
    mutex cout_mutex;
    thread t1([&cout_mutex]() -> void {
        cout_mutex.lock();
        cout << "Thread t1 startet" << endl;
        cout << "Thread t1 geht schlafen" << endl;
        cout_mutex.unlock();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Thread t1 beendet sich" << endl;
    });
    thread t2([&cout_mutex]() -> void {
        cout_mutex.lock();
        cout << "Thread t2 startet" << endl;
        cout << "Thread t2 geht schlafen" << endl;
        cout_mutex.unlock();
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Thread t2 beendet sich" << endl;
    });
    thread t3([&cout_mutex]() -> void {
        cout_mutex.lock();
        cout << "Thread t3 startet" << endl;
        cout << "Thread t3 geht schlafen" << endl;
        cout_mutex.unlock();
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Thread t3 beendet sich" << endl;
    });
    t1.join();
    t2.join();
    t3.join();
}