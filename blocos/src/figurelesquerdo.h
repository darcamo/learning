#ifndef FIGURELESQUERDO_H
#define FIGURELESQUERDO_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureLEsquerdo : public Figure
{
public:
	/**
	 * Construtor de FigureLEsquerdo
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigureLEsquerdo(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureLEsquerdo();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2, mode3, mode4;

};

#endif
