#ifndef COLOR_H
#define COLOR_H

#include <algorithm>
#include <tuple>

class Color
{
public:
    virtual ~Color() = default;

    Color() : r_(0), g_(0), b_(0) {};
    Color(int r, int g, int b)
        : r_(std::clamp(r, 0, 255)),
          g_(std::clamp(g, 0, 255)),
          b_(std::clamp(b, 0, 255)) {};
    Color(int gray)
        : r_(std::clamp(gray, 0, 255)),
          g_(std::clamp(gray, 0, 255)),
          b_(std::clamp(gray, 0, 255)) {};

    std::tuple<int, int, int> getRGB() const
    {
        return std::tuple<int, int, int>{r_, g_, b_};
    };

    int getBW() const
    {
        return (r_ + g_ + b_) / 3;
    };

    void changeColor(int r, int g, int b)
    {
        r_ = r;
        g_ = g;
        b_ = b;
    }

    void changeColor(int gray)
    {
        r_ = gray;
        g_ = gray;
        b_ = gray;
    }

private:
    int r_, g_, b_;
};

class RGBColor : public Color
{
    using Color::Color;
};
class BWColor : public Color
{
    using Color::Color;
};

#endif // COLOR_H
