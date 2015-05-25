#ifndef FIGUREV_H
#define FIGUREV_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darlan@darlan-laptop>
*/
class FigureV : public Figure
{
public:
	/**
	 * Construtor de FigureV
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
	FigureV(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureV();
	
protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2, mode3, mode4;

};

#endif
