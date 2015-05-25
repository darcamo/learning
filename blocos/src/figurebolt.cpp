#include "figurebolt.h"

FigureBolt::FigureBolt(Board *pGameTablePtr)
 : Figure(pGameTablePtr), mode1(3,2), mode2(2,3)
{
	mode1.set_value(0,0);
	mode1.set_value(1,0);
	mode1.set_value(1,1);
	mode1.set_value(2,1);
	
	mode2.set_value(0,1);
	mode2.set_value(0,2);
	mode2.set_value(1,0);
	mode2.set_value(1,1);

	Validmode.push_back(&mode1);
	Validmode.push_back(&mode2);
	
	actualMode = 0;
}


FigureBolt::~FigureBolt()
{
}

