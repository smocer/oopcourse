#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape/shape.h>
#include <color/color.h>
#include <point/point.h>

class Circle: public Shape
{
public:
    ~Circle();

    // MARK: - Constructors
    Circle();
    Circle(Point origin, int radius);
    Circle(const Circle &other);

    // MARK: - Inherited from Shape
    Color getColor() override;
    bool isPointInside(Point point) override;

private:
    Point origin_;
    int radius_;
};

#endif // CIRCLE_H
