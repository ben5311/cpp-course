#include <iostream>
#include <functional>
using namespace std;

/**
 * @brief Calculates next iteration of newton algorithm for solving function's zero points
 * 
 * @param xn the previous iteration x_n
 * @param f the function
 * @param f1 the function's first derivative
 * @return double the next iteration x_n+1
 */
double newton_solve(double xn, function<double(double)> f, function<double(double)> f1) {
    return xn - f(xn) / f1(xn);
}

int main() {

    auto newton_solve = [](double xn, function<double(double)> f, function<double(double)> f1) -> double {  //covers global function
        return xn - f(xn) / f1(xn);
    };

    // test with f(x) = x^3
    auto f = [](double x) -> double { return x*x*x; };
    auto f1 = [](double x) -> double { return 3*x*x; };
    double xn = 1;      //zero point is at x=0 so choose 1 as x0
    cout << "Calculate zero point for f(x) = x^3 with x0=" << xn << endl;
    cout << xn << endl;
    for (int i = 1; i <= 10; i++) {   //10 newton_solve iterations
        xn = newton_solve(xn, f, f1);
        cout << xn << endl;
    }
    cout << endl;

    // test with g(x) = (x-2)^2
    auto g = [](double x) -> double { return (x-2)*(x-2); };
    auto g1 = [](double x) -> double { return 2*(x-2); };
    xn = 3;     //zero point is at x=2 so choose 3 as x0
    cout << "Calculate zero point for g(x) = (x-2)^2 with x0=" << xn << endl;
    cout << xn << endl;
    for (int i = 1; i <= 10; i++) {   //10 newton_solve iterations
        xn = newton_solve(xn, g, g1);
        cout << xn << endl;
    }


}