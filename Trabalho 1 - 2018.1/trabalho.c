// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "manager.h"
#include "stack.h"
#include "list.h"


// Imprime o relatório parcial
void relatorio_parcial(pilha** GdA, int qnt_gda, lista* L) {
    printf("-:| RELATÓRIO PARCIAL |:-\n%u\n", qnt_gda);
    for (int i=0; i<qnt_gda; i++) {

        printf("Guiche %i: %lld\n", i+1, GdA[i]->qnt);
        while (!vazia_pilha(GdA[i])) {
            operacao nova = remover_pilha(GdA[i]);
            char aux_op;
            if (nova.o)
                aux_op = 'A';
            else
                aux_op = 'T';
            printf("[%u,%u,%c,%s]\n", nova.cpf, nova.cpf3, aux_op, nova.b);
            nob* N = criar_nob(nova.b, nova.cpf, nova.o);
            inserir_lista(L, N);
            N = criar_nob(nova.b, nova.cpf3, !nova.o);
            inserir_lista(L, N);
        }
    }
}


// Imprime o relatório final
void relatorio_final(lista* L) {
    printf("-:| RELATÓRIO FINAL |:-\n%lld\n", L->qnt_cpf);
    while (L->raiz != NULL) {
        nol rmv = remover_lista(L);
        printf("-:[ %u: %lld\n", rmv.cpf, rmv.qnt);
        while (rmv.bem != NULL) {
            nob rmv_bem = remover_nob(&rmv);
            if(rmv_bem.o)
                printf("	+");
            else
                printf("	-");
            printf("%s\n", rmv_bem.nome);
        }
    }
}


unsigned int prox(unsigned int i, unsigned int total) {
    return (i + 1) % total;
}


operacao le_entrada(operacao nova) {
    char aux_op;
    scanf("%u %u %u %c ", &nova.cpf, &nova.cpf3, &nova.p, &aux_op);
    fgets(nova.b, 26, stdin);
    strtok(nova.b, "\n");
    if(aux_op == 'A')
        nova.o = 1;
    else
        nova.o = 0;

    for (int j=0; j<26; j++) {
        if(nova.b[j] == '\0')
            break;
        if(nova.b[j] == ' ') {
            nova.b[j] = '_';
        }
        else if(nova.b[j] >= 'a' && nova.b[j] <= 'z') {
            nova.b[j] = 'A' + (nova.b[j]-'a');
        }
    }
    return nova;
}


//Cria vetor de pilhas e aloca os Guiches de Atendimento
void aloca_atendimento(pilha **GdA, unsigned int qnt_gda, unsigned int qnt_cli) {
    for (unsigned int i=0; i<qnt_gda; i++)
        GdA[i] = criar_pilha((int) qnt_cli / qnt_gda + 1);
}



//Lê todas operacoes e alocar na fila correspondente
void inserir_fila_entrada(unsigned int qnt_cli, gerenciador* G) {
    for (unsigned int i=0; i<qnt_cli; i++) {
        operacao nova;
        nova = le_entrada(nova);
        inserir_gerenciador(G, nova);
    }
}



// Remove da fila de entrada
void remover_fila_entrada(unsigned int qnt_fdp, unsigned int qnt_gda, gerenciador* G, pilha **GdA ) {
    unsigned int next=0;
    for (int i = qnt_fdp-1; i >= 0; i--) {
        while (!vazia_fila_gerenciador(G, i)){
            operacao move = remover_gerenciador(G, i);
            inserir_pilha(GdA[next], move);
            next = prox(next, qnt_gda);
        }
    }
}


int main() {
    unsigned int qnt_fdp, qnt_gda, qnt_cli;
    scanf("%u %u %u", &qnt_fdp, &qnt_gda, &qnt_cli);

    gerenciador* G = criar_gerenciador(qnt_fdp);

    //Cria vetor de pilhas e aloca os Guiches de Atendimento
    pilha **GdA = (pilha**) malloc(sizeof(pilha*) * qnt_gda);
    aloca_atendimento(GdA, qnt_gda, qnt_cli);

    //Lê todas operacoes e alocar na fila correspondente
    inserir_fila_entrada(qnt_cli, G);

    // Remove da fila de entrada
    remover_fila_entrada(qnt_fdp, qnt_gda, G, GdA);

    lista* L = criar_lista();
    relatorio_parcial(GdA, qnt_gda, L);
    relatorio_final(L);

    desalocar_gerenciador(G);
    free(G);

    for(unsigned int i=0; i<qnt_gda; i++)
        desalocar_pilha(GdA[i]);

    free(GdA);
    free(L);

}
