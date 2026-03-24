#ifndefCOMPOSITE_SHAPE_H
#defineCOMPOSITE_SHAPE_H

#include"shape.h"
#include<vector>
#include<memory>


classCompositeShape:publicShape
{
public:
//Добавлениефигуры
voidaddShape(std::unique_ptr<Shape>shape);

//Суммарнаяплощадь
doublegetArea()constoverride;

//Центрсоставнойфигуры
PointgetCenter()constoverride;

//Перемещениевсехфигур
voidmove(doubledx,doubledy)override;

//Масштабированиевсехфигур
voidscale(doublek)override;

//Название
constchar*getName()constoverride;

//Выводинформации
voidprintInfo()constoverride;

private:
std::vector<std::unique_ptr<Shape>>shapes_;

staticconstexprconstchar*NAME="COMPOSITE";
};

#endif
