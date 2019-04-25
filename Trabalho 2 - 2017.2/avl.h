#ifndef AVL
#define AVL

typedef struct node{
	struct node* pai;
	struct node* esq;
	struct node* dir;
	int id;
	int saldo;
	int qnt;
}no;

typedef struct avl{
	no* raiz;
	int qnt_operacoes;
	int qnt_clientes;
}arvore;



arvore* cria_arv ();

no* criar_no (int id, int valor);

int alt_sub (no* x);

int fb(no* x);

no* minimo (no* x);

no* maximo (no* x);

no* sucessor (no* x);

no* predecessor (no* x);

void rot_esq (arvore* T, no* x);

void rot_dir (arvore* T, no* x);

void rot_dupla_esq (arvore* T, no* x);

void rot_dupla_dir (arvore* T, no* x);

void balanceamento (arvore* T, no* x);

void inserir_avl (arvore* T, no* x, no* z);

void transplante (arvore* T, no* u, no* v);

void remover_avl (arvore* T, no* x, int k);

int consulta_avl (no* x, int id);

void listar_avl_ordem(no* x);

void listar_avl_nivel(no* x, int k);

void listar_avl ( no* node_ptr );

#endif
