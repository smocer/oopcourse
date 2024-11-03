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
#include <chrono>

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

void mushroomExample()
{
    int bgColor = 255;
    int capColor = 179;
    int stipeColor = 128;
    int bottomColor = 52;
    BWMatrix bw(2000, 2000, 255);
    BWColor bwColor(capColor);
    Circle cap({1000, 1000}, 700, bwColor);
    bwColor.changeColor(bgColor);
    Rectangle background({0, 700}, 2000, 1000, bwColor);
    Rectangle background2({800, 1300}, 400, 200, bwColor);
    bwColor.changeColor(stipeColor);
    Triangle stipe({1000, 350}, {1200, 1500}, {800, 1500}, bwColor);
    bwColor.changeColor(capColor);
    Rectangle background3({800, 350}, 400, 350, bwColor);
    bwColor.changeColor(bottomColor);
    Circle bottom({1000, 1500}, 200, bwColor);

    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);
    // bw.display();
}

void houseExample()
{
    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({0, 0}, 2000, 1500, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({0, 1500}, 2000, 2000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({50, 50}, 300, rgbColor);
    Triangle ray1({360, 50}, {550, 30}, {550, 70}, rgbColor);
    Triangle ray2({270, 270}, {420, 360}, {390, 400}, rgbColor);
    Triangle ray3({50, 360}, {30, 550}, {70, 550}, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({600, 900}, 1000, 800, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({1300, 550}, 100, 200, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({560, 900}, {1100, 500}, {1640, 900}, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({1400, 1350}, 150, 300, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({1535, 1500}, 6, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({700, 950}, 300, 350, rgbColor);
    Rectangle window2({1200, 950}, 300, 350, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);
    // rgb.display();
}

void myExample()
{
    RGBMatrix rgb(2000, 2000, 0);

    RGBColor rgbColor(0, 0, 50);
    Rectangle sky({0, 0}, 2000, 1500, rgbColor);
    rgb.draw(sky);

    rgbColor.changeColor(255, 255, 150);
    Circle moon({1800, 200}, 100, rgbColor);
    rgb.draw(moon);

    rgbColor.changeColor(255, 255, 255);
    for (int i = 0; i < 100; ++i)
    {
        int x = std::rand() % 2000;
        int y = std::rand() % 1500;
        Circle star({x, y}, 3, rgbColor);
        rgb.draw(star);
    }

    rgbColor.changeColor(5, 50, 15);
    Rectangle grass({0, 1500}, 2000, 500, rgbColor);
    rgb.draw(grass);

    for (int i = 50; i < 2000; i += 200)
    {
        rgbColor.changeColor(0, 100, 0);
        Circle foliage({i, 1300}, 80, rgbColor);
        rgbColor.changeColor(140, 70, 20);
        Rectangle trunk({i - 10, 1370}, 20, 130, rgbColor);
        rgb.draw(foliage);
        rgb.draw(trunk);
    }

    rgbColor.changeColor(25, 25, 110);
    Circle lake({1000, 3600}, 2000, rgbColor);
    rgb.draw(lake);

    rgbColor.changeColor(255, 255, 255);
    for (int i = 0; i < 100; ++i)
    {
        int x = std::rand() % 2000;
        int y = 1500 + std::rand() % 500;
        if ((x - 1000) * (x - 1000) + (y - 3600) * (y - 3600) < 2000 * 2000)
        {
            Circle star({x, y}, 3, rgbColor);
            rgb.draw(star);
        }
    }

    for (int i = 450; i < 1800; i += 200)
    {
        int topLakeY = abs(sqrt(2000 * 2000 - (i - 1000) * (i - 1000)) - 3600);
        rgbColor.changeColor(70, 20, 15);
        Rectangle trunk({i - 10, std::max(1590, topLakeY)}, 20, 130 - topLakeY + 1590, rgbColor);
        rgbColor.changeColor(0, 40, 20);
        Circle foliage({i, 1800}, 80, rgbColor);
        rgb.draw(foliage);
        rgb.draw(trunk);
    }

    // rgb.display();
}

using Time = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;
using ms = std::chrono::milliseconds;

double measureExecutionTimeMs(std::function<void()> lambda)
{
    Time::time_point start = Time::now();
    lambda();
    Time::time_point end = Time::now();
    double duration = std::chrono::duration_cast<ms>(end - start).count();
    return duration;
}

double measureExecutionTimeLikeOnTheSlide(std::function<void()> lambda)
{
    Time::time_point start = Time::now();
    lambda();
    Time::time_point end = Time::now();
    double duration = std::chrono::duration_cast<ns>(end - start).count() * 10e-6;
    return duration;
}

int main()
{
    std::cout << "Mushroom time: " << measureExecutionTimeLikeOnTheSlide(mushroomExample) << "ms" << std::endl;
    std::cout << "House time: " << measureExecutionTimeLikeOnTheSlide(houseExample) << "ms" << std::endl;
    std::cout << "My time: " << measureExecutionTimeLikeOnTheSlide(myExample) << "ms" << std::endl;
    return 0;
}