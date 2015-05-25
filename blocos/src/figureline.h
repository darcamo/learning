#ifndef FIGURELINE_H
#define FIGURELINE_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureLine : public Figure
{
public:
	/**
	 * Construtor de FigureLine
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigureLine(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureLine();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2;
};

#endif
