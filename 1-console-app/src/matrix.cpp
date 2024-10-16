#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>

Matrix::Matrix()
    : rowSize(0), colSize(0)
{
} // syntax - what is :, {}, ...

Matrix::Matrix(const Matrix &matrix)
    : rowSize(matrix.rowSize), colSize(matrix.colSize), data(matrix.data) // private scope - ?
{
}

Matrix::Matrix(size_t rowSize, size_t colSize)
    : rowSize(rowSize), colSize(colSize), data(rowSize * colSize)
{
}

Matrix::Matrix(size_t rowSize, size_t colSize, int initValue)
    : rowSize(rowSize), colSize(colSize), data(rowSize * colSize, initValue)
{
}

void Matrix::print()
{
    for (size_t row = 0; row < rowSize; ++row)
    {
        for (size_t col = 0; col < colSize; ++col)
        {
            std::cout << (col > 0 ? " " : "") << std::setw(4);
            std::cout << at(row, col);
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::add(int val) const
{
    return performOperation([val](int e)
                            { return e + val; });
}

Matrix Matrix::subtract(int val) const
{
    return performOperation([val](int e)
                            { return e - val; });
}

Matrix Matrix::multiply(int val) const
{
    return performOperation([val](int e)
                            { return e * val; });
}

Matrix Matrix::performOperation(std::function<int(int)> operation) const
{
    auto result = Matrix(rowSize, colSize);
    // result.data.resize(data.size());
    std::transform(data.begin(), data.end(), result.data.begin(), operation);
    return result;
}

Matrix Matrix::add(Matrix val) const
{
    if (val.rowSize != rowSize || val.colSize != colSize)
    {
        throw std::invalid_argument("Matrices must be of an equal size.");
    }
    auto result = Matrix(rowSize, colSize);
    std::transform(val.data.begin(), val.data.end(), result.data.begin(), [this, idx = 0](int const &value) mutable
                   { return data[idx++] + value; });
    return result;
}

Matrix Matrix::subtract(Matrix val) const
{
    if (val.rowSize != rowSize || val.colSize != colSize)
    {
        throw std::invalid_argument("Matrices must be of an equal size.");
    }
    auto result = Matrix(rowSize, colSize);
    std::transform(val.data.begin(), val.data.end(), result.data.begin(), [this, idx = 0](int const &value) mutable
                   { return data[idx++] - value; });
    return result;
}

Matrix Matrix::multiply(Matrix val) const {
    // Check if matrix multiplication is possible
    if (getColSize() != val.getRowSize()) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }

    // Result matrix dimensions will be (rows of this) x (cols of val)
    Matrix result(this->getRowSize(), val.getColSize(), 0);

    // Perform matrix multiplication
    for (size_t i = 0; i < this->getRowSize(); ++i) {
        for (size_t j = 0; j < val.getColSize(); ++j) {
            int sum = 0;
            for (size_t k = 0; k < this->getColSize(); ++k) {
                sum += this->at(i, k) * val.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }

    return result;
}