#include "CompositeShape.h"

void CompositeShape::move(double x, double y)
{
    for (auto& shape : shape_)
    {
        shape->move(x, y);
    }
}
void CompositeShape::scale(double coefficient)
{
    if (coefficient <= 0)
    {
        throw std::invalid_argument("coefficient must be greater than 0");
    }
    Point centerComposite = getCenter();
    for (auto& shape : shape_)
    {
        Point shapeCenter = shape->getCenter();
        double newX = (shapeCenter.x_ - centerComposite.x_) * (coefficient - 1);
        double newY = (shapeCenter.y_ - centerComposite.y_) * (coefficient - 1);
        shape->move(newX, newY);
        shape->scale(coefficient);
    }
}
Point CompositeShape::getCenter() const
{
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::min();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::min();
    for (auto& shape : shape_)
    {
        Point center = shape->getCenter();
        minX = std::min(minX, center.x_);
        maxX = std::max(maxX, center.x_);
        minY = std::min(minY, center.y_);
        maxY = std::max(maxY, center.y_);
    }
    return Point((minX + maxX) / 2, (minY + maxY) / 2);
}
double CompositeShape::getArea() const
{
    double total = 0.0;
    for (auto& shape : shape_)
    {
        total += shape->getArea();
    }
    return total;
}
const char* CompositeShape::getName() const
{
    return "COMPOSITESHAPE";
}
void CompositeShape::add(std::unique_ptr<Shape> shape)
{
    shape_.push_back(std::move(shape));
}
void CompositeShape::print() const
{
    Point center = getCenter();
    std::cout << std::setprecision(2) << std::fixed << "\n[" << getName() << ", (" <<
        center.x_ << ", " << center.y_ << "), " << getArea() << ":";
    for (size_t i = 0; i < shape_.size(); i++) {
        std::cout << "\n";
        shape_[i]->print();
    }
    std::cout << "\n]" << std::endl;
}
