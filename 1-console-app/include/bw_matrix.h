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

    BWMatrix &operator=(const BWMatrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
};

#endif // BW_MATRIX_H