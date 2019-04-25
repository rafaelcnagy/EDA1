// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int vazia_fila(fila* F) {
    if(F->sai == NULL) {
        return 1;
    }
    return 0;
}


fila* criar_fila() {
    fila* novo = (fila*) malloc(sizeof(fila));
    novo->ent = NULL;
    novo->sai = NULL;
    return novo;
}


nof* criar_nof(operacao O) {
    nof* novo = (nof*) malloc(sizeof(nof));
    novo->op = O;
    novo->prox = NULL;
    return novo;
}


void inserir_fila(fila* F, nof* N) {
    if(vazia_fila(F)) {
        F->sai = N;
    }  else {
        F->ent->prox = N;
    }
    F->ent = N;
}


operacao remover_fila(fila* F) {
	operacao rmv;
    if(vazia_fila(F))
        printf("ERROR: FILA VAZIA\n");
    else {
	    nof* R = F->sai;
	    if(F->sai == F->ent) {
	        F->sai = NULL;
	        F->ent = NULL;
	    }  else {
	        F->sai = F->sai->prox;
	    }
	    rmv = R->op;
	    free(R);
	}
    return rmv;
}
