#include "square.h"
Square::Square(Point leftBottom, double side) : leftBottom_(leftBottom), side_(side)
{
    if (side < 0)
    {
        throw std::invalid_argument("side of square must be greater than 0");
    }
}
double Square::getArea() const
{
    return side_ * side_;
}
Point Square::getCenter() const
{
    return Point(leftBottom_.x_ + side_ / 2, leftBottom_.y_ + side_ / 2);
}
const char* Square::getName() const
{
    return "SQUARE";
}
void Square::move(double x, double y)
{
    leftBottom_.x_ += x;
    leftBottom_.y_ += y;
}
void Square::scale(double coefficient)
{
    if (coefficient <= 0)
    {
        throw std::invalid_argument("coefficient must be greater than 0");
    }
    Point center = getCenter();
    leftBottom_.x_ = center.x_ + (leftBottom_.x_ - center.x_) * coefficient;
    leftBottom_.y_ = center.y_ + (leftBottom_.y_ - center.y_) * coefficient;
    side_ *= coefficient;
}
void Square::print() const
{
    Point center = getCenter();
    std::cout << "[" << getName() << ", ("
        << std::fixed << std::setprecision(2)
        << center.x_ << ", " << center.y_ << "), "
        << getArea() << "]";
}
