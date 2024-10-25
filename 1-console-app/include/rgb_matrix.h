#ifndef RGB_MATRIX_H
#define RGB_MATRIX_H

#include "matrix.h"

class RGBMatrix : public Matrix
{
public:
    RGBMatrix();
    RGBMatrix(const RGBMatrix &mat);
    RGBMatrix(size_t rows, size_t cols);
    RGBMatrix(size_t rows, size_t cols, int init_val);

    void print() const override;
    void fromOpenCV(const cv::Mat &mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string &path) override;

    RGBMatrix add(int val) const;
    RGBMatrix subtract(int val) const;
    RGBMatrix multiply(int val) const;
    
    RGBMatrix operator+(int val) const;
    RGBMatrix operator-(int val) const;
    RGBMatrix operator*(int val) const;
    
    RGBMatrix &operator=(const RGBMatrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
};

#endif // RGB_MATRIX_H