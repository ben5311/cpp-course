#ifndef SUM_FUNCTION_H
#define SUM_FUNCTION_H
#include "Function.h"
#include <ostream>

class SumFunction : public Function {

    public:
        SumFunction(Function* left, Function* right) : left(left), right(right) {}
        virtual double operator()(double x) const override {
            return (*left)(x) + (*right)(x);
        }
        virtual SumFunction* getDerivative() const override {
            return new SumFunction(left->getDerivative(), right->getDerivative());
        }
        virtual ~SumFunction() override {
            delete left;
            delete right;
            left = nullptr;
            right = nullptr;
        }
        virtual void printTo(std::ostream& os) const override {
            left->printTo(os);
            os << "+";
            right->printTo(os);
        }

    private:
        Function* left;
        Function* right;

};

SumFunction operator+(Function& functionA, Function& functionB) {
    return SumFunction(&functionA, &functionB);
}

#endif