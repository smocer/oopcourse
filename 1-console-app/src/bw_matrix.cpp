#include "bw_matrix.h"

#include <iomanip>
#include <iostream>

BWMatrix::BWMatrix()
    : Matrix(0, 0, 1)
{
}

BWMatrix::BWMatrix(const BWMatrix &mat)
    : Matrix(mat)
{
}
BWMatrix::BWMatrix(size_t rows, size_t cols)
    : Matrix(rows, cols, 1)
{
}

BWMatrix::BWMatrix(size_t rows, size_t cols, int init_val)
    : Matrix(rows, cols, 1, init_val)
{
}

void BWMatrix::print() const
{
    std::cout << *this << std::endl; // this / *this?
}

BWMatrix &BWMatrix::operator=(const BWMatrix &mat)
{
    Matrix::operator=(mat);
    return *this;
}

// std::ostream &operator<<(std::ostream &out, const Matrix &mat)
// {
//     if (mat.data_.empty())
//     {
//         out << "(An empty matrix)" << std::endl;
//         return out;
//     }

//     for (size_t row = 0; row < mat.getRows(); ++row)
//     {
//         for (size_t col = 0; col < mat.getCols(); ++col)
//         {
//             out << (col > 0 ? " " : "") << std::setw(4);
//             out << mat.at(row, col, 0);
//         }
//         out << std::endl;
//     }
//     return out;
// }

BWMatrix BWMatrix::add(int val) const
{
    BWMatrix res(rows_count_, columns_count_, channels_count_);
    Matrix::add(res, val);
    return res;
}

BWMatrix BWMatrix::subtract(int val) const
{
    BWMatrix res(rows_count_, columns_count_, channels_count_);
    Matrix::subtract(res, val);
    return res;
}

BWMatrix BWMatrix::multiply(int val) const
{
    BWMatrix res(rows_count_, columns_count_, channels_count_);
    Matrix::multiply(res, val);
    return res;
}

BWMatrix BWMatrix::operator+(int val) const
{
    return add(val);
}

BWMatrix BWMatrix::operator-(int val) const
{
    return subtract(val);
}

BWMatrix BWMatrix::operator*(int val) const
{
    return multiply(val);
}