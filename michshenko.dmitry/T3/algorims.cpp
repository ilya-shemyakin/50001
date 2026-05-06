#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

#include "algoritms.hpp"
#include "service.hpp"

/* КОМПОРАТОРЫ */

// для площадей
bool AreaComparator (const Polygon& firstPol, const Polygon& secondPol) {
    return areaPolygons(firstPol.points) < areaPolygons(secondPol.points);
}

// для вершин
bool VertexComparator (const Polygon& firstPol, const Polygon& secondPol) {
    return firstPol.points.size() < secondPol.points.size();
}

/* МЕТОДЫ */

// вычисление площади фигуры (метод Гаусса)
double areaPolygons (const std::vector<Point>& points) {
    if (points.size() <= 2) {
        return 0.0;
    }

    return std::abs(std::accumulate(
        points.begin(), points.end(), 0.0,
        [&](double sum, const Point& current) {
            size_t next = (&current - &points[0] + 1) % points.size();
            return sum + (current.x * points[next].y - points[next].x * current.y); }
    )) /2 ; // 2
}

// Вычисление площади чётной/нечётной фигуры
double areaEvenOdd(const std::string& value, const std::vector<Polygon>& pols) {

    return std::abs(accumulate(
        pols.begin(), pols.end(), 0.0,
        [&](double sum, const Polygon& current) {
            if ((current.points.size() % 2== 0) == (value == "EVEN")) {
                return sum + areaPolygons(current.points);
            }
            else {
                return sum;
            }
        }
    ));
}

// Вычисление средней площади фигур
double areaMean(const std::vector<Polygon>& pols) {
    return std::accumulate(
        pols.begin(), pols.end(), 0.0,
        [](double sum, const Polygon& current) {
            return sum + areaPolygons(current.points);
        }
    ) / static_cast<double>(pols.size());

}

// Расчёт суммы площади фигур с заданным количеством вершин
double areaNum(int value, const std::vector<Polygon>&  pols) {
    return std::accumulate(
        pols.begin(), pols.end(), 0.0,
        [&](double sum, const Polygon& current) {
            if (current.points.size() == value) {
                return sum + areaPolygons(current.points);
            }
            return sum;
        }
    );
}

// Расчёт максимального значения площади или количества вершин
double maxAreaVertex(const std::string& value, const std::vector<Polygon>& pols) {
    if (value == "AREA") {
        auto max = std::max_element(pols.begin(), pols.end(), AreaComparator);
        return areaPolygons(max->points);
    }
    if (value == "VERTEXES") {
        auto max = std::max_element(pols.begin(), pols.end(), VertexComparator);
        return static_cast<double>(max->points.size());
    }
    return 0.0;
}

// Расчёт минимального значения площади или количества вершин
double minAreaVertex(const std::string& value, const std::vector<Polygon>& pols) {
    if (value == "AREA") {
        auto min = std::min_element(pols.begin(), pols.end(), AreaComparator);
        return areaPolygons(min->points);
    }
    if (value == "VERTEXES") {
        auto min = std::min_element(pols.begin(), pols.end(), VertexComparator);
        return static_cast<double>(min->points.size());
    }
    return 0.0;
}

//  Подсчёт количества фигур с нечётным, чётным количеством вершин
int countVertexOddNum(const std::string& value, const std::vector<Polygon>& pols) {
    return std::count_if(pols.begin(), pols.end(), [&](const Polygon& current) {
            if (value == "EVEN") {
                return current.points.size() % 2 == 0;
            }
            return !(current.points.size() % 2 == 0);
        }
    );
}

//  Подсчёт количества фигур c конкретным количеством вершин
int countVertexOddNum(const size_t& value, const std::vector<Polygon>& pols) {
    if (value <= 2) {
        invalComm();
        return -1;
    }

    return std::count_if(pols.begin(), pols.end(),
        [&](const Polygon& current) {
            return current.points.size() == value;
        }
    );
}

/* ВАРИАНТ */

// Получение bounding box многоугольника
BoundingBox getBoundingBox(const Polygon& poly) {
    if (poly.points.empty()) {
        return {0, 0, 0, 0};
    }

    // поиск минимального и максимального x и y
    auto minX = std::min_element(poly.points.begin(), poly.points.end(),
        [](const Point& a, const Point& b) { return a.x < b.x; });
    auto maxX = std::max_element(poly.points.begin(), poly.points.end(),
        [](const Point& a, const Point& b) { return a.x < b.x; });
    auto minY = std::min_element(poly.points.begin(), poly.points.end(),
        [](const Point& a, const Point& b) { return a.y < b.y; });
    auto maxY = std::max_element(poly.points.begin(), poly.points.end(),
        [](const Point& a, const Point& b) { return a.y < b.y; });

    return {static_cast<double>(minX->x), static_cast<double>(minY->y),
        static_cast<double>(maxX->x), static_cast<double>(maxY->y) };
}

