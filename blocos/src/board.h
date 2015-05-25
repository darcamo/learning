#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <assert.h>


#include <iostream>


/** Classe que armazena as posições preenchidas ou não. A numeração começa de cima-esquerda até baixo-direita.
	@author Darlan Cavalcante Moreira,,, <darcamo@gmail.com>
*/
class Board{
public:
	
    /**
     * Construtor de Board
     * @param pNRowInt Número de Linhas do Board 
     * @param pNColInt Número de Colunas do Board
     * @return 
     */
	Board(int pNRowInt, int pNColInt);
	
	/// @brief Destrutor virtual
	virtual ~Board();
	
	/**
	 *    Seta todas as posições do Board para falso
	 */
	void clear_board();

	/**
	 *    Seta o valor de uma posição específica de Board para verdadeiro ou falso
	 * @param pRowInt Valor da Linha
	 * @param pColInt Valor da Coluna
	 * @param pValueBool Qual valor setar: verdadeiro ou falso
	 */
	void set_value(int pRowInt, int pColInt, bool pValueBool = true);

	/**
	 *    Retorna o valor de uma posição específica de Board
	 * @param pRowInt Valor da Linha
	 * @param pColInt Valor da Coluna
	 * @return Valor da posição solicitada
	 */
	bool get_value(int pRowInt, int pColInt);

	/**
	 *    Seta os valores de uma linha inteira
	 * @param pRowInt Valor da Linha
	 * @param pValueBool Qual valor setar: verdadeiro ou falso
	 */
	void set_line(int pRowInt, bool pValueBool = true);

	/**
	 *    Seta os valores de uma linha de acordo com um vetor especificado 
	 * @param pRowInt Valor da Linha
	 * @param pLineVec Veotor especificando os valores da linha
	 */
	void set_line(int pRowInt, std::vector<bool> pLineVec);

	/**
	 *    Retorna uma linha inteira
	 * @param pRowInt Valor da linha
	 * @return Vetor contendo os valores da linha especificada por \a pRowInt
	 */
	std::vector<bool> get_line(int pRowInt);
	
	/**
	 *    Detecta se todos os elementos da linha são verdadeiros.
	 * @param pRowInt Valor da linha
	 * @return \a true se todos os elementos são verdadeiros ou \a false em caso contrário
	 */
	bool is_line_set(int pRowInt);
	
	/**
	 *    Retorna o número de linhas de Board.
	 * @return Número de linhas
	 */
	int get_nRows();

	/**
	 *    Retorna o número de colunas de Board
	 * @return Número de Colunas
	 */
	int get_nCols();

	/**
	 *    Deleta a linha especificada e "desce" todas as linhas acima dela
	 * @param pRowInt Valor da linha
	 */
	void delete_line(int pRowInt);
	
	/**
	 *    Muda as dimensões de Board para \a pNRowInt x \a pNColInt e seta todos os valores para false.
	 * @param pNRowInt Número de Linhas
	 * @param pNColInt Número de Colunas
	 */
	void resize_board(int pNRowInt, int pNColInt);

private:
	/**
	 *    Vetor que armazena todos os valores de Board
	*/
	std::vector< bool > boardMap;
	
	/**
	 *	Número de Linhas de Board
	*/
	int nRowInt;
	
	/**
	 *	Número de Colunas de Board
	*/
	int nColInt;
};

#endif
