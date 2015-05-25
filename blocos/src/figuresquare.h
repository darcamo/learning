#ifndef FIGURESQUARE_H
#define FIGURESQUARE_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureSquare : public Figure
{
public:
	/**
	 * Construtor de FigureSquare
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigureSquare(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureSquare();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1;

};

#endif
