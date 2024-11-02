#include "matrix/matrix.h"
#include "matrix/rgb_matrix.h"
#include "matrix/bw_matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "color/color.h"
#include "shape/triangle.h"
#include "shape/rectangle.h"
#include "shape/circle.h"

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

    BWColor bwCol(100);
    Rectangle rect({20, 20}, 100, 30, BWColor(100));
    std::cout << rect.isPointInside({500, 500}) << std::endl;

    Triangle tri({40, 40}, {50, 50}, {0, 60}, RGBColor(255));
    std::cout << tri.isPointInside({42, 45}) << std::endl;
    return 0;
}