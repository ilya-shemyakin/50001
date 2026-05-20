#include <iostream>
#include "Polygon.h"


std::istream& operator>>(std::istream& in, Polygon& dest)
{
    size_t nPoints = 0;
    in >> nPoints;

    Polygon polygon;
    for (size_t i = 0; i < nPoints; ++i) {
        Point point;
        in >> point;
        polygon.points.push_back(point);
    }

    if (in) {
        dest = std::move(polygon);
    }

    return in;
}
