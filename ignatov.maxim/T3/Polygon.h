#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "Point.h"

struct Polygon
{
	std::vector<Point> points;
	bool operator==(const Polygon& other) const { return points == other.points; }
};

std::istream& operator>>(std::istream& in, Polygon& dest);
#endif /* POLYGON_H */
