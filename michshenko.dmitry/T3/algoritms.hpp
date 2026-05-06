#ifndef ALGORIMS_HPP
#define ALGORIMS_HPP

#include <vector>
#include <string>

#include "Polygon.hpp"

// методы
double areaPolygons (const std::vector<Point>& points);
double areaEvenOdd(const std::string& value, const std::vector<Polygon>& pols);
double areaMean(const std::vector<Polygon>& pols);
double areaNum(int value, const std::vector<Polygon>& pols);
double maxAreaVertex(const std::string& value, const std::vector<Polygon>& pols);
double minAreaVertex(const std::string& value, const std::vector<Polygon>& pols);
int countVertexOddNum(const std::string& value, const std::vector<Polygon>& pols);
int countVertexOddNum(const size_t& value, const std::vector<Polygon>& pols);

// компораторы
bool VertexComparator(const Polygon& firstPol, const Polygon& secondPol);
bool AreaComparator(const Polygon& firstPol, const Polygon& secondPol);

// методы варианта

// Получение bounding box многоугольника
BoundingBox getBoundingBox(const Polygon& poly);

// Получение общего bounding box для всей коллекции
BoundingBox getOverallBoundingBox(const std::vector<Polygon>& pols);

// возврат левой границы
double getMinX(const BoundingBox& box);

// возврат нижней границы
double getMinY(const BoundingBox& box);

// возврат правой границы
double getMaxX(const BoundingBox& box);

// возврат верхней границы
double getMaxY(const BoundingBox& box);

// a >= b
bool isEqual(double a, double b);

// a <= b
bool isLessEqual(double a, double b);

// проверка на принадлежность фигуры целиком в прямоугольнике
bool isInframe(const Polygon& pol, const std::vector<Polygon>& pols);

//2

// сравнение многоугольников
bool isPolygonsEqual(const Polygon& a, const Polygon& b);

// максимальная последовательность одинаковых фигур
int maxSeq(const std::vector<Polygon>& pols, const Polygon& target);

#endif
