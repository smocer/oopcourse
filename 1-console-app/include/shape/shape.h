#ifndef SHAPE_H
#define SHAPE_H

#include "color/color.h"
#include "point/point.h"

class Shape
{
public:
    virtual ~Shape() = default;

    virtual Color getColor() const = 0;
    virtual bool isPointInside(Point point) const = 0;
    virtual std::vector<Point> &getPoints() const = 0;
};

#endif // SHAPE_H
