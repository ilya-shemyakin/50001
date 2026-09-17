#include "CompositeShape.h"
#include "rectangle.h"
#include "square.h"
#include <vector>
int main()
{
    try
    {
        std::unique_ptr<CompositeShape> c1 = std::make_unique<CompositeShape>();
        std::vector<std::unique_ptr<Shape>> figures;
        c1->add(std::make_unique<Square>(Point(4, 10), 5));
        c1->add(std::make_unique<Rectangle>(Point(3, 3), Point(5, 10)));
        c1->add(std::make_unique<Square>(Point(6, 21), 4));
        c1->add(std::make_unique<Rectangle>(Point(6, 2), Point(8, 11)));
        c1->add(std::make_unique<Square>(Point(10, 17), 6));
        std::unique_ptr<Rectangle> c2 = std::make_unique<Rectangle>(Point(3,3), Point(5,10));
        figures.push_back(std::move(c2));
        figures.push_back(std::move(c1));
        figures.push_back(std::make_unique<Square>(Point(3, 3), 5));
        for (auto& elements : figures)
        {
            elements->print();
        }
        for (auto& elements : figures)
        {
            elements->scale(5);
        }
        std::cout << "\nAfter scale:" << std::endl;
        for (auto& elements : figures)
        {
            elements->print();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}
