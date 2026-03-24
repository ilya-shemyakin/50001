#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"shape.h"


class Rectangle:publicShape
{
public:
//Конструкторспараметрами
Rectangle(constPoint &lb,constPoint &rt);

//Площадьпрямоугольника
double getArea() const override;

//Центр—пересечениедиагоналей
Point getCenter() const override;

//Перемещениефигуры
void move(double dx,double dy) override;

//Масштабированиеотносительноцентра
void scale(double k) override;

//Названиефигуры
const char* getName() constoverride;

//Выводинформации
void printInfo() constoverride;

private:
Point lb_;//левыйнижнийугол
Point rt_;//правыйверхнийугол

static const expr constchar* NAME="RECTANGLE";
};

#endif
