#include "shape/rectangle.h"
#include <vector>

// MARK: - Constructors
Rectangle::Rectangle(Point origin, int width, int height, Color color)
    : origin_(origin),
      width_(width),
      height_(height),
      color_(color)
{
}

Rectangle::Rectangle(const Rectangle &other)
    : origin_(other.origin_),
      width_(other.width_),
      height_(other.height_),
      color_(other.color_)
{
}

// MARK: - Inherited from Shape
Color Rectangle::getColor() const
{
    return color_;
}

bool Rectangle::isPointInside(Point point) const
{
    return point.x >= origin_.x &&
           point.y >= origin_.y &&
           point.x <= origin_.x + width_ &&
           point.y <= origin_.y + height_;
}

std::vector<Point> &Rectangle::getPoints() const
{
    std::vector<Point> *result = new std::vector<Point>;
    for (int x = origin_.x; x < origin_.x + width_; ++x)
    {
        for (int y = origin_.y; y < origin_.y + height_; ++y)
        {
            result->push_back({x, y});
        }
    }
    return *result;
}
