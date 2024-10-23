#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <functional>

class Matrix
{
public:
    Matrix();
    Matrix(const Matrix &mat);
    Matrix(int num_rows, int num_cols);
    Matrix(size_t rowSize, size_t colSize);
    Matrix(size_t rowSize, size_t colSize, int initValue);

    inline size_t getRows() const { return rowSize; } // why inline
    inline size_t getCols() const { return colSize; }
    inline const int &at(size_t row, size_t col) const { return data[row * rowSize + col]; } // why `int &` instead of int
    inline int &at(size_t row, size_t col) { return data[row * rowSize + col]; } // what's the difference with the previous one

    void print();

    Matrix add(int val) const;
    Matrix subtract(int val) const;
    Matrix multiply(int val) const;
    Matrix performOperation(std::function<int(int)> operation) const;

    Matrix add(Matrix val) const;
    Matrix subtract(Matrix val) const;
    Matrix multiply(Matrix val) const;

    Matrix& operator=(const Matrix& mat);

private:
    size_t rowSize;
    size_t colSize;
    std::vector<int> data;
};

#endif // MATRIX_H