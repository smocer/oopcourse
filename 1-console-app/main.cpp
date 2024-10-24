#include "matrix.h"
#include "rgb_matrix.h"
#include "bw_matrix.h"
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
    RGBMatrix a(2, 3);
    GenMatrix(a);

    std::cout << a;

    return 0;
}