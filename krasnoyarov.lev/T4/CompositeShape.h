#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include "shape.h"
#include <vector>
#include <memory>
#include <limits>

class CompositeShape : public Shape
{
private:
    std::vector<std::unique_ptr<Shape>> shape_;
public:
    CompositeShape() = default;
    double getArea() const override;
    Point getCenter() const override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    const char* getName() const override;
    ~CompositeShape() = default;
    void add(std::unique_ptr<Shape> shape);
    void print() const override;
};

#endif
