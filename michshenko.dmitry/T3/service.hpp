#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "Polygon.hpp"
#include <sstream>

// отладка
void invalComm();
bool isEmpty(std::vector<Polygon>& polys);

// перегрузки выводов
std::istream& operator>>(std::istream& in, Point& p);
std::istream& operator>>(std::istream& in, Polygon& poly);

#endif
