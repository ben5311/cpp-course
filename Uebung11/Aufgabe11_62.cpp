#include <iostream>
#include <functional>
#include "PolynomialFunction.h"
#include "Function.h"
#include <vector>
using namespace std;

vector<Function*> functions;

/**
 * @brief Calculates next iteration of newton algorithm for solving function's zero points
 * 
 * @param xn the previous iteration x_n
 * @param f the function
 * @param f1 the function's first derivative
 * @return double the next iteration x_n+1
 */
double newton_solve(double xn, Function& f) {
    Function* f1 = f.getDerivative();
    double result = xn - f(xn) / (*f1)(xn);
    functions.push_back(f1);
    return result;
}

int main() {

    // test with f(x) = x^3
    PolynomialFunction f = PolynomialFunction("x^3");
    double xn = 1;      //zero point is at x=0 so choose 1 as x0
    cout << "Calculate zero point for f(x) = " << f << " with x0=" << xn << endl;
    cout << xn << endl;
    for (int i = 1; i <= 10; i++) {   //10 newton_solve iterations
        xn = newton_solve(xn, f);
        cout << xn << endl;
    }
    cout << endl;
 
    // test with g(x) = (x-2)^2
    PolynomialFunction g = PolynomialFunction(1, 2, new SumFunction(new PolynomialFunction("x"), new PolynomialFunction("-2")));
    xn = 3;     //zero point is at x=2 so choose 3 as x0
    cout << "Calculate zero point for g(x) = " << g << " with x0=" << xn << endl;
    cout << xn << endl;
    for (int i = 1; i <= 10; i++) {   //10 newton_solve iterations
        xn = newton_solve(xn, g);
        cout << xn << endl;
    } 

    for (Function* f : functions) {
        delete f;
    }

}