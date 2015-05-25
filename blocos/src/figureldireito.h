#ifndef FIGURELDIREITO_H
#define FIGURELDIREITO_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureLDireito : public Figure
{
public:
	/**
	 * Construtor de FigureLDireito
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigureLDireito(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureLDireito();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2, mode3, mode4;

};

#endif
