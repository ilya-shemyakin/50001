#include <algorithm>
#include <vector>
#include <iterator>
#include "Polygon.h"
#include "functions.h"

std::vector<Point> normalize(const Polygon& poly) {
    if (poly.points.empty()) return {};
    auto minX = std::min_element(poly.points.begin(), poly.points.end(),
        [](const Point& a, const Point& b) { return a.x < b.x; })->x;
    auto minY = std::min_element(poly.points.begin(), poly.points.end(),
        [](const Point& a, const Point& b) { return a.y < b.y; })->y;

    std::vector<Point> norm;
    norm.reserve(poly.points.size());
    std::transform(poly.points.begin(), poly.points.end(), std::back_inserter(norm),
        [minX, minY](const Point& p) { return Point{ p.x - minX, p.y - minY }; });
    std::sort(norm.begin(), norm.end());
    return norm;
}

int rmecho(std::vector<Polygon>& polygons, const Polygon& target) {
    auto it = std::unique(polygons.begin(), polygons.end(),
        [&target](const Polygon& a, const Polygon& b) {
            return a == target && b == target;
        });
    int removed = static_cast<int>(std::distance(it, polygons.end()));
    polygons.erase(it, polygons.end());
    return removed;
}

int same(const std::vector<Polygon>& polygons, const Polygon& target) {
    auto targetNorm = normalize(target);
    return std::count_if(polygons.begin(), polygons.end(),
        [&targetNorm](const Polygon& p) {
            return normalize(p) == targetNorm;
        });
}
