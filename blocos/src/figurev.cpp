#include "figurev.h"

FigureV::FigureV(Board *pGameTablePtr)
 : Figure(pGameTablePtr), mode1(2,2), mode2(2,2), mode3(2,2), mode4(2,2)
{
	mode1.set_value(0,0);
	mode1.set_value(1,0);
	mode1.set_value(0,1);
	
	mode2.set_value(0,0);
	mode2.set_value(0,1);
	mode2.set_value(1,1);
	
	mode3.set_value(0,1);
	mode3.set_value(1,1);
	mode3.set_value(1,0);
	
	mode4.set_value(0,0);
	mode4.set_value(1,0);
	mode4.set_value(1,1);
	
	Validmode.push_back(&mode1);
	Validmode.push_back(&mode2);
	Validmode.push_back(&mode3);
	Validmode.push_back(&mode4);
	
	actualMode = 0;
}


FigureV::~FigureV()
{
}


