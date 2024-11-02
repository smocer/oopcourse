#ifndef BW_COLOR_H
#define BW_COLOR_H

#include "color/color.h"
#include "color/rgb_color.h"

class BWColor : public Color
{
public:
    ~BWColor() = default;

    // MARK: - Constructors
    BWColor();
    BWColor(const BWColor &other);
    BWColor(int value);

    // MARK: - Inherited from Color
    RGBColor getRGB() const override;
    BWColor getBW() const override;

    // MARK: - Other methods
    void changeColor(int value);

private:
    int value_;
};

#endif // BW_COLOR_H
