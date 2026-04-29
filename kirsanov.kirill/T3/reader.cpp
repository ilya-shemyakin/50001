#include "reader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstddef>

namespace kirsanov
{
    std::vector<Polygon> readPolygons(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
            throw std::runtime_error("Cannot open file");

        std::vector<Polygon> polygons;
        std::string line;

        // Читаем файл построчно
        while (std::getline(file, line))
        {
            if (line.empty())
                continue;  // пропускаем пустые строки

            std::istringstream iss(line);
            int n;
            iss >> n;  // читаем количество вершин

            if (iss.fail() || n < 3)
                continue;  // некорректное количество вершин — игнорируем

            Polygon poly; //временный объект для сбора вершин
            bool valid = true;

            // Читаем n точек в формате (x;y)
            for (int i = 0; i < n; ++i)
            {
                char c1, c2, c3;
                int x, y;
                iss >> c1 >> x >> c2 >> y >> c3;

                // Проверяем формат
                if (iss.fail() || c1 != '(' || c2 != ';' || c3 != ')')
                {
                    valid = false;
                    break;
                }

                poly.points.push_back({ x, y });
            }

            if (valid && poly.points.size() == static_cast<size_t>(n)) {
                // Проверяем, что после последней точки нет лишних символов
                char leftover;
                if (!(iss >> leftover))
                {
                    polygons.push_back(poly);
                }
                // Если есть leftover — пропускаем строку
            }
        }

        return polygons;
    }
}
