#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "polygon.h"
#include <vector>
#include <functional>

namespace kirsanov
{
    // AREA команды
    double totalArea(const std::vector<Polygon>& polys, std::function<bool(const Polygon&)> pred);
    double meanArea(const std::vector<Polygon>& polys);

    // MAX/MIN команды
    double maxArea(const std::vector<Polygon>& polys);
    size_t maxVertexes(const std::vector<Polygon>& polys);
    double minArea(const std::vector<Polygon>& polys);
    size_t minVertexes(const std::vector<Polygon>& polys);

    // COUNT команды
    size_t countPolygons(const std::vector<Polygon>& polys, std::function<bool(const Polygon&)> pred);

    // PERMS команда
    size_t countPerms(const std::vector<Polygon>& polys, const Polygon& target);

    // RIGHTSHAPES команда
    size_t countRightShapes(const std::vector<Polygon>& polys);
}

#endif
