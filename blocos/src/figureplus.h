#ifndef FIGUREPLUS_H
#define FIGUREPLUS_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigurePlus : public Figure
{
public:
	/**
	 * Construtor de FigurePlus
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigurePlus(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigurePlus();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1;
};

#endif
