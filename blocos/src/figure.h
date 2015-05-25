#ifndef FIGURE_H
#define FIGURE_H
#include "general_defs.h"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <assert.h>
#include "board.h"

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
	Grid 4x4 no qual fica representada a figura.
*/
class Figure{
public:
    /**
     * Construtor de Figure
     * @param pGameTablePtr Ponteiro para \a GameTable utilizado.
	 * \see Game::gameTable
     */
    Figure(Board *pGameTablePtr);

	/// @brief Destrutor virtual
    virtual ~Figure();

	/** \brief Seta a posição da figura
	 *    Seta em que linha e coluna de \a gameTable a posição [0,0] da figura está.
	 * @param pRowInt O valor da linha 
	 * @param pColInt O valor da coluna
	 * \see Game::gameTable
	 */
	void set_position(int pRowInt, int pColInt);

	/**
	 *    Desenha a figura (checa se houve colisão antes). Retorna true se houver colisão e não desenha o bloco.
	 * @param mark 
	 * @return 
	 */
	bool draw(bool mark = true);

	/**
	 *    Tenta mover a figura para a esquerda. Retorna true se houver colisão e a figura não é movida.
	 * @return true se houver colisão ou false em caso contrário
	 */
	bool move_left();

	/**
	 *    Tenta mover a figura para a direita. Retorna true se houver colisão e a figura não é movida.
	 * @return true se houver colisão ou false em caso contrário
	 */
	bool move_right();

	/**
	 *    Tenta mover a figura para baixo. Retorna true se houver colisão e a figura não é movida.
	 * @return true se houver colisão ou false em caso contrário
	 */
	bool move_down();

	/**
	 *    Tenta mover a figura para cima. Retorna true se houver colisão e a figura não é movida. Essa função não é utilizada no jogo em si, mas foi feita para fins de debug.
	 * @return true se houver colisão ou false em caso contrário.
	 */
	bool move_up();

	/**
	 *    Rotaciona a figura para a direita. Retorna true se houver colisão e a figura não é rotacionada.
	 * @return true se houver colisão ou false em caso contrário.
	 */
	bool change_right();
	
	/**
	 *    Detecta se houve colisão.
	 * @return true se houver colisão ou false em caso contrário.
	 */
	bool detect_collision();
	

	/**
	 *    Retorna a figura em sua posição (rotação) atual.
	 * @return Ponteiro para um objeto da classe Board que representa a figura. 
	 */
	Board* get_figureGrid();
protected:
	/**
	 *	Ponteiro para o gameTable
	 * \see Game::gameTable
	 * @todo Mudar tudo que requer conhecimento de gameTable para a classe Game e apagar a função get_figureGrid() dessa classe. Para isso detect_collision teria que ser mudado para a classe game. Isso vale a pena? Acho que não.
	*/
	Board *gameTablePtr;
	
	/**
	 *	Marca a linha atual em que se encontra a figura (numeração de cima para baixo).
	*/ 
	int rowInt;

	/**
	 *	Marca a coluna atual em que se encontra a figura (numeração da esquerda para a direita)
	*/ 
	int colInt;
	
	/**
	 *	Indica quando foi a última vez que a função change_right() foi chamada.
	*/
	int prevTicksInt; 

	/** 
	 *	Cada figura no jogo corresponde a um objeto da classe Board. Isso corresponde a dizer que a figura é representada por uma matriz cujos elementos podem ter valor true ou false. O vetor \a Validmode armazena ponteiros para tantos objetos da classe Board quantos forem as posições em que a figura pode estar.
	*/ 
	std::vector<Board *> Validmode;

	/**
	 *	Indica qual elemento do vetor Figure::Validmode corresponde a posição atual da figura.
	*/
	int actualMode;
};

#endif
