#include "figuresquare.h"

FigureSquare::FigureSquare(Board *pGameTablePtr)
 : Figure(pGameTablePtr), mode1(2,2)
{
	mode1.set_value(0,0);
	mode1.set_value(0,1);
	mode1.set_value(1,0);
	mode1.set_value(1,1);
	
	Validmode.push_back(&mode1);
	
	actualMode = 0;
}


FigureSquare::~FigureSquare()
{
}

