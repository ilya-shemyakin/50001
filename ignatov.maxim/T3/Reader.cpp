#include <iostream>
#include <vector>
#include <limits>
#include "Polygon.h"
#include "Reader.h"

void polygonReader(std::istream& in, std::vector<Polygon>& dest)
{
    std::vector<Polygon> polygons;
    while (!in.eof()) {
        Polygon polygon;
        in >> polygon;
        if (!polygon.points.empty()) {
            polygons.push_back(polygon);
        }

        if (in.fail() && !in.eof()) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
    }

    dest = std::move(polygons);
}
