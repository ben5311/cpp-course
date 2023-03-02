#include <iostream>
using namespace std;

int main() {

    const int DIM_M = 2;
    const int DIM_N = 3;
    int matrix[DIM_M][DIM_N] = {{1, 2, 3}, {4, 5, 6}};
    
    cout << sizeof(matrix) << endl;

    // matrix hat die Dimensionen DIM_M x DIM_N
    // matrix[0][0] liege an Adresse 0.
    // Dann gilt für Zeile m und Spalte n: adresse(m, n) = m*DIM_N + n

}