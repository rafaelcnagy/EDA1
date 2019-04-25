/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "filacirc.h"


/* Função que verifica se a fila circular está vazia */
int vaziaFila (filacirc *F) {
	if (F->comeco==0 && F->fim==0)		// Se F->comeco e F->fim tiverem índice 0, então a fila está vazia
		return 1;						// Retorna 1 se a fila circular estiver vazia e 0 caso não esteja
	else
		return 0;
}

/* Função que verifica se a fila circular está cheia */
int cheiaFila (filacirc *F) {
	if ((F->fim % F->tam)+1 == F->comeco)
		return 1;					 // Retorna 1 se a fila circular estiver cheia e 0 caso não esteja
	else
		return 0;
}

/* Função que aloca e retorna a lista */
filacirc *criaFila (int n) {
	filacirc *F = (filacirc*) malloc (sizeof(filacirc));
	F->cont = (no*) malloc (sizeof(no) * ceil((double)sqrt(n)));
	F->tam = ceil((double)sqrt(n));
	F->comeco = 0;
	F->fim = 0;
	return F;
}

/* Função que insere nó K na fila circular */
void insereFila (filacirc *F, no k) {
	if(vaziaFila(F)) {			// Verifica se a fila não está vazia antes da inserção
		F->comeco = 1;
		F->fim = 1;
		F->cont[F->fim-1] = k;
	}
 	else if(!cheiaFila(F)) {		// Verifica se a fila não está cheia antes da inserção
		F->fim = (F->fim % F->tam)+1;
		F->cont[F->fim-1] = k;
	}
	else						// Se a lista estiver cheia imprime mensagem de erro (impossibilidade de inserção)
		printf("ERRO: Lista de Entrada Cheia\n");
}

/* Função para remoção de nó da fila circular */
no removeFila (filacirc *F) {
	no retorno;
	if(!vaziaFila(F)) {		// Verifica se a fila não está vazia antes de fazer a remoção
		retorno = F->cont[F->comeco-1];
		F->comeco = (F->comeco % F->tam) + 1;
		if((F->fim % F->tam)+1 == F->comeco) {
			F->fim = 0;
			F->comeco = 0;
		}
	}
	else{				// Se a fila estiver vazia retorna mensagem de erro (impossibilidade de remoção)
		printf("ERRO: Lista de Entrada Vazia\n");
	}
	return retorno;
}
