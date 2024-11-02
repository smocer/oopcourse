#include "color/color.h"
#include "color/rgb_color.h"
#include "color/bw_color.h"

#include <exception>

Color::Color() {}
RGBColor Color::getRGB() const { return RGBColor(); }
BWColor Color::getBW() const { return BWColor(); }
