/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#ifndef FILACIRC
#define FILACIRC
#include "structs.h"

/* Struct que define os campos da fila circular */

typedef struct {
	int comeco;			// Campo de índice do começo da fila circular
	int fim;				// Campo de índice do final da fila circular
	int tam;				// Tamanho da fila circular
	no *cont;				// Vetor que contém as informações da operação
}filacirc;				// Definição do nome da Struct: filacirc

int vaziaFila (filacirc *F);			// Protótipo da função (em filacirc.c) que verifica se a fila está vazia

int cheiaFila (filacirc *F);  		// Protótipo da função (em filacirc.c) que verifica se a fila está cheia

filacirc *criaFila (int n); 	// Protótipo da função (em filacirc.c) que cria a fila circular

void insereFila (filacirc *F, no k);	// Protótipo da função (em filacirc.c) que insere um nó na fila circular

no removeFila (filacirc *F);			// Protótipo da função (em filacirc.c) que remove um nó da fila circular

#endif
