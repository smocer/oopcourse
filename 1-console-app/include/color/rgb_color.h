#ifndef RGB_COLOR_H
#define RGB_COLOR_H

#include "color/color.h"
#include "color/bw_color.h"

class RGBColor : public Color
{
public:
    ~RGBColor() = default;

    // MARK: - Constructors
    RGBColor();
    RGBColor(const RGBColor &other);
    RGBColor(int value);
    RGBColor(int r, int g, int b);

    // MARK: - Inherited from Color
    RGBColor getRGB() const override;
    BWColor getBW() const override;

    // MARK: - Other methods
    void changeColor(int r, int g, int b);

private:
    int r_, g_, b_;
};

#endif // RGB_COLOR_H
