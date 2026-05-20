#ifndef POINT_H
#define POINT_H
#include <iostream>

struct Point
{
    int x = 0;
    int y = 0;
    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
    bool operator<(const Point& other) const
    {
        return x < other.x || (x == other.x && y < other.y
            );
    }
};

std::istream& operator>>(std::istream& in, Point& dest);
#endif /* POINT_H */
