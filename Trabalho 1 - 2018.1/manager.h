// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#ifndef manager
#define manager

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

typedef struct mng{
	fila** FdP;
	unsigned int tam;
} gerenciador;


/*
 * Função vazia_gerenciador
 * Verifica se o gerenciador está vazio.
 *
 * */
int vazia_gerenciador(gerenciador* G);


/*
 * Função vazia_fila_gerenciador
 * Verifica se a fila contida no gerenciador está vazia.
 *
 * */
int vazia_fila_gerenciador(gerenciador* G, int index);


/*
 * Função criar_gerenciador
 * Alova espaço de memória para um novo gerenciador. Retorna um ponteiro para o gerenciador criado.
 *
 * */
gerenciador* criar_gerenciador(unsigned int tam);


/*
 * Função inserir_gerenciador
 * Insere uma nova operação no gerenciador.
 * */
void inserir_gerenciador(gerenciador* G, operacao O);


/*
 * Função remover_gerenciador
 * Remove elemento do gerenciador e retorna o elemento removido.
 *
 * */
operacao remover_gerenciador(gerenciador* G, unsigned int index);


/*
 * Função desalocar_gerenciador
 * Desaloca espaço de memória destinado ao gerenciador.
 *
 * */
void desalocar_gerenciador(gerenciador* G);

#endif
