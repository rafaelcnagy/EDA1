// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#ifndef oper
#define oper

typedef struct oper {
    unsigned int cpf, cpf3, p, o;
    char b[26];
} operacao;
#endif


#ifndef queue
#define queue

typedef struct nodef {
    operacao op;
    struct nodef *prox;
} nof;

typedef struct queue {
    struct nodef *ent, *sai;
} fila;

/*
 * Função vazia_fila:
 * Verifica se a fila está vazia.
 *
 * */
int vazia_fila(fila* F);


/*
 * Função criar_fila:
 * Aloca o espaço de memória para uma nova fila. Retorna um ponteiro para a fila criada.
 *
 * */
fila* criar_fila();


/*
 * Função criar_nof:
 * Cria um nó do tipo nof. Retorna um ponteiro para o nó criado.
 *
 * */
nof* criar_nof(operacao O);


/*
 * Função inserir_fila:
 * Insere um nó na fila.
 *
 * */
void inserir_fila(fila* F, nof* N);


/*
 * Função remover_fila:
 * Remove um nó da fila e retorna a operação contida no nó
 *
 * */
operacao remover_fila(fila* F);

#endif
