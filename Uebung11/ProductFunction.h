#ifndef PRODUCT_FUNCTION_H
#define PRODUCT_FUNCTION_H
#include "Function.h"
#include "SumFunction.h"
#include <ostream>

class ProductFunction : public Function {

    public:
        ProductFunction(Function* left, Function* right) : left(left), right(right) {}
        ProductFunction(const ProductFunction& other) : left(other.left), right(other.right) {}
        virtual double operator()(double x) const override {
            return (*left)(x) * (*right)(x);
        }
        virtual SumFunction* getDerivative() const override {
            return new SumFunction(new ProductFunction(left, right->getDerivative()), new ProductFunction(left->getDerivative(), right));
        }
        virtual ~ProductFunction() {
            delete left;
            delete right;
            left = nullptr;
            right = nullptr;
        }
        virtual void printTo(std::ostream& os) const override {
            left->printTo(os);
            os << "*";
            right->printTo(os);
        }

    private:
        Function* left;
        Function* right;

};

ProductFunction operator*(Function& functionA, Function& functionB) {
    return ProductFunction(&functionA, &functionB);
}


#endif