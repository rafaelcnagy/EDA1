/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#ifndef LISTA
#define LISTA
#include "structs.h"

/* Struct que define o nó de cada cliente da lista duplamente encadeada */

typedef struct Nolista{
	int id, qnt;
	long long saldo;		// Cria o campo de identificação do cliente (id), a quantidade de operações feitas por ele e o seu saldo bancário
	struct Nolista *ant, *prox;	// Cria os ponteiros que armazenam o nó anterior(*ant) e o próximo nó(*prox) da lista duplamente encadeada
}nolista;						// Definição do nome da struct: nolista

typedef nolista* cliente;


void criaLista (cliente* L);			// Protótipo da função (em lista.c) que cria a lista duplamente encadeada

void insereLista (cliente* L, no k);	// Protótipo da função (em lista.c) que insere um nó (cliente) na lista duplamente encadeada

cliente removeLista (cliente* L);		// Protótipo da função (em lista.c) que remove um nó (cliente) da lista duplamente encadeada

int contaLista (cliente* L);			// Protótipo da função (em lista.c) que percorre os nós na lista duplamente encadeada

void imprimeLista (cliente* L);			// Protótipo da função (em lista.c) que imprime na tela o id (identificação) do cliente e o seu respectivo saldo

void limpaLista(cliente* L);			// Protótipo da função (em lista.c) que limpa toda a lista e desaloca todo espaço utilizado

#endif
