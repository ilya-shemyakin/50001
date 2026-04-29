#include "polygon.h"
#include <cmath>
#include <algorithm>
#include <cstddef>

namespace kirsanov
{
    // Сравнение двух точек по координатам
    bool Point::operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    bool Point::operator!=(const Point& other) const
    {
        return !(*this == other);
    }

    // Сравнение двух многоугольников
    // проверяем одинаковые вершины в одинаковом порядке
    bool Polygon::operator==(const Polygon& other) const
    {
        if (points.size() != other.points.size())
            return false;
        return points == other.points;
    }

    bool Polygon::operator!=(const Polygon& other) const
    {
        return !(*this == other);
    }

    // Возвращает количество вершин многоугольника
    size_t Polygon::vertexCount() const
    {
        return points.size();
    }

    // Площадь по формуле Гаусса (шнурков)
    double Polygon::area() const
    {
        if (points.size() < 3)  // минимально возможное количество вершин
            return 0.0;

        double s = 0.0;
        for (size_t i = 0; i < points.size(); ++i)
        {
            const Point& p1 = points[i];
            // замыкаем на первую точку
            const Point& p2 = points[(i + 1) % points.size()];
            s += static_cast<double>(p1.x * p2.y - p2.x * p1.y);
        }
        return std::abs(s) / 2.0;
    }

    // Проверяем, является ли другой многоугольник перестановкой вершин текущего
    // Для этого сортируем вершины (по x, потом по y) и сравниваем
    bool Polygon::isPermutationOf(const Polygon& other) const
    {
        if (points.size() != other.points.size())
            return false;

        auto sorted1 = points;
        auto sorted2 = other.points;

        // Лямбда для сравнения точек: сначала по x, потом по y
        auto compare = [](const Point& a, const Point& b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
            };

        std::sort(sorted1.begin(), sorted1.end(), compare);
        std::sort(sorted2.begin(), sorted2.end(), compare);

        return sorted1 == sorted2;
    }

    // Проверяем, есть ли в многоугольнике хотя бы один прямой угол
    bool Polygon::hasRightAngle() const
    {
        if (points.size() < 3)
            return false;

        for (size_t i = 0; i < points.size(); ++i)
        {
            const Point& a = points[i];                     // предыдущая вершина
            const Point& b = points[(i + 1) % points.size()]; // вершина угла
            const Point& c = points[(i + 2) % points.size()]; // следующая вершина

            // Векторы: ab и bc
            int dx1 = b.x - a.x;
            int dy1 = b.y - a.y;
            int dx2 = c.x - b.x;
            int dy2 = c.y - b.y;

            // Скалярное произведение == 0, тогда прямой угол
            if (dx1 * dx2 + dy1 * dy2 == 0)
                return true;
        }
        return false;
    }
}
