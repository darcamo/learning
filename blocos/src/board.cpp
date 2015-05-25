#include "board.h"

Board::Board(int pNRowInt, int pNColInt)
{
	resize_board(pNRowInt,pNColInt);
}


Board::~Board()
{
}


void Board::resize_board(int pNRowInt, int pNColInt)
{
	nRowInt = pNRowInt;
	nColInt = pNColInt;
	boardMap.resize(pNRowInt*pNColInt);
	clear_board();
}



void Board::clear_board()
{
	for(int i = 0; i < nRowInt; i++)
	{
		for(int k =0; k < nColInt; k++)
		{
			set_value(i,k,false);
		}
	}
}


void Board::set_value(int pRowInt, int pColInt, bool pValueBool)
{
	assert(pRowInt < nRowInt);
	assert(pColInt < nColInt);
	boardMap[pRowInt * nColInt + pColInt] = pValueBool;
}


bool Board::get_value(int pRowInt, int pColInt)
{
	assert(pRowInt < nRowInt);
	assert(pColInt < nColInt);
	return boardMap[pRowInt * nColInt + pColInt]; 
}


void Board::set_line(int pRowInt, bool pValueBool)
{
	for(int k = 0; k < nColInt; k++)
	{
		set_value(pRowInt, k, pValueBool);
	}
}


bool Board::is_line_set(int pRowInt)
{
	for(int k = 0; k < nColInt; k++)
	{
		if(boardMap[pRowInt * nColInt + k] == false)
		{
			return false;
		}
	}
	return true;
}


int Board::get_nCols()
{
	return nColInt;
}


int Board::get_nRows()
{
	return nRowInt;
}


void Board::delete_line(int pRowInt)
{
	for(int i = pRowInt; i > 0; i--)
	{
		set_line(i, get_line(i-1));
	}
	set_line(0,false);
}


void Board::set_line(int pRowInt, std::vector<bool> pLineVec)
{
	assert(pLineVec.size() == nColInt);
	for(int k = 0; k < nColInt; k++)
	{
		set_value(pRowInt, k, pLineVec[k]);
	}
}


std::vector<bool> Board::get_line(int pRowInt)
{
	std::vector<bool> lineVec(nColInt);
	for(int k = 0; k < nColInt; k++)
	{
		lineVec[k] = get_value(pRowInt, k);
	}
	return lineVec;
}

