#include <color/color.h>;

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
    : value_(value)
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
    value_ = value;
}
