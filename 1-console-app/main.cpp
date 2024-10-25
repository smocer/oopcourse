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
    RGBMatrix rgb;
    BWMatrix bw;

    bw.readImage("images/bw.jpg");
    rgb.readImage("images/rgb.jpg");
    bw.display();
    bw.invert().display();
    rgb.display();
    rgb.toBW().display();
    return 0;
}