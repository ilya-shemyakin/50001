#ifndef FUNCTIONS_H
#define FUNCTIONS_H
std::vector<Point> normalize(const Polygon& poly);
int rmecho(std::vector<Polygon>& polygons, const Polygon& target);
int same(const std::vector<Polygon>& polygons, const Polygon& target);
#endif /* FUNCTIONS_H */