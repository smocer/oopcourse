#include <color/color.h>;

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
    : r_(value),
      g_(value),
      b_(value)
{
}

RGBColor::RGBColor(int r, int g, int b)
    : r_(r),
      g_(g),
      b_(b)
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
    r_ = r;
    g_ = g;
    b_ = b;
}
