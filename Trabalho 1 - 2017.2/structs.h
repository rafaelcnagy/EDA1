/* Disciplina: MATA40 - Estrutura de Dados e Algoritmos I */
/* Docente: Roberto Parente  	Semestre: 2017.2	*/
/* Integrantes da equipe: Bárbara Gabriele, Dimitri Marinho e Rafael Nagy */
#ifndef STRUCTS
#define STRUCTS

// structs.h foi criado para aproveitar esta struct em todas as outras Estruturas de Dados
// Essa prática evita ter de mudar o nome da struct a cada nova manipulação sendo que as mesmas são iguais

typedef struct {
	int id, op, valor;	// id do cliente, operação(saque ou depósito) e valor operado
}no;

#endif
