#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <cctype>
#include <stdexcept>
#include "Polygon.h"

std::vector<Point> normalize(const Polygon& poly);
size_t rmecho(std::vector<Polygon>& polygons, const Polygon& target);
size_t same(const std::vector<Polygon>& polygons, const Polygon& target);
double areaEven(const std::vector<Polygon>& polygons);
double areaOdd(const std::vector<Polygon>& polygons);
double areaNVertexes(const std::vector<Polygon>& polygons, size_t nVertexes);
double areaMean(const std::vector<Polygon>& polygons);
double minArea(const std::vector<Polygon>& polygons);
double maxArea(const std::vector<Polygon>& polygons);
size_t minVertexes(const std::vector<Polygon>& polygons);
size_t maxVertexes(const std::vector<Polygon>& polygons);
size_t countEven(const std::vector<Polygon>& polygons);
size_t countOdd(const std::vector<Polygon>& polygons);
size_t countNVertexes(const std::vector<Polygon>& polygons, size_t nVertexes);
#endif /* FUNCTIONS_H */
