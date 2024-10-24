#include "rgb_matrix.h"

#include <iomanip>
#include <iostream>

RGBMatrix::RGBMatrix()
    : Matrix(0, 0, 3)
{
}

RGBMatrix::RGBMatrix(const RGBMatrix &mat)
    : Matrix(mat)
{
}
RGBMatrix::RGBMatrix(size_t rows, size_t cols)
    : Matrix(rows, cols, 3)
{
}

RGBMatrix::RGBMatrix(size_t rows, size_t cols, int init_val)
    : Matrix(rows, cols, 3, init_val)
{
}

void RGBMatrix::print() const
{
    std::cout << *this << std::endl; // this / *this?
}

RGBMatrix &RGBMatrix::operator=(const RGBMatrix &mat)
{
    Matrix::operator=(mat);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
    if (mat.data_.empty())
    {
        out << "(An empty matrix)" << std::endl;
        return out;
    }

    static const std::vector<std::string> names = {"R", "G", "B"};
    for (size_t row = 0; row < mat.getRows(); ++row)
    {
        for (size_t col = 0; col < mat.getCols(); ++col)
        {
            out << (col > 0 ? " " : "") << std::setw(2);
            out << "(";
            for (size_t channel = 0; channel < mat.getChannels(); ++channel)
            {
                out << (channel > 0 ? ", " : "") << std::setw(3);
                out << names[channel] << ": " << mat.at(row, col, channel);
            }
            out << ")";
        }
        out << std::endl;
    }
    return out;
}