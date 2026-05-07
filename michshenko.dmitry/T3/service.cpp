#include <iostream>
#include <limits>

#include "Polygon.hpp"
#include "service.hpp"

// отладка
void invalComm() {
    std::cout<<"<INVALID COMMAND>"<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isEmpty(std::vector<Polygon>& polys) {
    return polys.size() == 0;
}

// перегрузки выводов
std::istream& operator>>(std::istream& in, Point& point) {
    char value;
    if (in >> value && value == '(' && in >> point.x >>value &&
       value == ';'  && in >> point.y >> value && value == ')' ) {
        return in;
    }
    in.setstate(std::ios::failbit);
    return in;
}

std::istream& operator>>(std::istream& in, Polygon& pol) {
    size_t count = 0;
    pol.points.clear();

    if (!(in >> count) || (count <= 2)) {
        in.setstate(std::ios::failbit);
        return in;
    }

    for (size_t i = 0; i < count; ++i) {
        Point p;
        if (!(in >> p)) {
            in.setstate(std::ios::failbit);
            return in;
        }
        pol.points.push_back(p);
    }

    char nextChar;
    if (in >> nextChar) {
        in.setstate(std::ios::failbit);
    }

    return in;
}
