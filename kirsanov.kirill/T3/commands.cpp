#include "commands.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace kirsanov
{
    // Сумма площадей фигур, удовлетворяющих предикату
    // Сначала вычисляем все площади
    double totalArea(const std::vector<Polygon>& polys, std::function<bool(const Polygon&)> pred)
    {
        std::vector<double> areas(polys.size());
        std::transform(polys.begin(), polys.end(), areas.begin(),
            [](const Polygon& p) { return p.area(); });

        double sum = 0.0;
        for (size_t i = 0; i < polys.size(); ++i)
        {
            if (pred(polys[i]))
                sum += areas[i];
        }
        return sum;
    }

    // Средняя арифметическая площадь
    double meanArea(const std::vector<Polygon>& polys)
    {
        if (polys.empty())
            throw std::runtime_error("No polygons");

        std::vector<double> areas(polys.size());
        std::transform(polys.begin(), polys.end(), areas.begin(),
            [](const Polygon& p) { return p.area(); });

        double sum = std::accumulate(areas.begin(), areas.end(), 0.0);
        return sum / polys.size();
    }

    // Максимальная площадь
    double maxArea(const std::vector<Polygon>& polys)
    {
        if (polys.empty())
            throw std::runtime_error("No polygons");

        std::vector<double> areas(polys.size());
        std::transform(polys.begin(), polys.end(), areas.begin(),
            [](const Polygon& p) { return p.area(); });

        return *std::max_element(areas.begin(), areas.end());
    }

    // Максимальное количество вершин
    size_t maxVertexes(const std::vector<Polygon>& polys)
    {
        if (polys.empty())
            throw std::runtime_error("No polygons");

        std::vector<size_t> verts(polys.size());
        std::transform(polys.begin(), polys.end(), verts.begin(),
            [](const Polygon& p) { return p.vertexCount(); });

        return *std::max_element(verts.begin(), verts.end());
    }

    // Минимальная площадь
    double minArea(const std::vector<Polygon>& polys)
    {
        if (polys.empty())
            throw std::runtime_error("No polygons");

        std::vector<double> areas(polys.size());
        std::transform(polys.begin(), polys.end(), areas.begin(),
            [](const Polygon& p) { return p.area(); });

        return *std::min_element(areas.begin(), areas.end());
    }

    // Минимальное количество вершин
    size_t minVertexes(const std::vector<Polygon>& polys)
    {
        if (polys.empty())
            throw std::runtime_error("No polygons");

        std::vector<size_t> verts(polys.size());
        std::transform(polys.begin(), polys.end(), verts.begin(),
            [](const Polygon& p) { return p.vertexCount(); });

        return *std::min_element(verts.begin(), verts.end());
    }

    // Обёртка над std::count_if — подсчёт по предикату
    size_t countPolygons(const std::vector<Polygon>& polys, std::function<bool(const Polygon&)> pred)
    {
        return std::count_if(polys.begin(), polys.end(), pred);
    }

    // PERMS: сколько фигур являются перестановкой target
    size_t countPerms(const std::vector<Polygon>& polys, const Polygon& target)
    {
        return std::count_if(polys.begin(), polys.end(),
            [&target](const Polygon& p) { return p.isPermutationOf(target); });
    }

    // RIGHTSHAPES: сколько фигур содержат прямой угол
    size_t countRightShapes(const std::vector<Polygon>& polys)
    {
        return std::count_if(polys.begin(), polys.end(),
            [](const Polygon& p) { return p.hasRightAngle(); });
    }
}
