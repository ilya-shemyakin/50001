#ifndefCOMPOSITE_SHAPE_H
#defineCOMPOSITE_SHAPE_H

#include"shape.h"
#include<vector>
#include<memory>


classCompositeShape:publicShape
{
public:
//Добавлениефигуры
void addShape(std::unique_ptr<Shape>shape);

//Суммарнаяплощадь
double getArea() const override;

//Центрсоставнойфигуры
Point getCenter() const override;

//Перемещениевсехфигур
void move(doubledx,doubledy)override;

//Масштабированиевсехфигур
void scale(doublek)override;

//Название
const char* getName()constoverride;

//Выводинформации
void printInfo()constoverride;

private:
std::vector<std::unique_ptr<Shape>>shapes_;

static const expr const char* NAME="COMPOSITE";
};

#endif
