#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <functional>
#include <iostream>

class Matrix
{
public:
    Matrix();
    Matrix(const Matrix &mat);
    Matrix(size_t rows_count, size_t columns_count, size_t channels);
    Matrix(size_t rows_count, size_t columns_count, size_t channels, int init_value);

    // why inline
    inline size_t getRows() const { return rows_count_; }
    inline size_t getCols() const { return columns_count_; }
    inline size_t getChannels() const { return channels_count_; }

    // why `int &` instead of int
    inline const int &at(size_t row, size_t col, size_t channel = 0) const
    {
        return data_[row * columns_count_ * channels_count_ + col * channels_count_ + channel];
    }

    // what's the difference with the previous one
    inline int &at(size_t row, size_t col, size_t channel = 0)
    {
        return data_[row * columns_count_ * channels_count_ + col * channels_count_ + channel];
    }

    virtual void print() const;

    Matrix add(int val) const;
    Matrix subtract(int val) const;
    Matrix multiply(int val) const;
    Matrix performOperation(std::function<int(int)> operation) const;

    Matrix add(Matrix val) const;
    Matrix subtract(Matrix val) const;
    Matrix multiply(Matrix val) const;

    Matrix operator+(int val) const;
    Matrix operator+(Matrix val) const;
    Matrix operator-(int val) const;
    Matrix operator-(Matrix val) const;
    Matrix operator*(int val) const;
    Matrix operator*(Matrix val) const;
    Matrix &operator=(const Matrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);

protected:
    size_t rows_count_;
    size_t columns_count_;
    size_t channels_count_;
    std::vector<int> data_;
};

#endif // MATRIX_H