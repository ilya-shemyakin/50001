#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include "Point.h"

struct Polygon
{
    std::vector<Point> points_;
    bool operator==(const Polygon& other) const { return points_ == other.points_; }
    double getArea() const;
};

std::istream& operator>>(std::istream& in, Polygon& dest);
#endif /* POLYGON_H */
