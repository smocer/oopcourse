#include "matrix/rgb_matrix.h"

#include <iomanip>
#include <iostream>
#include <tuple>

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

void RGBMatrix::fromOpenCV(const cv::Mat &mat)
{
    if (mat.channels() != 3 || mat.depth() != CV_8U)
    {
        return;
    }

    rows_count_ = mat.rows;
    columns_count_ = mat.cols;
    data_.resize(mat.total() * mat.channels());

    for (size_t r = 0; r < rows_count_; ++r)
    {
        for (size_t c = 0; c < columns_count_; ++c)
        {
            auto val = mat.at<cv::Vec3b>(r, c);
            at(r, c, 0) = val[2];
            at(r, c, 1) = val[1];
            at(r, c, 2) = val[0];
        }
    }
}

cv::Mat RGBMatrix::toOpenCV() const
{
    cv::Mat mat(rows_count_, columns_count_, CV_8UC3);

    for (size_t r = 0; r < rows_count_; ++r)
    {
        for (size_t c = 0; c < columns_count_; ++c)
        {
            cv::Vec3b val;
            val[0] = at(r, c, 2);
            val[1] = at(r, c, 1);
            val[2] = at(r, c, 0);
            mat.at<cv::Vec3b>(r, c) = val;
        }
    }
    return mat;
}

bool RGBMatrix::readImage(const std::string &path)
{
    cv::Mat rgbImage = cv::imread(path, cv::IMREAD_COLOR);
    if (rgbImage.empty())
    {
        return false;
    }
    fromOpenCV(rgbImage);
    return true;
}

void RGBMatrix::draw(Shape *shape)
{
    auto color = shape->getColor().getRGB();
    for (int y = 0; y < rows_count_; ++y)
    {
        for (int x = 0; x < columns_count_; ++x)
        {
            if (shape->isPointInside({x, y}))
            {
                at(y, x, 0) = std::get<0>(color);
                at(y, x, 1) = std::get<1>(color);
                at(y, x, 2) = std::get<2>(color);
            }
        }
    }
}

BWMatrix RGBMatrix::toBW() const
{
    BWMatrix res(rows_count_, columns_count_);
    for (size_t r = 0; r < rows_count_; ++r)
    {
        for (size_t c = 0; c < columns_count_; ++c)
        {
            int gray = (at(r, c, 0) + at(r, c, 1) + at(r, c, 2)) / 3;
            res.at(r, c) = gray;
        }
    }
    return res;
}

RGBMatrix &RGBMatrix::operator=(const RGBMatrix &mat)
{
    Matrix::operator=(mat);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
    if (mat.getRows() == 0 || mat.getCols() == 0)
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
                out << (channel > 0 ? ", " : "") << std::setw(4);
                out << names[channel] << ": " << mat.at(row, col, channel);
            }
            out << ")";
        }
        out << std::endl;
    }
    return out;
}

RGBMatrix RGBMatrix::add(int val) const
{
    RGBMatrix res(rows_count_, columns_count_, channels_count_);
    Matrix::add(res, val);
    return res;
}

RGBMatrix RGBMatrix::subtract(int val) const
{
    RGBMatrix res(rows_count_, columns_count_, channels_count_);
    Matrix::subtract(res, val);
    return res;
}

RGBMatrix RGBMatrix::multiply(int val) const
{
    RGBMatrix res(rows_count_, columns_count_, channels_count_);
    Matrix::multiply(res, val);
    return res;
}

RGBMatrix RGBMatrix::operator+(int val) const
{
    return add(val);
}

RGBMatrix RGBMatrix::operator-(int val) const
{
    return subtract(val);
}

RGBMatrix RGBMatrix::operator*(int val) const
{
    return multiply(val);
}