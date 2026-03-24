#ifndef SHAPE_H
#define  SHAPE_H

#include "point.h"

//Базовыйклассдлявсехгеометрическихфигур
class Shape
{
public:
virtual ~Shape() = default;//виртуальныйдеструктор

//Вычислениеплощадифигуры
virtual double getArea() const = 0;

//Получениецентрафигуры
virtual Point getCenter() const = 0;

//Перемещениефигурынаdxиdy
virtual void move(double dx,double dy) = 0;

//Масштабированиеотносительноцентра
virtual void scale(double k) = 0;

//Получениеназванияфигуры
virtual constchar* getName() const = 0;

//Выводинформацииофигуре
virtual void printInfo() const=0;
};

#endif
