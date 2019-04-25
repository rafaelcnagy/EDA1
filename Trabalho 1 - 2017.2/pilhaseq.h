/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#ifndef PILHASEQ
#define PILHASEQ
#include "structs.h"

/* Struct que define o nó de cada cliente atendido da pilha dos caixas */

typedef struct {
	int tam;		// Tamanho da pilha
	int fim;		// Campo de índice do final da pilha
	no *cont;		// Vetor que contém as informações da operação
}pilha;			// Definição do nome da struct: pilha

int vaziaPilha (pilha *P); 	// Protótipo da função (em pilhaseq.c) que verifica se a fila está vazia (verifica se o caixa está vazio)

int cheiaPilha (pilha *P);	// Protótipo da função (em pilhaseq.c) que verifica se a fila está cheia (verifica se o caixa está cheio)

void criaPilha (pilha *P, int n, int m);	// Protótipo da função (em pilhaseq.c) que cria a pilha

void inserePilha (pilha *P, no k);			// Protótipo da função (em pilhaseq.c) que insere um nó na pilha (insere um cliente no caixa)

no removePilha (pilha *P);					// Protótipo da função (em pilhaseq.c) que remove um nó da pilha

#endif
