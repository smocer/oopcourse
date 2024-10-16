#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <functional>

class Matrix
{
public:
    Matrix();
    Matrix(const Matrix &mat);
    Matrix(size_t rowSize, size_t colSize);
    Matrix(size_t rowSize, size_t colSize, int initValue);

    inline size_t getRowSize() const { return rowSize; } // why inline
    inline size_t getColSize() const { return colSize; }
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

    

private:
    size_t rowSize;
    size_t colSize;
    std::vector<int> data;
};

#endif // MATRIX_H