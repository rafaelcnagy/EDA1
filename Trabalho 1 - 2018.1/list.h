// Desenvolvido por Bárbara Gabriele Lima Luz Santos e Rafael Correa Nagy

#ifndef list
#define list

typedef struct mininodel {
    unsigned int cpf, o;
    char nome[26];
    struct mininodel *prox;
} nob;

typedef struct nodel {
    unsigned int cpf;
    long long qnt;
    nob *bem;
    struct nodel *prox, *ant;
} nol;

typedef struct listoflist {
    nol *raiz;
    long long qnt_cpf;
} lista;


/*
 * Função criar_lista:
 * Aloca o espaço de memória para uma nova lista. Retorna um ponteiro para a lista criada.
 *
 * */
lista* criar_lista();


/*
 * Função criar_nol:
 * Cria um nó do tipo nol. Retorna um ponteiro para o nó criado.
 *
 * */
nol* criar_nol(unsigned int cpf, nob* N);


/*
 * Função criar_nob:
 * Cria um nó do tipo nob. Retorna um ponteiro para o nó criado.
 *
 * */
nob* criar_nob(char nome[26], unsigned int cpf, unsigned int o);


/*
 * Função inserir_lista:
 * Insere um nó na lista.
 *
 * */
void inserir_lista(lista* L, nob* N);


/*
 * Função remover_lista:
 * Remove um nó da lista e retorna o elemento removido.
 *
 * */
nol remover_lista(lista* L);


/*
 * Função remover_nob:
 * Remove um bem do nó de lista e retorna seu conteúdo.
 *
 * */
nob remover_nob(nol* node);


#endif
