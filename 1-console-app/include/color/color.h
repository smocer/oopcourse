#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    virtual ~Color() = default;
    virtual RGBColor getRGB() const = 0;
    virtual BWColor getBW() const = 0;
};

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

#endif // COLOR_H
