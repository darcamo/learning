#include "figure.h"

Figure::Figure(Board *pGameTablePtr)
{
	gameTablePtr = pGameTablePtr;
	rowInt = 0;
	colInt = 0;
	prevTicksInt = SDL_GetTicks();
}


Figure::~Figure()
{
}


bool Figure::draw(bool mark)
{
	if(mark == false)
	{
		for(int i = 0; i < Validmode[actualMode]->get_nRows()/*bound_box_y*/; i++)
		{
			for(int k = 0; k < Validmode[actualMode]->get_nCols()/*bound_box_x*/; k++)
			{
				if(Validmode[actualMode]->get_value(i,k) == true)
				{
					gameTablePtr->set_value(i+rowInt,k+colInt,false);
				}
			}
		}
	}
	else
	{
		if(detect_collision() == true)
		{
			return true;
		}
		else
		{
			for(int i = 0; i < Validmode[actualMode]->get_nRows()/*bound_box_y*/; i++)
			{
				for(int k = 0; k < Validmode[actualMode]->get_nCols()/*bound_box_x*/; k++)
				{
					if(Validmode[actualMode]->get_value(i,k) == true)
					{
						gameTablePtr->set_value(i+rowInt,k+colInt,true);
					}
				}
			}
		}
	}
	return false;
}



void Figure::set_position(int pRowInt, int pColInt)
{
	assert(pRowInt < VALID_SCREEN_HEIGHT && pColInt < VALID_SCREEN_WIDTH);
	rowInt = pRowInt;
	colInt = pColInt;
}


bool Figure::move_left()
{
	draw(false);
	colInt--;
	if(detect_collision())
	{
		colInt++;
		draw();
		return true;
	}
	draw();
	return false;
}


bool Figure::move_right()
{
	draw(false);
	colInt++;
	if(detect_collision())
	{
		colInt--;
		draw();
		return true;
	}
	draw();
	return false;
}


bool Figure::move_down()
{
	draw(false);
	rowInt++;
	if(detect_collision())
	{
		rowInt--;
		draw();
		return true;
	}
	draw();
	return false;
}


bool Figure::move_up()
{
	draw(false);
	rowInt--;
	if(detect_collision())
	{
		rowInt++;
		draw();
		return true;
	}
	draw();
	return false;
}


bool Figure::detect_collision()
{
	bool collision_detected = false;
	for(int i = 0; i < Validmode[actualMode]->get_nRows()/* bound_box_y*/; i++)
	{
		for(int k = 0; k < Validmode[actualMode]->get_nCols()/*bound_box_x*/; k++)
		{
			if( (i+rowInt >= VALID_SCREEN_HEIGHT) || // testa colisão com chão
			(k+colInt >= VALID_SCREEN_WIDTH) || // com parede direita
			(k+colInt < 0) || // com parede esquerda
			(rowInt)<0) // com o teto
			{
				collision_detected = true;
			}
			else
				if(gameTablePtr->get_value(i+rowInt,k+colInt) == true && Validmode[actualMode]->get_value(i,k) == true) //testa colisão com blocos)
				{
					collision_detected = true;
				}
		}
	}
	return collision_detected;
}



bool Figure::change_right()
{
	///@todo Check se tudo está funcionando direito. Talvez quando haja colisão ele mude o actualmode (embora a mudança não apareça na tela), mas isso não deve ser feito.
	int curTicksInt = SDL_GetTicks();
	if(curTicksInt - prevTicksInt > 100)
	{
		prevTicksInt = curTicksInt;
	
		draw(false);
		actualMode = (actualMode+1)%Validmode.size();
		if(detect_collision())
		{
			actualMode = (actualMode+1)%Validmode.size();
			draw();
			return true;
		}
		draw();
	}
	return false;
}


Board* Figure::get_figureGrid()
{
	return Validmode[actualMode];
}


