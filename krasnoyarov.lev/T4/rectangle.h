#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle : public Shape
{
private:
    Point leftBottom_;
    Point rightTop_;
public:
    Rectangle(Point leftBottom, Point rightTop);
    double getArea() const override;
    Point getCenter() const override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    const char* getName() const override;
    ~Rectangle() = default;
    void print() const override;
};

#endif // !RECTANGLE_H
