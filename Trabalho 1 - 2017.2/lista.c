/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

/* Função que cria lista */
void criaLista (cliente* L) {
	*L=NULL;
}

/* Função que insere nó na lista */
void insereLista (cliente* L, no k) {
	if(*L == NULL) {		// Verifica se a lista está vazia antes de alocar o novo cliente
		cliente novo = (cliente) malloc(sizeof(nolista));
		if(k.op)		// Muda o sinal do valor a depender da operação ("-" para saque e "+" para depósito)
			k.valor *= -1;
		novo->saldo = k.valor;
		novo->id = k.id;
		novo->qnt = 1;
		novo->ant = NULL;
		novo->prox = NULL;
		*L = novo;
	}

	else{
		cliente p = *L;

		if(p->id > k.id) {
			while (p->ant != NULL && p->ant->id >= k.id) {
				p = p->ant;
			}
		}
		else if (p->id < k.id) {
			while (p->id < k.id && p->prox != NULL) {
				p = p->prox;
			}
		}



		if(p->id == k.id) {				// Condição que encontra id de cliente já registrado
			if(k.op)
				k.valor *= -1;
			p->saldo += k.valor;		// Alteração apenas no valor do saldo no cliente já registrado
			p->qnt ++;
		}
		else {

			cliente novo = (cliente) malloc(sizeof(nolista));
			if(k.op)
				k.valor *= -1;
			novo->saldo = k.valor;
			novo->id = k.id;
			novo->qnt = 1;

			*L = novo;


			if (novo == NULL)
				printf("ERRO: OVERFLOW\n");
			else if(p->id > k.id) {
				if(p->ant != NULL) {
					novo->ant = p->ant;
					p->ant->prox = novo;
				}
				else
					novo->ant = NULL;
				p->ant = novo;
				novo->prox = p;
			}
			else if (p->id < k.id) {
				if(p->prox != NULL) {
					novo->prox = p->prox;
					p->prox->ant = novo;
				}
				else
					novo->prox = NULL;
				p->prox = novo;
				novo->ant = p;
			}
		}
	}
}

/* Função que retorna a quantidade de clientes registrados */
int contaLista (cliente* L) {

	int cont = 1;
	cliente p = *L;

	while (p->ant != NULL)
		p = p->ant;

	while (p->prox != NULL) {
		cont++;
		p = p->prox;
	}
	return cont;
}

/* Função que imprime o id do cliente, a quantidade de operações realizadas e o seu saldo */
void imprimeLista(cliente* L) {
	cliente p = *L;

	while (p->ant != NULL)
		p = p->ant;

	while (p != NULL) {
		printf("%i %i %lld\n", p->id, p->qnt, p->saldo);
		p = p->prox;
	}
}

/* Função que limpa toda a lista e desaloca os espaços utilizados */
void limpaLista(cliente* L){
	while ((*L)->prox != NULL){
		*L = (*L)->prox;
	}
	while ((*L)->ant != NULL){
		cliente p = *L;
		*L = (*L)->ant;
		free(p);
	}
	free(*L);
}