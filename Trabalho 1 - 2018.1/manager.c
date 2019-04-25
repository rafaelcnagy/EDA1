// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "manager.h"

int vazia_gerenciador(gerenciador* G) {
	if(G->FdP == NULL)
		return 1;
	return 0;
}

int vazia_fila_gerenciador(gerenciador* G, int index){
	return vazia_fila(G->FdP[index]);
}

gerenciador* criar_gerenciador(unsigned int tam){
	gerenciador* novo = (gerenciador*) malloc(sizeof(gerenciador));
	novo->FdP = (fila**) malloc(sizeof(fila*) * tam);
	novo->tam = tam;
	for(unsigned int i = 0; i < tam; i++)
		novo->FdP[i] = criar_fila();
	return novo;
}

void inserir_gerenciador(gerenciador* G, operacao OP){
	nof* novo = criar_nof(OP);
	inserir_fila(G->FdP[OP.p-1], novo);
}

operacao remover_gerenciador(gerenciador* G, unsigned int index){
	operacao rmv = remover_fila(G->FdP[index]);
	return rmv;
}

void desalocar_gerenciador(gerenciador* G){
	for(unsigned int i = 0; i < G->tam; i++)
		free(G->FdP[i]);
	free(G->FdP);
}
