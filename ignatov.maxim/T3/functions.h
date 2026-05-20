#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include "Polygon.h"

std::vector<Point> normalize(const Polygon& poly);
size_t rmecho(std::vector<Polygon>& polygons, const Polygon& target);
size_t same(const std::vector<Polygon>& polygons, const Polygon& target);
#endif /* FUNCTIONS_H */
