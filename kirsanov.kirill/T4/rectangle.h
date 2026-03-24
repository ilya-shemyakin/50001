#ifndefRECTANGLE_H
#defineRECTANGLE_H

#include"shape.h"


classRectangle:publicShape
{
public:
//Конструкторспараметрами
Rectangle(constPoint&lb,constPoint&rt);

//Площадьпрямоугольника
doublegetArea()constoverride;

//Центр—пересечениедиагоналей
PointgetCenter()constoverride;

//Перемещениефигуры
voidmove(doubledx,doubledy)override;

//Масштабированиеотносительноцентра
voidscale(doublek)override;

//Названиефигуры
constchar*getName()constoverride;

//Выводинформации
voidprintInfo()constoverride;

private:
Pointlb_;//левыйнижнийугол
Pointrt_;//правыйверхнийугол

staticconstexprconstchar*NAME="RECTANGLE";
};

#endif
