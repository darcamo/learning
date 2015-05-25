#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include <vector>
#include <SDL/SDL_ttf.h>
#include "general_defs.h"
#include "board.h"
#include "figurebolt.h"
#include "figurebolt2.h"
#include "figureline.h"
#include "figuresquare.h"
#include "figuret.h"
#include "figureldireito.h"
#include "figurelesquerdo.h"
#include "figureplus.h"
#include "figurev.h"
#include <math.h>

/**
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
	Classe encarregada de rodar o jogo.
*/
class Game
{
public:
	/// \brief Contrutor padrão
	Game();
	
	/// \brief Destrutor padrão
	virtual ~Game();

	/// \brief Roda o jogo
	void play();

protected:
	/**
	 *	Superfície SDL que representa a tela do computador. O que for gravado para essa superfície (atraves de um blit) aparecerá na tela depois que for chamada a função SDL_UpdateRect.
	*/
	SDL_Surface *screenSDLSurface;

	/**
	 *	Superfície SDL correspondnete ao fundo.
	*/
	SDL_Surface *backgroundSDLSurface;

	/**
	 *	Superfície SDL correspondente ao bloco que forma as peças.
	*/
	SDL_Surface *blockSDLSurface;

	/**
	 *	Superfície SDL correspondente a área de jogo.
	*/
	SDL_Surface *boardSDLSurface;

	/**
	 *	Superfície SDL que armazena o texto com a pontuação.
	*/
	SDL_Surface *textSDLSurface; 

	/**
	 *	Fonte que será utilizada para criar a superfície com o texto da pontuação. \a font será um dos argumentos passados para a função TTF_RenderText_Solid() que retorna um ponteiro para um objeto do tipo SDL_Surface.
	 *	\see textSDLSurface
	*/
	TTF_Font *font;

	/**
	 *	Um grid indicando quais posições na área de jogo estão ou não preenchidas por um blocos
	*/
	Board gameTable;

	/**
	 * Carrega os dados do jogo, como background, blocos, fonte, etc.
	 */
	void load_data();

	/**
	 *    Desenha o fundo do jogo na tela.
	 */
	void draw_background();

	/** \brief Desenha um objeto do tipo Board na tela.
	 *    Desenha um bloco para cada elemento do objeto Board com valor true. A posição [0,0] do objeto é colocada na posição [ \a pXOffsetInt , \a  pYOffsetInt ] 
	 * @param pXOffsetInt Offset no eixo x.
	 * @param pYOffsetInt Offset no eixo y.
	 * @param pBoard Objeto da classe Board que deve ser desenhado.
	 */
	void draw_Board(int pXOffsetInt, int pYOffsetInt, Board *pBoard);

	/** \brief Desenha a pontuação atual na tela.
	 * 	\a textSDLSurface é atualizado com o valor mais recente da pontuação e em seguida é desenhado na tela na posição [ \a pXOffsetInt , \a pYOffsetInt ]
	 * @param pXOffsetInt Offset no eixo x.
	 * @param pYOffsetInt Offset no eixo y.
	 */
	void draw_score(int pXOffsetInt = 600, int pYOffsetInt = 20);
	
	/**	\brief Desenha tudo.
	 *	 Função conveniente que chama as funções draw_background(), draw_Board() e draw_score() para desenhar tudo.
	 */
	void draw_everything();

	/**
	 *    Executa a ação que deve ser feita quando o jogador perde. Por enquanto apenas sai do jogo.
	 */
	void player_lost();
	
	/**	\brief Preenche a última linha. Trapaça útil para fins de debug.
	 * 
	 */
	void fill_last_line();
	
	/**
	 *	Armazena o valor do último "Tick".
	*/
	int prevTicksInt;

	/**
	 *	Armazena o valor do "Tick" atual.
	*/
	int curTicksInt;
	
	/** \brief Medida em milisegundos para que a Figura desça uma posição.
	 *	\a updateDelayInt é utilizado como controle da velocidade do jogo. Um valor menor fará com que a figura desça mais rápido. Ou seja, quando menor o valor de \a updateDelayInt maior o nível de dificuldade.
	*/
	int updateDelayInt;
	
	/**
	 * Ponteiro que aponta para a figura atual.
	*/
	Figure *figurePtr;

	/**
	 * Ponteiro que aponta para a próxima figura.
	*/
	Figure *nextFigurePtr;
	
	/**
	 *	Armazena a pontuação do usuário.
	*/
	int pointsInt;

	/** \brief Atualiza o estado do jogo.
	 * Move a figura de acordo com a última ação do jogador, cria ou deleta a figura quando for o caso, etc.
	 * @return true se o jogador perdeu ou false em caso contrário.
	 */
	bool update();

	/**
	 *    Tenta mover a figura para a esquerda.
	 * @return true se houver colisão e a figura não é movida. Retorna false em caso contrário.
	 */
	bool move_left();

	/**
	 *    Tenta mover a figura para a direita.
	 * @return true se houver colisão e a figura não é movida. Retorna false em caso contrário.
	 */
	bool move_right();

	/**
	 *    Tenta mover a figura para baixo.
	 * @return true se houver colisão e a figura não é movida. Retorna false em caso contrário.
	 */
	bool move_down();

	
	/**
	 *    Rotaciona a figura para direita.
	 * @return true se houver colisão e a figura não é rotacionada. Retorna false em caso contrário.
	 */
	bool change_right();

	/**
	 *    Detecta se uma linha foi preenchida e apaga a linha.
	 */
	void detect_full_line();
	
	/** \brief Carrega um arquivo bitmap em uma SDL_Surface.
	 *	A superfície carregada já está no formato de tela, garantindo blits mais rápidos. 
	 * @param pBitmapFileName Arquivo bitmap que deve ser carregado.
	 * @param pSurfacePtr Ponteiro no qual será armazenado a superfície criada.
	 */
	void load_SDLSurface(const char * pBitmapFileName, SDL_Surface * &pSurfacePtr);

	/**
	 * Desce a figura o máximo possível
	 */
	void move_to_bottom();

	/**
	 *    Cria uma nova Figura
	 * @param pFigurePtr Ponteiro no qual a nova figura será armazenada.
	 */
	void newFigure(Figure * &pFigurePtr);
};

#endif