// Получение общего bounding box для всей коллекции
BoundingBox getOverallBoundingBox(const std::vector<Polygon>& pols) {
    if (pols.empty()) {
        return {0, 0, 0, 0};
    }

    //
    std::vector<BoundingBox> boxes(pols.size());
    std::transform(pols.begin(), pols.end(), boxes.begin(),
        [](const Polygon& p) { return getBoundingBox(p); });

    //среди фигур ищем с наименьшим/наибольшим значением
    auto minX = std::min_element(boxes.begin(), boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) { return a.minX < b.minX; });
    auto minY = std::min_element(boxes.begin(), boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) { return a.minY < b.minY; });
    auto maxX = std::max_element(boxes.begin(), boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) { return a.maxX < b.maxX; });
    auto maxY = std::max_element(boxes.begin(), boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) { return a.maxY < b.maxY; });

    return {minX->minX, minY->minY, maxX->maxX, maxY->maxY};
}


//вспомогательные функции
double getMinX(const BoundingBox& box)
{
    return box.minX;
}

double getMinY(const BoundingBox& box)
{
    return box.minY;
}

double getMaxX(const BoundingBox& box)
{
    return box.maxX;
}

double getMaxY(const BoundingBox& box)
{
    return box.maxY;
}

bool isEqual(double a, double b)
{
    return a >= b;
}

bool isLessEqual(double a, double b)
{
    return a <= b;
}

// основная функция isInframe
bool isInframe(const Polygon& pol, const std::vector<Polygon>& pols) {

    if (pols.empty()) {
        return false;
    }

    //  общий bounding box коллекции
    BoundingBox overallBB = getOverallBoundingBox(pols);

    //  bounding box проверяемой фигуры
    BoundingBox testBB = getBoundingBox(pol);

    // проверки через bind
    auto checkMinX = std::bind(
        isEqual, std::bind(getMinX, std::cref(testBB)), std::bind(getMinX, std::cref(overallBB)));

    auto checkMaxX = std::bind(
        isLessEqual, std::bind(getMaxX, std::cref(testBB)), std::bind(getMaxX, std::cref(overallBB)));

    auto checkMinY = std::bind(
        isEqual, std::bind(getMinY, std::cref(testBB)), std::bind(getMinY, std::cref(overallBB)));

    auto checkMaxY = std::bind(
        isLessEqual, std::bind(getMaxY, std::cref(testBB)), std::bind(getMaxY, std::cref(overallBB)));

    // Комбинация всех проверок
    auto checkX = std::bind(std::logical_and<bool>(), checkMinX, checkMaxX);
    auto checkY = std::bind(std::logical_and<bool>(), checkMinY, checkMaxY);
    auto result = std::bind(std::logical_and<bool>(), checkX, checkY);

    return result();
}


// сравнение многоугольников
bool isPolygonsEqual(const Polygon& a, const Polygon& b) {
    if (a.points.size() != b.points.size()) {
        return false;
    }

    // Лямбда для сравнения двух точек
    auto pointsEqual = [](const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    };

    // Поиск циклического сдвига с предикатом
    auto it = std::search(
        a.points.begin(), a.points.end(),
        b.points.begin(), b.points.end(),
        pointsEqual);

    if (it != a.points.end()) {
        // Явно указываем итераторы и предикат
        auto bEnd = b.points.end();
        auto offset = std::distance(a.points.begin(), it);

        return std::equal(
            a.points.begin(), it,
            bEnd - offset,
            bEnd,
            pointsEqual);
    }

    // Проверка обратного порядка
    Polygon reversed = b;
    std::reverse(reversed.points.begin(), reversed.points.end());

    return std::equal(
        a.points.begin(), a.points.end(),
        reversed.points.begin(), reversed.points.end(),
        pointsEqual);
}

//
int maxSeq(const std::vector<Polygon>& pols, const Polygon& target) {

    struct State {
        int currentLen;
        int maxLen;
    };

    State result = std::accumulate(
        pols.begin(), pols.end(), State{0, 0},
        [&](State state, const Polygon& current) {
            if (isPolygonsEqual(current, target)) {
                state.currentLen++;
                state.maxLen = std::max(state.maxLen, state.currentLen);
            }
            else {
                state.currentLen = 0;
            }
            return state;
        });

    return result.maxLen;
}
