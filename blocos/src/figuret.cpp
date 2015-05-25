#include "figuret.h"

FigureT::FigureT(Board *pGameTablePtr)
 : Figure(pGameTablePtr), mode1(2,3), mode2(3,2), mode3(2,3), mode4(3,2)
{
	mode1.set_value(1,0);
	mode1.set_value(1,1);
	mode1.set_value(1,2);
	mode1.set_value(0,1);
	
	mode2.set_value(0,0);
	mode2.set_value(1,0);
	mode2.set_value(2,0);
	mode2.set_value(1,1);
	
	mode3.set_value(0,0);
	mode3.set_value(0,1);
	mode3.set_value(0,2);
	mode3.set_value(1,1);
	
	mode4.set_value(0,1);
	mode4.set_value(1,1);
	mode4.set_value(2,1);
	mode4.set_value(1,0);
	
	Validmode.push_back(&mode1);
	Validmode.push_back(&mode2);
	Validmode.push_back(&mode3);
	Validmode.push_back(&mode4);
	
	actualMode = 0;
}


FigureT::~FigureT()
{
}

