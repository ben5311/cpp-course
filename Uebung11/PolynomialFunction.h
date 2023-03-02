#ifndef POLYNOMIAL_FUNCTION_H
#define POLYNOMIAL_FUNCTION_H
#include "Function.h"
#include "SumFunction.h"
#include "ProductFunction.h"
#include <string>
#include <cmath>
#include <ostream>
#include <stdexcept>

class PolynomialFunction : public Function {

    public:
        PolynomialFunction(double coefficient, double exponent, Function* innerFunction = nullptr) : coefficient(coefficient), exponent(exponent), innerFunction(innerFunction) {}
        PolynomialFunction(std::string s) {
            double coefficient;
            double exponent;
            size_t xIndex = s.find("x");   //find x
            if (xIndex == std::string::npos) {  //no x found, so function is constant
                coefficient = stod(s);
                exponent = 0;
            } else {   //function is polynomial
                coefficient = 1;
                exponent = 1;
                //parse coefficient
                if (xIndex >= 1) {  //there is something left to x
                    if (s[xIndex-1] == '*') {   //there is an asterisk left to x
                        size_t asterixIndex = xIndex - 1;
                        if (asterixIndex == 0) { throw std::invalid_argument("there is no coefficient left to \"*\""); }  //make sure that there is a number before asterisk
                        coefficient = stod(s.substr(0, xIndex-1)); 
                    } else {    //there is a coefficient left to x
                        coefficient = stod(s.substr(0, xIndex));
                    }
                }
                //parse exponent
                if (xIndex+2 < s.size() && s.at(xIndex+1) == '^') {
                    exponent = stod(s.substr(xIndex+2));
                }
            }
            this->coefficient = coefficient;
            this->exponent = exponent;
        }
        virtual double operator()(double x) const override {
            if (innerFunction != nullptr) {
                return coefficient * pow((*innerFunction)(x), exponent);
            } else {
                return coefficient * pow(x, exponent);
            }
        }
        virtual Function* getDerivative() const override {
            Function* derivative;
            if (exponent == 0) {
                derivative = new PolynomialFunction(0, 0, innerFunction);
            } else {
                derivative = new PolynomialFunction(exponent*coefficient, exponent-1, innerFunction);
            }
            if (innerFunction != nullptr) {
                return new ProductFunction(derivative, innerFunction->getDerivative());
            }
            return derivative;
        }
        virtual ~PolynomialFunction() { 
            delete innerFunction; 
            innerFunction = nullptr;
        }
        virtual void printTo(std::ostream& os) const override {
            if (coefficient == 0) { os << 0; } 
            else if (exponent == 0) { os << coefficient; }
            else {
                if (coefficient != 1) { os << coefficient << "*"; }
                if (innerFunction == nullptr) { os << "x";  }
                else { 
                    os << "(";
                    innerFunction->printTo(os);
                    os << ")"; 
                }
                if (exponent != 1) { os << "^" << exponent; }
            }
        }

    private:
        double coefficient;
        double exponent;
        Function* innerFunction = nullptr;

};

SumFunction operator+(PolynomialFunction& functionA, PolynomialFunction& functionB) {
    return SumFunction(&functionA, &functionB);
}

#endif