#include "Polygon.h"


std::istream& operator>>(std::istream& in, Polygon& dest)
{
    size_t nPoints = 0;
    in >> nPoints;
    if (nPoints < 3) {
        in.setstate(std::ios::failbit);
        return in;
    }

    Polygon polygon;
    for (size_t i = 0; i < nPoints; ++i) {
        Point point;
        in >> point;
        polygon.points_.push_back(point);
    }

    in >> std::ws;
    if (!in.eof()) {
        in.setstate(std::ios::failbit);
        return in;
    }

    if (in) {
        dest = std::move(polygon);
    }

    return in;
}

double Polygon::getArea() const
{
    double area = 0.0;
    for (size_t i = 0; i < points_.size(); ++i) {
        area += 0.5 * (points_[i].x * points_[(i + 1) % points_.size()].y
            - points_[i].y * points_[(i + 1) % points_.size()].x);
    }
    return std::abs(area);
}
