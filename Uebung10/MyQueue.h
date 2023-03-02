#ifndef MY_QUEUE_INT_CPP
#define MY_QUEUE_INT_CPP

#include <list>
#include <ostream>
#include <initializer_list>
#include <iterator>
#include <memory>

template <typename T>
class MyQueue {

    public:
        MyQueue() {}
        MyQueue(std::initializer_list<T> list) {
            for (T item : list) {
                this->push_back(item);
            }
        }
        MyQueue<T>& push_back(T item) { 
            queue.push_back(item); 
            return *this;
        }
        T pop_front() { 
            T front = queue.front();
            queue.pop_front(); 
            return front;
        }
        bool empty() const { return queue.empty(); }
        size_t size() const { return queue.size(); }

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const MyQueue<U>& queue);

        typename std::list<T>::iterator begin() { return queue.begin(); };
        typename std::list<T>::iterator end() { return queue.end(); };
        typename std::list<T>::iterator cbegin() const { return queue.cbegin(); };
        typename std::list<T>::iterator cend() const { return queue.cend(); };

    private:
        std::list<T> queue;

};

template <typename U>
std::ostream& operator<<(std::ostream& os, const MyQueue<U>& queue) {
    os << "MyQueue { ";
    size_t index = 0;
    for (U item : queue.queue) {
        os << item;
        if (index++ < queue.size()-1) { os << ", "; }
    }
    os << " }";
    return os;
}

#endif