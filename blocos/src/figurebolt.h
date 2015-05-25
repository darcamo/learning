#ifndef FIGUREBOLT_H
#define FIGUREBOLT_H

#include "figure.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class FigureBolt : public Figure
{
public:
    /**
     * Construtor de FigureBolt
     * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
     */
    FigureBolt(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~FigureBolt();

protected:
	//Possíveis posições da figura (serão elementos do vetor Validmode da classe Figure)
	Board mode1, mode2;
};

#endif
