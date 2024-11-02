#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <shape/shape.h>
#include <color/color.h>
#include <point/point.h>

class Triangle: public Shape
{
public:
    ~Triangle();

    // MARK: - Constructors
    Triangle();
    Triangle(Point vertex1, Point vertex2, Point vertex3);
    Triangle(const Triangle &other);

    // MARK: - Inherited from Shape
    Color getColor() override;
    bool isPointInside(Point point) override;

private:
    Point vertex1;
    Point vertex2;
    Point vertex3;
};

#endif // TRIANGLE_H
