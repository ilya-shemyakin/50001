#ifndefSHAPE_H
#defineSHAPE_H

#include"point.h"

//Базовыйклассдлявсехгеометрическихфигур
classShape
{
public:
virtual~Shape()=default;//виртуальныйдеструктор

//Вычислениеплощадифигуры
virtualdoublegetArea()const=0;

//Получениецентрафигуры
virtualPointgetCenter()const=0;

//Перемещениефигурынаdxиdy
virtualvoidmove(doubledx,doubledy)=0;

//Масштабированиеотносительноцентра
virtualvoidscale(doublek)=0;

//Получениеназванияфигуры
virtualconstchar*getName()const=0;

//Выводинформацииофигуре
virtualvoidprintInfo()const=0;
};

#endif
