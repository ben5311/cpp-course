// Prüfung C++, Winter 2020/21, Bialonski/Terstegge/Voss

#ifndef A2_TICKER_H
#define A2_TICKER_H

#include <cassert>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
#include <random>
#include <cassert>

using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::chrono::milliseconds;
using std::thread;
using std::this_thread::sleep_for;
using std::function;


//!!! A2.(a) Zufallszahlen mit random_range()

// Beispiele:
//   2..5,100 -> 2.00..5.00
//  -1..1,10  -> -1.0..1.0
// Hinweis: Die Funktion random_range muss beide Ränder einschließen!

static std::mt19937& getGen() {
    static std::random_device rd;  //Will be used to obtain a seed for the random number engine
    static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    return gen;
}

double random_range(int min, int max, int fraction10) {
    // rand() liefert einen Interger-Wert von 0 bis RAND_MAX
    std::uniform_int_distribution<> distrib(min*fraction10, max*fraction10);
    int value = distrib(getGen());
    double random_value = value / double(fraction10);
    return random_value;
}


class Ticker {
    //!!! A2.(b) Attribute

    public:
        //!!! A2.(b) Konstruktor
        Ticker(): is_running_(false), interval_(0) {}
        //!!! A2.(c) Method attach zum Setzten von Funktion und Intervall
        void attach(std::function<void()> func, unsigned long long interval_ms=1000) {
            interval_ = interval_ms;
            func_ = func;
        }
        //!!! A2.(d) Destruktor
        virtual ~Ticker() {
            stop(false);
        }
        //!!! A2.(e) running
        bool running() const { return is_running_; }
        //!!! A2.(f) thread starten
        void start() {
            if(!is_running_) {
                is_running_ = true;
                auto callFunction = [this]() {
                    while (this->is_running_) {
                        this->func_();
                        sleep_for(milliseconds(this->interval_));
                    }  
                };
                thread_ = new thread(callFunction);
            }
        }
        //!!! A2.(g) thread stoppen
        void stop(bool wait=true) {
            is_running_ = false;
            if (wait) { 
                thread_->join();
                delete thread_;
             }
        }

    private:
        bool is_running_;
        unsigned long long interval_;
        std::function<void()> func_;
        std::thread* thread_ = nullptr;
};

#endif
