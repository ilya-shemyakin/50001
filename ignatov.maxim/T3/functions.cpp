#include "functions.h"

std::vector<Point> normalize(const Polygon& poly) {
    if (poly.points_.empty()) return {};
    int minX = std::min_element(poly.points_.begin(), poly.points_.end(),
        [](const Point& a, const Point& b) { return a.x < b.x; })->x;
    int minY = std::min_element(poly.points_.begin(), poly.points_.end(),
        [](const Point& a, const Point& b) { return a.y < b.y; })->y;

    std::vector<Point> norm;
    norm.reserve(poly.points_.size());
    std::transform(poly.points_.begin(), poly.points_.end(), std::back_inserter(norm),
        [minX, minY](const Point& p) { return Point{ p.x - minX, p.y - minY }; });
    std::sort(norm.begin(), norm.end());
    return norm;
}

size_t rmecho(std::vector<Polygon>& polygons, const Polygon& target)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    auto it = std::unique(polygons.begin(), polygons.end(),
        [&target](const Polygon& a, const Polygon& b) {
            return a == target && b == target;
        });
    int removed = static_cast<int>(std::distance(it, polygons.end()));
    polygons.erase(it, polygons.end());
    return removed;
}

size_t same(const std::vector<Polygon>& polygons, const Polygon& target)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    auto targetNorm = normalize(target);
    return std::count_if(polygons.begin(), polygons.end(),
        [&targetNorm](const Polygon& p) {
            return normalize(p) == targetNorm;
        });
}

double areaEven(const std::vector<Polygon>& polygons)
{
    double totalSumm = 0.0;
    totalSumm = std::accumulate(polygons.begin(), polygons.end(), totalSumm,
        [](double summ, const Polygon& polygon) {
            if (polygon.points_.size() % 2 == 0) {
                return summ += polygon.getArea();
            }
            return summ;
        }
    );

    return totalSumm;
}

double areaOdd(const std::vector<Polygon>& polygons)
{
    double totalSumm = 0.0;
    totalSumm = std::accumulate(polygons.begin(), polygons.end(), totalSumm,
        [](double summ, const Polygon& polygon) {
            if (polygon.points_.size() % 2 == 1) {
                return summ += polygon.getArea();
            }
            return summ;
        }
    );

    return totalSumm;
}

double areaNVertexes(const std::vector<Polygon>& polygons, size_t nVertexes)
{
    double totalSumm = 0.0;
    totalSumm = std::accumulate(polygons.begin(), polygons.end(), totalSumm,
        [&nVertexes](double summ, const Polygon& polygon) {
            if (polygon.points_.size() == nVertexes) {
                return summ += polygon.getArea();
            }
            return summ;
        }
    );

    return totalSumm;
}

double areaMean(const std::vector<Polygon>& polygons)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    double totalSumm = 0.0;
    totalSumm = std::accumulate(polygons.begin(), polygons.end(), totalSumm,
        [](double summ, const Polygon& polygon) {
            return summ += polygon.getArea();
        }
    );

    return totalSumm / polygons.size();
}

double minArea(const std::vector<Polygon>& polygons)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    auto minPolygon = std::min_element(polygons.begin(), polygons.end(),
        [](const Polygon& thisP, const Polygon& otherP)
        { return thisP.getArea() < otherP.getArea(); });

    return minPolygon->getArea();
}

double maxArea(const std::vector<Polygon>& polygons)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    auto maxPolygon = std::max_element(polygons.begin(), polygons.end(),
        [](const Polygon& thisP, const Polygon& otherP)
        { return thisP.getArea() < otherP.getArea(); });

    return maxPolygon->getArea();
}

size_t minVertexes(const std::vector<Polygon>& polygons)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    auto minPolygon = std::min_element(polygons.begin(), polygons.end(),
        [](const Polygon& thisP, const Polygon& otherP)
        { return thisP.points_.size() < otherP.points_.size(); });

    return minPolygon->points_.size();
}

size_t maxVertexes(const std::vector<Polygon>& polygons)
{
    if (polygons.empty()) {
        throw std::runtime_error("ERROR: Empty polygons vector");
    }

    auto maxPolygon = std::max_element(polygons.begin(), polygons.end(),
        [](const Polygon& thisP, const Polygon& otherP)
        { return thisP.points_.size() < otherP.points_.size(); });

    return maxPolygon->points_.size();
}

size_t countEven(const std::vector<Polygon>& polygons)
{
    size_t count = std::count_if(polygons.begin(), polygons.end(),
        [](const Polygon& polygon)
        { return polygon.points_.size() % 2 == 0; });
    return count;
}

size_t countOdd(const std::vector<Polygon>& polygons)
{
    size_t count = std::count_if(polygons.begin(), polygons.end(),
        [](const Polygon& polygon)
        { return polygon.points_.size() % 2 == 1; });
    return count;
}

size_t countNVertexes(const std::vector<Polygon>& polygons, size_t nVertexes)
{
    size_t count = std::count_if(polygons.begin(), polygons.end(),
        [&nVertexes](const Polygon& polygon)
        { return polygon.points_.size() == nVertexes; });
    return count;
}
