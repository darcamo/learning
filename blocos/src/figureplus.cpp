#include "figureplus.h"

FigurePlus::FigurePlus(Board *pGameTablePtr)
 : Figure(pGameTablePtr), mode1(3,3)
{
	mode1.set_value(0,1);
	mode1.set_value(1,0);
	mode1.set_value(1,1);
	mode1.set_value(1,2);
	mode1.set_value(2,1);
	
	Validmode.push_back(&mode1);
	
	actualMode = 0;
}


FigurePlus::~FigurePlus()
{
}


