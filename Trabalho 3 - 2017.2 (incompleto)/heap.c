#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"

struct HEAP{

	int freq;
	int flag;
	char c;
	int pos;
	heap *dir;
	heap *esq;
	heap *pai;

};

// CRIA NÓ QUE APONTARÁ PARA A RAIZ //
heap* fila_cria(){
	heap *FILA;
	FILA = malloc(sizeof(heap));
	if(FILA==NULL)
		return 0;
	FILA->freq=0;
	FILA->flag=0;
	FILA->pos=-1;
	FILA->c='@';
	FILA->dir = NULL;
	FILA->pai = NULL;
	FILA->esq = NULL;
	return FILA; 
}

// INSERÇÃO //
void fila_insere(heap **FILA, char ch){
	if((*FILA)->pai == NULL)
	{
		heap *tmp;
		tmp = malloc(sizeof(heap));
		if(tmp == NULL)
			return;
		tmp->freq = 1;
		tmp->pos=0;
		tmp->flag=1;
		tmp->c = ch;
		tmp->pai = *FILA;
		tmp->dir = NULL;
		tmp->esq = NULL;
		*FILA = tmp;
		return;		
	}
	else
	{
		int cont = fila_quantidade(*FILA);
		int x=-1;
		search_node(*FILA, ch, &x);
		if(x!=-1)
		{
			FILA[x]->freq++;
			min_heapify(FILA, x);
			return;
		}
		heap *tmp;
		tmp = malloc(sizeof(heap));
		if(tmp == NULL)
			return;
		tmp->freq = 1;
		tmp->flag = 1;
		tmp->c = ch;
		tmp->pos = cont;
		tmp->dir = NULL;
		tmp->esq = NULL;
		tmp->pai = FILA[(cont-1)/2];
		FILA[cont] = tmp;
		if((cont+1)%2==0)
			FILA[(cont-1)/2]->esq = tmp;
		else
			FILA[(cont-1)/2]->dir = tmp;

		int aux = cont;
		while(aux>=1 && FILA[aux/2]->freq>FILA[aux]->freq)
		{
			int x;
			char y;
			x = FILA[aux/2]->freq;
			y = FILA[aux/2]->c;
		
			FILA[aux/2]->c = FILA[aux]->c;
			FILA[aux/2]->freq = FILA[aux]->freq;
			FILA[aux]->freq = x;
			FILA[aux]->c = y;
			
			aux = aux/2;
		}
		min_heapify(FILA, cont);
		return;
	}
	return;

}


// [MIN_HEAPIFY] //
void min_heapify(heap **FILA, int pos){
	int L = (pos*2)+1;
	int R = (pos*2)+2;
	int menor;
	int qtd = fila_quantidade(*FILA);


	if(L<qtd && FILA[L]->freq < FILA[pos]->freq)
		menor = L;
	else
		menor = pos;

	if(R<qtd && FILA[R]->freq < FILA[menor]->freq)
		menor = R;

	if(menor!=pos)
	{
		int x;
		char y;
		x = FILA[pos]->freq;
		y = FILA[pos]->c;
		
		FILA[pos]->c = FILA[menor]->c;
		FILA[pos]->freq = FILA[menor]->freq;
		FILA[menor]->freq = x;
		FILA[menor]->c = y;
		
		min_heapify(FILA,menor);
	}

}



// PROCURA UM DETERMINADO NÓ A PARTIR DO CARACTER E RETORNA SUA POSIÇÃO (SE ACHAR) PARA O PONTEIRO X //
int search_node(heap *FILA, char ch, int *x){
	if(FILA == NULL) return -1;
	
	if(FILA->c == ch)
		*x = FILA->pos;
	
	else
	{
		if(FILA->esq!=NULL) search_node(FILA->esq, ch, &(*x));
		if(FILA->dir!=NULL) search_node(FILA->dir, ch, &(*x));
	}	
	return -1;
}


int fila_vazia(heap *FILA){
	if(FILA==NULL)
		return 1;
	return 0;
}

//  IMPRIME EM ORDEM DE POSIÇÃO //
void fila_imprime(heap **FILA){
	if(*FILA == NULL)
		return;
	int qtd = fila_quantidade(*FILA);
	//printf("%d\n", qtd);
	for(int i=0;i<qtd;i++)
		printf("%d %d %c\n", FILA[i]->pos, FILA[i]->freq, FILA[i]->c);
	
}


//	RETORNA QTD DE ELEMENTOS NA FILA  //
int fila_quantidade(heap *FILA){
	if(FILA==NULL || FILA->pai==NULL) return 0;
	int cont=1;

	if(FILA->esq != NULL) cont+= fila_quantidade((FILA->esq));
	if(FILA->dir != NULL) cont+= fila_quantidade((FILA->dir));

	return cont;
}

//REMOVE ELEMENTO E REORDENA FILA
void fila_remove(heap **FILA){
	
	if(*FILA==NULL) return;
	int qtd = fila_quantidade(*FILA);
	if(qtd==0) return;
	FILA[0]->c = FILA[qtd-1]->c;
	FILA[0]->freq = FILA[qtd-1]->freq;
	
	
	remove_top(&(*FILA), qtd);

	if(qtd!=1)min_heapify(&(*FILA), 0);

}

void fila_libera(heap *FILA){
	if(FILA->pai!=NULL && FILA->pai->freq==0) free(FILA->pai);
}

void remove_top(heap **FILA, int qtd){
	if(*FILA==NULL) return;

	if((*FILA)->pos == qtd-1)
	{
		if(qtd==1)
			free((*FILA)->pai);
		free(*FILA);
		*FILA=NULL;
		return;
	}

	if((*FILA)->esq!=NULL) remove_top(&(*FILA)->esq, qtd);
	if((*FILA)->dir!=NULL) remove_top(&(*FILA)->dir, qtd);
}

heap* get_last(heap **FILA, int qtd){
	return FILA[qtd-1];
}
