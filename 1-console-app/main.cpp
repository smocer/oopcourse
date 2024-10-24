#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void GenMatrix(Matrix &mat, int min = 0, int max = 255)
{
    for (size_t r = 0; r < mat.getRows(); ++r)
    {
        for (size_t c = 0; c < mat.getCols(); ++c)
        {
            for (size_t ch = 0; ch < mat.getChannels(); ++ch)
            {
                mat.at(r, c, ch) = min + std::rand() % (max - min + 1);
            }
        }
    }
}

int main()
{
    std::srand(std::time(nullptr));
    Matrix a(2, 3, 3);
    Matrix a1(2, 3, 3);
    Matrix b(2, 3, 2, 3);
    Matrix c1(3, 2, 1);
    Matrix c2(2, 3, 1);
    GenMatrix(a);
    GenMatrix(a1);
    GenMatrix(c1);
    GenMatrix(c2);

    std::cout << a;
    std::cout << "_____________" << std::endl;
    std::cout << a1;
    std::cout << "_____________" << std::endl;
    std::cout << a + a1;
    std::cout << "_____________" << std::endl;
    std::cout << c1;
    std::cout << "_____________" << std::endl;
    std::cout << c2;
    std::cout << "_____________" << std::endl;
    std::cout << c1 * c2;

    return 0;
}