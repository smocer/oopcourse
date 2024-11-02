#include "shape/triangle.h"
#include <cmath>

// MARK: - Constructors
Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3, Color color)
    : vertex1_(vertex1),
      vertex2_(vertex2),
      vertex3_(vertex3),
      color_(color)
{
}

Triangle::Triangle(const Triangle &other)
    : vertex1_(other.vertex1_),
      vertex2_(other.vertex2_),
      vertex3_(other.vertex3_),
      color_(other.color_)
{
}

// MARK: - Inherited from Shape
Color Triangle::getColor()
{
    return color_;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

bool Triangle::isPointInside(Point point)
{
    double x = (double)point.x;
    double y = (double)point.y;
    double x1 = (double)vertex1_.x;
    double y1 = (double)vertex1_.y;
    double x2 = (double)vertex2_.x;
    double y2 = (double)vertex2_.y;
    double x3 = (double)vertex3_.x;
    double y3 = (double)vertex3_.y;
    double area_all = area(x1, y1, x2, y2, x3, y3);
    double area_1 = area(x, y, x2, y2, x3, y3);
    double area_2 = area(x1, y1, x, y, x3, y3);
    double area_3 = area(x1, y1, x2, y2, x, y);
    double tolerance = 1e-9;
    return std::abs(area_all - (area_1 + area_2 + area_3)) < tolerance;
}