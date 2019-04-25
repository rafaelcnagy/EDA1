// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#ifndef oper
#define oper

typedef struct oper {
    unsigned int cpf, cpf3, p, o;
    char b[26];
} operacao;
#endif


#ifndef stack
#define stack

typedef struct stack {
	operacao *chave;
	unsigned int tam, ent;
    long long qnt;
} pilha;


/*
 *  Função vazia_pilha:
 *  Verifica se a pilha está vazia.
 *
 * */
int vazia_pilha(pilha* P);

/*
 *  Função cheia_pilha:
 *  Verifica se a pilha está cheia.
 *
 * */
int cheia_pilha(pilha* P);

/*
 * Função criar_pilha:
 * Aloca o espaço de memória para uma nova pilha. Retorna um ponteiro para a pilha criada.
 *
 * */
pilha* criar_pilha(unsigned int tam);


/*
 * Função inserir_pilha:
 * Insere um nó na pilha.
 *
 * */
void inserir_pilha(pilha* P, operacao op);


/*
 * Função remover_pilha:
 * Remove um nó da pilha e retorna a operação contida no nó.
 *
 * */
operacao remover_pilha(pilha* P);


/*
 * Função desalocar_pilha
 * Desaloca o espaço de memória destinado à operação e à pilha.
 *
 * */
void desalocar_pilha(pilha* P);
#endif
