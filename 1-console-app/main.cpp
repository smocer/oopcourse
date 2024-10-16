#include <iostream>
#include "matrix.h"

int main() {
    Matrix matrix = Matrix(4, 4, 1);
    matrix.at(3, 3) = 10;
    // matrix.print();

    // matrix.add(100).print();
    // matrix.subtract(100).print();
    // matrix.multiply(100).print();

    Matrix matrix3 = Matrix(4, 4, 3);
    Matrix matrix4 = Matrix(4, 4, 4);
    // matrix3.add(matrix4).print();

    matrix3.multiply(matrix4).print();

    // Matrix matrixLarge = Matrix(6, 6, 4);
    // matrix4.add(matrixLarge);
    return 0;
}