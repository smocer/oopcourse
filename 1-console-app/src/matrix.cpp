#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>

// MARK: - Constructors

Matrix::Matrix()
    : rows_count_(0),
      columns_count_(0),
      channels_count_(0),
      data_(0)
{
} // syntax - what is :, {}, ...

Matrix::Matrix(const Matrix &matrix)
    : rows_count_(matrix.rows_count_),
      columns_count_(matrix.columns_count_),
      channels_count_(matrix.channels_count_),
      data_(matrix.data_) // private scope - ?
{
}

Matrix::Matrix(int num_rows, int num_cols, int channels)
    : rows_count_(num_rows),
      columns_count_(num_cols),
      channels_count_(channels),
      data_(num_rows * num_cols * channels)
{
}

Matrix::Matrix(size_t rows_count, size_t columns_count, size_t channels_count)
    : rows_count_(rows_count),
      columns_count_(columns_count),
      channels_count_(channels_count),
      data_(rows_count * columns_count * channels_count)
{
}

Matrix::Matrix(size_t rows_count, size_t columns_count, size_t channels_count, int init_value)
    : rows_count_(rows_count),
      columns_count_(columns_count),
      channels_count_(channels_count),
      data_(rows_count * columns_count, init_value)
{
}

// MARK: - Methods

void Matrix::print() const
{
    std::cout << *this << std::endl;
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
    auto result = Matrix(rows_count_, columns_count_, channels_count_);
    // result.data.resize(data.size());
    std::transform(data_.begin(), data_.end(), result.data_.begin(), operation);
    return result;
}

Matrix Matrix::add(Matrix val) const
{
    if (val.rows_count_ != rows_count_ || val.columns_count_ != columns_count_)
    {
        return Matrix();
        // throw std::invalid_argument("Matrices must be of an equal size.");
    }
    auto result = Matrix(rows_count_, columns_count_, channels_count_);
    std::transform(val.data_.begin(), val.data_.end(), result.data_.begin(), [this, idx = 0](int const &value) mutable
                   { return data_[idx++] + value; });
    return result;
}

Matrix Matrix::subtract(Matrix val) const
{
    if (val.rows_count_ != rows_count_ || val.columns_count_ != columns_count_)
    {
        return Matrix();
        // throw std::invalid_argument("Matrices must be of an equal size.");
    }
    auto result = Matrix(rows_count_, columns_count_, channels_count_);
    std::transform(val.data_.begin(), val.data_.end(), result.data_.begin(), [this, idx = 0](int const &value) mutable
                   { return data_[idx++] - value; });
    return result;
}

Matrix Matrix::multiply(Matrix val) const
{
    // Check if matrix multiplication is possible
    if (getCols() != val.getRows() || (getChannels() != 1 && val.getChannels() != 1))
    {
        return Matrix();
        // throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }

    // Result matrix dimensions will be (rows of this) x (cols of val)
    // TODO: Change 1 to the correct number of channels
    Matrix result(this->getRows(), val.getCols(), 1, 0);

    // Perform matrix multiplication
    for (size_t i = 0; i < this->getRows(); ++i)
    {
        for (size_t j = 0; j < val.getCols(); ++j)
        {
            int sum = 0;
            for (size_t k = 0; k < this->getCols(); ++k)
            {
                sum += this->at(i, k) * val.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }

    return result;
}

// MARK: - Operators

Matrix Matrix::operator+(int val) const
{
    return add(val);
}

Matrix Matrix::operator+(Matrix val) const
{
    return add(val);
}

Matrix Matrix::operator-(int val) const
{
    return subtract(val);
}

Matrix Matrix::operator-(Matrix val) const
{
    return subtract(val);
}

Matrix Matrix::operator*(int val) const
{
    return multiply(val);
}

Matrix Matrix::operator*(Matrix val) const
{
    return multiply(val);
}

Matrix &Matrix::operator=(const Matrix &mat)
{
    if (this != &mat)
    {
        Matrix tmp(mat);

        std::swap(rows_count_, tmp.rows_count_);
        std::swap(columns_count_, tmp.columns_count_);
        std::swap(channels_count_, tmp.channels_count_);
        std::swap(data_, tmp.data_);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
    if (mat.data_.empty())
    {
        out << "(An empty matrix)" << std::endl;
        return out;
    }

    for (size_t row = 0; row < mat.getRows(); ++row)
    {
        for (size_t col = 0; col < mat.getCols(); ++col)
        {
            out << (col > 0 ? " " : "") << std::setw(2);
            out << "(";
            for (size_t channel = 0; channel < mat.getChannels(); ++channel)
            {
                out << (channel > 0 ? ", " : "") << std::setw(3);
                out << mat.at(row, col, channel);
            }
            out << ")";
        }
        out << std::endl;
    }
    return out;
}