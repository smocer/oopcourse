#include "shape/circle.h"
#include <vector>

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
Color Circle::getColor() const
{
    return color_;
}

bool Circle::isPointInside(Point point) const
{
    double x_x0 = (double)point.x - (double)origin_.x;
    double y_y0 = (double)point.y - (double)origin_.y;
    double r = (double)radius_;
    return x_x0 * x_x0 + y_y0 * y_y0 <= r * r;
}

std::vector<Point> &Circle::getPoints() const 
{
    std::vector<Point> *result = new std::vector<Point>;
    int xMin = origin_.x - radius_;
    int yMin = origin_.y - radius_;
    int xMax = origin_.x + radius_;
    int yMax = origin_.y + radius_;
    for (int x = xMin; x < xMax; ++x)
    {
        for (int y = yMin; y < yMax; ++y)
        {
            if (isPointInside({x, y}))
            {
                result->push_back({x, y});
            }
        }
    }
    return *result;
}
