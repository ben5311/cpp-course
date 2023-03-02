#include <iostream>
#include <vector>
using namespace std;

class Fibonacci {

    public:
        Fibonacci() {
            cache.push_back(1);
            cache.push_back(1);
        }
        unsigned int operator()(unsigned int n) {
            if (n >= cache.size()) {  //n is not in cache
                for (unsigned int i = cache.size(); i <= n; i++) {  //calculate missing Fibonacci numbers
                    cache.push_back(cache[i-1]+cache[i-2]);
                }
            }
            return cache[n];
        }

    private:
        vector<unsigned int> cache;

};

int main() {
    Fibonacci fib;
    for (unsigned int n = 0; n < 20; n++) {
        std::cout << fib(n) << std::endl;
    }
}