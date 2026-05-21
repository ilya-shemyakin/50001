#ifndef ALGORIMS_HPP
#define ALGORIMS_HPP

#include <vector>
#include <string>

#include "Polygon.hpp"

// методы
double areaEvenOdd(const std::string& value, const std::vector<Polygon>& pols);
double areaMean(const std::vector<Polygon>& pols);
double areaNum(int value, const std::vector<Polygon>& pols);
double maxAreaVertex(const std::string& value, const std::vector<Polygon>& pols);
double minAreaVertex(const std::string& value, const std::vector<Polygon>& pols);
int countVertexOddNum(const std::string& value, const std::vector<Polygon>& pols);
int countVertexOddNum(const size_t& value, const std::vector<Polygon>& pols);

// проверка на принадлежность фигуры целиком в прямоугольнике
bool isInframe(const Polygon& pol, const std::vector<Polygon>& pols);

// максимальная последовательность одинаковых фигур
int maxSeq(const std::vector<Polygon>& pols, const Polygon& target);

#endif
