#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
#include <stdexcept>
#include <iomanip>
#include <iostream>
class Shape
{
public:
    virtual double getArea() const = 0;
    virtual Point getCenter() const = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double coefficient) = 0;
    virtual const char* getName() const = 0;
    virtual ~Shape() = default;
    virtual void print() const = 0;
};

#endif // !SHAPE_H
