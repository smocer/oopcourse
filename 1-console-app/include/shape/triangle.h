#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape/shape.h"
#include "color/color.h"
#include "point/point.h"

class Triangle : public Shape
{
public:
    ~Triangle() = default;

    // MARK: - Constructors
    Triangle(Point vertex1, Point vertex2, Point vertex3, Color color);
    Triangle(const Triangle &other);

    // MARK: - Inherited from Shape
    Color getColor() const override;
    bool isPointInside(Point point) const override;
    std::vector<Point> &getPoints() const override;

private:
    Point vertex1_;
    Point vertex2_;
    Point vertex3_;
    Color color_;
};

#endif // TRIANGLE_H
