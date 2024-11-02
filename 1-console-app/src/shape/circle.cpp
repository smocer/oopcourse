#include "shape/circle.h"

// MARK: - Constructors
Circle::Circle(Point origin, int radius, Color color)
    : origin_(origin),
      radius_(radius),
      color_(color)
{
}

Circle::Circle(const Circle &other)
    : origin_(other.origin_),
      radius_(other.radius_),
      color_(other.color_)
{
}

// MARK: - Inherited from Shape
Color Circle::getColor()
{
    return color_;
}

bool Circle::isPointInside(Point point)
{
    double x_x0 = (double)point.x - (double)origin_.x;
    double y_y0 = (double)point.y - (double)origin_.y;
    double r = (double)radius_;
    return x_x0 * x_x0 + y_y0 * y_y0 <= r * r;
}
