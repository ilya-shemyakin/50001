#include <iostream>
#include <string>
#include "Point.h"
#include "DelimiterIO.h"

std::istream& operator>>(std::istream& in, Point& dest)
{
    using sep = DelimiterIO;
    int x = 0;
    int y = 0;

    in >> sep{ '(' };
    in >> x;
    in >> sep{ ';' };
    in >> y;
    in >> sep{ ')' };

    if (in) {
        dest.x = x;
        dest.y = y;
    }

    return in;
}
