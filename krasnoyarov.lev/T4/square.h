#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
private:
    Point leftBottom_;
    double side_;
public:
    Square(Point leftBottom, double side);
    double getArea() const override;
    Point getCenter() const override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    const char* getName() const override;
    ~Square() = default;
    void print() const override;
};

#endif // !SQUARE_H
