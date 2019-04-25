/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#include "filacirc.h"
#include "pilhaseq.h"
#include "lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int proxima=0;

// Remove os clientes que estavam na fila 'esperando atendimento' e os insere na pilha onde são armazenadas as operações
void MandarProAtendimento (filacirc *F, pilha P[], int m) {
	while (!vaziaFila(F)) {
		no nozinho = removeFila(F);
		inserePilha (&P[proxima], nozinho);
		proxima = (proxima+1)%m;
	}
}

// Lê os dados de entrada: identificador do cliente, operação e valor
void Leitura(filacirc *F, pilha P[], int n, int m) {
	int i;
	for (i=0; i<n; i++) {
		no aux;
		scanf ("%i %i %i", &aux.id, &aux.op, &aux.valor);
		insereFila(F, aux);

		if(cheiaFila(F)) {
			MandarProAtendimento (F, P, m);
		}
	}
}

// Imprime relatório final de atividades
void Relatorio (cliente *L) {
	int quantidade = contaLista (L);
	printf("%i\n", quantidade);
	imprimeLista (L);
}

int main() {

	int n, m, i;
	proxima=0;
	scanf ("%i %i", &m, &n);
	filacirc *F = criaFila(n);		// Entrada da Fila
	pilha *P = (pilha*) malloc (sizeof(pilha)*m);

	for(i=0; i<m; i++) {
		criaPilha(&P[i], n, m);
	}

	cliente L;
	criaLista (&L);
	Leitura (F, P, n, m);
	MandarProAtendimento (F, P, m);
	free (F);

	while (!vaziaFila(F)) {
		no nozinho = removeFila(F);
		inserePilha (&P[proxima], nozinho);
		proxima = (proxima+1)%m;
	}

	for(proxima=0; proxima<m; proxima++) {
		while (!vaziaPilha(&P[proxima])) {
			no aux = removePilha (&P[proxima]);
			insereLista (&L, aux);
		}
		free (P[proxima].cont);
	}

	free(P);
	Relatorio (&L);
	limpaLista (&L);
	return 0;
}
