#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "shape/shape.h"

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

    virtual void print() const = 0;
    virtual void fromOpenCV(const cv::Mat &mat) = 0;
    virtual cv::Mat toOpenCV() const = 0;
    virtual bool readImage(const std::string &path) = 0;
    virtual void draw(const Shape &shape) = 0;
    void display() const;

    Matrix &operator=(const Matrix &mat);

protected:
    void add(Matrix &res, int val) const;
    void subtract(Matrix &res, int val) const;
    void multiply(Matrix &res, int val) const;

protected:
    size_t rows_count_;
    size_t columns_count_;
    size_t channels_count_;
    std::vector<int> data_;
};

#endif // MATRIX_H