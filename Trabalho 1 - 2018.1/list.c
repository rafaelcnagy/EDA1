// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"


int vazia_lista(lista* L) {
    if(L->raiz == NULL)
        return 1;
    return 0;
}


lista* criar_lista() {
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->raiz = NULL;
    novo->qnt_cpf = 0;
    return novo;
}


nol* criar_nol(unsigned int cpf, nob* N) {
    nol* novo = (nol*)malloc(sizeof(nol));
    novo->cpf = cpf;
    novo->bem = N;
    novo->qnt = 1;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}


nob* criar_nob(char nome[26], unsigned int cpf, unsigned int o) {
    nob* novo = (nob*)malloc(sizeof(nob));
    strcpy(novo->nome, nome);
    novo->cpf = cpf;
    novo->o = o;
    novo->prox = NULL;
    return novo;
}


void inserir_lista(lista* L, nob* N) {

    if (vazia_lista(L)) {
        nol* novo = criar_nol(N->cpf, N);
        novo->prox = novo;
        novo->ant = novo;
        L->raiz = novo;
        L->qnt_cpf = 1;
        return;
    }

    nol* aux = L->raiz;

    if(aux->cpf > N->cpf) {
        nol* novo = criar_nol(N->cpf, N);
        L->raiz = novo;
        L->qnt_cpf++;
        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
        return;
    }

    while (aux->prox != L->raiz && N->cpf >= aux->prox->cpf) {
        aux = aux->prox;
    }

    if (aux->cpf == N->cpf) {
        aux->qnt++;
        nob* aux2 = aux->bem;
        while (aux2->prox != NULL && strcmp(N->nome, aux2->prox->nome) > 0) {
            aux2 = aux2->prox;
        }
        if (aux2 == aux->bem && strcmp(N->nome, aux2->nome) < 0) {
            aux->bem = N;
            N->prox = aux2;
        }
        else {
            N->prox = aux2->prox;
            aux2->prox = N;
        }
        return;
    }

    if (aux->prox == L->raiz) {
        nol* novo = criar_nol(N->cpf, N);
        aux->prox = novo;
        L->raiz->ant = novo;
        novo->ant = aux;
        novo->prox = L->raiz;
        L->qnt_cpf++;
    }
    else {
        nol* novo = criar_nol(N->cpf, N);
        nol* aux2 = aux->prox;
        aux->prox = novo;
        aux2->ant = novo;
        novo->prox = aux2;
        novo->ant = aux;
        L->qnt_cpf++;
    }
}


nol remover_lista(lista* L) {
    nol rmv;
    if(vazia_lista(L)) {
        printf("ERROR: LISTA VAZIA\n");
    }
    else if (L->raiz->prox == L->raiz){
        rmv = *(L->raiz);
        nol *aux = L->raiz;
        L->raiz = NULL;
        free(aux);
    }
    else {
        rmv = *(L->raiz);
        nol *aux = L->raiz;
        L->raiz = aux->prox;
        L->raiz->ant = aux->ant;
        aux->ant->prox = L->raiz;
        free(aux);
    }
    return rmv;
}
    

nob remover_nob(nol* node) {
    nob rmv = *(node->bem);
    free(node->bem);
    node->bem = rmv.prox;
    return rmv;
}

