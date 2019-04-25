/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "pilhaseq.h"

/* Função que verifica se a pilha está vazia */
int vaziaPilha (pilha *P) {
    if (P->fim == 0)
        return 1;
    else
        return 0;
}

/* Função que verifica se a pilha está cheia */
int cheiaPilha (pilha *P) {
    if (P->fim == P->tam)
        return 1;
    else
        return 0;
}

/* Função que aloca(cria) pilha */
void criaPilha (pilha *P, int n, int m) {
    P->cont = (no*) malloc (sizeof(no)*ceil((float)n/m));
    P->tam = ceil((float)n/m);
    P->fim = 0;
}

/* Função que insere o nó na pilha */
void inserePilha (pilha *P, no k) {
    if(!cheiaPilha(P)) {             // Se a pilha não estiver cheia, insere o nó
        P->fim ++;
        P->cont[P->fim-1] = k;
    }
    else                           // Se a pilha estiver cheia imprime mensagem de erro (impossibilidade de inserção)
        printf("ERRO: Pilha cheia\n");
}

/* Função que remove o nó da pilha */
no removePilha (pilha *P) {
    no retorno;
    if(!vaziaPilha(P)) {         // Verifica se a pilha não estiver vazia antes de remover o nó (evitar underflow)
        retorno = P->cont[P->fim-1];
        P->fim --;
    }
    else{                       // Se a pilha estiver vazia imprime mensagem de erro (impossibilidade de remoção)
        printf("ERRO: Pilha Vazia\n");
    }
    return retorno;
}
