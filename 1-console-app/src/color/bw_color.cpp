#include "color/bw_color.h"
#include <algorithm>

// MARK: - Constructors
BWColor::BWColor()
    : value_(0)
{
}

BWColor::BWColor(const BWColor &other)
    : value_(other.value_)
{
}

BWColor::BWColor(int value)
    : value_(std::clamp(value, 0, 255))
{
}

// MARK: - Inherited from Color
RGBColor BWColor::getRGB() const
{
    return RGBColor(value_);
}

BWColor BWColor::getBW() const
{
    return BWColor(*this);
}

// MARK: - Other methods
void BWColor::changeColor(int value)
{
    value_ = std::clamp(value, 0, 255);
}
