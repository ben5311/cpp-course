#ifndef FUNCTION_H
#define FUNCTION_H
#include <functional>
#include <ostream>

class Function {

    public:
        virtual double operator()(double x) const = 0;
        virtual Function* getDerivative() const = 0;
        virtual ~Function() {};
        virtual void printTo(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Function& function) {
    function.printTo(os);
    return os;
}

#endif