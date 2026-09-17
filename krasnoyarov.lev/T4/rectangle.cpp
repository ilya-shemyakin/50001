#include "rectangle.h"

Rectangle::Rectangle(Point leftBottom, Point rightTop) : leftBottom_(leftBottom), rightTop_(rightTop) {
    if (leftBottom.x_ > rightTop.x_ || leftBottom.y_ > rightTop.y_)
    {
        throw std::invalid_argument("x and y must be closer to (0,0) coordinates than topright");
    }
}
double Rectangle::getArea() const
{
    double width = rightTop_.x_ - leftBottom_.x_;
    double height = rightTop_.y_ - leftBottom_.y_;
    return width * height;
}
Point Rectangle::getCenter() const
{
    double xCenter = (leftBottom_.x_ + rightTop_.x_) / 2;
    double yCenter = (rightTop_.y_ + leftBottom_.y_) / 2;
    return Point(xCenter, yCenter);
}
void Rectangle::move(double x, double y)
{
    rightTop_.x_ += x;
    rightTop_.y_ += y;
    leftBottom_.x_ += x;
    leftBottom_.y_ += y;
}
void Rectangle::scale(double coefficient)
{
    if (coefficient <= 0)
    {
        throw std::invalid_argument("coefficient");
    }
    Point center = getCenter();
    leftBottom_.x_ = center.x_ + (leftBottom_.x_ - center.x_) * coefficient;
    leftBottom_.y_ = center.y_ + (leftBottom_.y_ - center.y_) * coefficient;
    rightTop_.x_ = center.x_ + (rightTop_.x_ - center.x_) * coefficient;
    rightTop_.y_ = center.y_ + (rightTop_.y_ - center.y_) * coefficient;
}
const char* Rectangle::getName() const
{
    return "RECTANGLE";
}
void Rectangle::print() const
{
    Point center = getCenter();
    std::cout << "[" << getName() << ", ("
        << std::fixed << std::setprecision(2)
        << center.x_ << ", " << center.y_ << "), "
        << getArea() << "]";
}
