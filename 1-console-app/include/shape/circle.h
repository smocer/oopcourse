#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape/shape.h"
#include "color/color.h"
#include "point/point.h"

class Circle : public Shape
{
public:
    ~Circle() = default;

    // MARK: - Constructors
    Circle(Point origin, int radius, Color color);
    Circle(const Circle &other);

    // MARK: - Inherited from Shape
    Color getColor() const override;
    bool isPointInside(Point point) const override;
    std::vector<Point> &getPoints() const override;

private:
    Point origin_;
    int radius_;
    Color color_;
};

#endif // CIRCLE_H
