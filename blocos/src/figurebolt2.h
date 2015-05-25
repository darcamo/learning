#ifndef FIGUREBOLT2_H
#define FIGUREBOLT2_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureBolt2 : public Figure
{
public:
	/**
	 * Construtor de FigureBolt2
	 * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
	 */
    FigureBolt2(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureBolt2();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2;
};

#endif
