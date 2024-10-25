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

void Matrix::display() const
{
    cv::imshow("Display image", toOpenCV());
    cv::waitKey(0);
}

// MARK: - Operators

Matrix &Matrix::operator=(const Matrix &mat)
{
    if (this != &mat)
    {
        rows_count_ = mat.rows_count_;
        columns_count_ = mat.columns_count_;
        channels_count_ = mat.channels_count_;
        data_ = mat.data_;
    }

    return *this;
}

void Matrix::add(Matrix &res, int val) const
{
    for (size_t i = 0; i < data_.size(); ++i)
    {
        res.data_[i] = data_[i] + val;
    }
}

void Matrix::subtract(Matrix &res, int val) const
{
    for (size_t i = 0; i < data_.size(); ++i)
    {
        res.data_[i] = data_[i] - val;
    }
}

void Matrix::multiply(Matrix &res, int val) const
{
    for (size_t i = 0; i < data_.size(); ++i)
    {
        res.data_[i] = data_[i] * val;
    }
}