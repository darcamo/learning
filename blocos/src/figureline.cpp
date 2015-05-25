#include "figureline.h"

FigureLine::FigureLine(Board *pGameTablePtr)
 : Figure(pGameTablePtr), mode1(4,1), mode2(1,4)
{
	mode1.set_value(0,0);
	mode1.set_value(1,0);
	mode1.set_value(2,0);
	mode1.set_value(3,0);
	
	mode2.set_value(0,0);
	mode2.set_value(0,1);
	mode2.set_value(0,2);
	mode2.set_value(0,3);
	
	Validmode.push_back(&mode1);
	Validmode.push_back(&mode2);
	
	actualMode = 0;
}


FigureLine::~FigureLine()
{
}

