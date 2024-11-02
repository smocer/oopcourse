#ifndef BW_MATRIX_H
#define BW_MATRIX_H

#include "matrix.h"

class BWMatrix : public Matrix
{
public:
    BWMatrix();
    BWMatrix(const BWMatrix &mat);
    BWMatrix(size_t rows, size_t cols);
    BWMatrix(size_t rows, size_t cols, int init_val);

    void print() const override;
    void fromOpenCV(const cv::Mat &mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string &path) override;
    void draw(const Shape &shape) override;

    BWMatrix invert() const;

    BWMatrix add(int val) const;
    BWMatrix subtract(int val) const;
    BWMatrix multiply(int val) const;
    
    BWMatrix operator+(int val) const;
    BWMatrix operator-(int val) const;
    BWMatrix operator*(int val) const;

    BWMatrix &operator=(const BWMatrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
};

#endif // BW_MATRIX_H