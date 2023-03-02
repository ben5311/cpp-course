#ifndef MY_QUEUE_INT_CPP
#define MY_QUEUE_INT_CPP

#include <list>
#include <ostream>
#include <initializer_list>
#include <iterator>

class MyQueueInt {

    public:
        MyQueueInt() {}
        MyQueueInt(std::initializer_list<int> list) {
            for (int item : list) {
                this->push_back(item);
            }
        }
        MyQueueInt& push_back(int item) { 
            queue.push_back(item); 
            return *this;
        }
        int pop_front() { 
            int front = queue.front();
            queue.pop_front(); 
            return front;
        }
        bool empty() const { return queue.empty(); }
        size_t size() const { return queue.size(); }

        friend std::ostream& operator<<(std::ostream& os, const MyQueueInt& queue);

        std::list<int>::iterator begin() { return queue.begin(); };
        std::list<int>::iterator end() { return queue.end(); };
        std::list<int>::const_iterator begin() const { return queue.cbegin(); };
        std::list<int>::const_iterator end() const { return queue.cend(); };

    private:
        std::list<int> queue;

};

std::ostream& operator<<(std::ostream& os, const MyQueueInt& queue) {
    os << "MyQueueInt { ";
    size_t index = 0;
    for (int item : queue.queue) {
        os << item;
        if (index++ < queue.size()-1) { os << ", "; }
    }
    os << " }";
    return os;
}

#endif