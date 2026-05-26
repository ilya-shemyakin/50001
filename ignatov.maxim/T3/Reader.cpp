#include "Reader.h"

void polygonReader(std::istream& in, std::vector<Polygon>& dest)
{
    std::vector<Polygon> polygons;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        Polygon poly;
        if (iss >> poly) {
            polygons.push_back(poly);
        }
    }

    dest = std::move(polygons);
}
