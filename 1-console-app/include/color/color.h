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
        r_ = std::clamp(r, 0, 255);
        g_ = std::clamp(g, 0, 255);
        b_ = std::clamp(b, 0, 255);
    }

    void changeColor(int gray)
    {
        r_ = std::clamp(gray, 0, 255);
        g_ = std::clamp(gray, 0, 255);
        b_ = std::clamp(gray, 0, 255);
    }

private:
    int r_, g_, b_;
};

typedef Color RGBColor;
typedef Color BWColor;

#endif // COLOR_H
