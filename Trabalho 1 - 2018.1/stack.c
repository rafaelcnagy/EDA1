// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"


int vazia_pilha(pilha* P) {
    if(P->ent == 0)
        return 1;
    return 0;
}

int cheia_pilha(pilha* P) {
    if(P->ent == P->tam)
        return 1;
    return 0;
}

pilha* criar_pilha(unsigned int tam) {
    pilha* novo = (pilha*) malloc(sizeof(pilha));
    novo->chave = (operacao*) malloc(sizeof(operacao) * tam);
    novo->tam = tam;
    novo->ent = 0;
    return novo;
}

void inserir_pilha(pilha* P, operacao op) {
    if (cheia_pilha(P))
         printf("ERROR: PILHA CHEIA\n");
    else {
        if (vazia_pilha(P)) {
            P->ent = 1;
            P->chave[0] = op;
            P->qnt = 1;
        }
        else {
            P->chave[P->ent] = op;
            P->ent++;
            P->qnt++;
        }
    }
}

operacao remover_pilha(pilha* P) {
    operacao rmv;
    if (vazia_pilha(P))
        printf("ERROR: PILHA VAZIA\n");
    else {
        rmv = P->chave[P->ent - 1];
        P->ent--;
        P->qnt--;
        if(cheia_pilha(P)){
            P->ent = 0;
        }
    }
    return rmv;
}

void desalocar_pilha(pilha* P){
    free(P->chave);
    free(P);
}
