#ifndef COLOR_H
#define COLOR_H

class RGBColor;
class BWColor;

class Color
{
public:
    virtual ~Color() = default;
    Color();
    virtual RGBColor getRGB() const;
    virtual BWColor getBW() const;
};

#endif // COLOR_H
