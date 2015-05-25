#ifndef FIGURET_H
#define FIGURET_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureT : public Figure
{
public:
	/**
	 * Construtor de FigureT
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigureT(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureT();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2, mode3, mode4;

};

#endif
