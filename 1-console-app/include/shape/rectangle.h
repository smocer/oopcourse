#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape/shape.h"
#include "color/color.h"
#include "point/point.h"

class Rectangle : public Shape
{
public:
    ~Rectangle() = default;

    // MARK: - Constructors
    Rectangle(Point origin, int width, int height, Color color);
    Rectangle(const Rectangle &other);

    // MARK: - Inherited from Shape
    Color getColor() override;
    bool isPointInside(Point point) override;

private:
    Point origin_;
    int width_;
    int height_;
    Color color_;
};

#endif // RECTANGLE_H
