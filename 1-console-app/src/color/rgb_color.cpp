#include "color/rgb_color.h"
#include <algorithm>

// MARK: - Constructors
RGBColor::RGBColor()
    : r_(0),
      g_(0),
      b_(0)
{
}

RGBColor::RGBColor(const RGBColor &other)
    : r_(other.r_),
      g_(other.g_),
      b_(other.b_)
{
}

RGBColor::RGBColor(int value)
    : r_(std::clamp(value, 0, 255)),
      g_(std::clamp(value, 0, 255)),
      b_(std::clamp(value, 0, 255))
{
}

RGBColor::RGBColor(int r, int g, int b)
    : r_(std::clamp(r, 0, 255)),
      g_(std::clamp(g, 0, 255)),
      b_(std::clamp(b, 0, 255))
{
}

// MARK: - Inherited from Color
RGBColor RGBColor::getRGB() const
{
    return RGBColor(*this);
}

BWColor RGBColor::getBW() const
{
    int grayscale = (r_ + g_ + b_) / 3;
    return BWColor(grayscale);
}

// MARK: - Other methods
void RGBColor::changeColor(int r, int g, int b)
{
    r_ = std::clamp(r, 0, 255);
    g_ = std::clamp(r, 0, 255);
    b_ = std::clamp(r, 0, 255);
}
