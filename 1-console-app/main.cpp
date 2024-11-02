#include "matrix/matrix.h"
#include "matrix/rgb_matrix.h"
#include "matrix/bw_matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "color/color.h"
#include "color/bw_color.h"
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

    bw.readImage(std::string(PROJECT_SOURCE_DIR) + "/images/bw.jpg");
    rgb.readImage(std::string(PROJECT_SOURCE_DIR) + "/images/rgb.jpg");
    bw.display();
    bw.invert().display();
    rgb.display();
    rgb.toBW().display();

    BWColor bwCol(100);
    Rectangle rect({20, 20}, 100, 30, BWColor(100));
    // std::cout << rect.isPointInside({500, 500}) << std::endl;

    // Triangle<RGBColor> tri({40, 40}, {50, 50}, {60, 60}, RGBColor(255));
    // std::cout << tri.isPointInside({500, 500}) << std::endl;
    return 0;
}