#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "avl.h"

arvore* criar_avl (){ //cria a avl
	arvore* T;
	T = malloc (sizeof(arvore)); //aloca a memória necessária
	T->raiz = NULL; //primeira raiz nula, já que não tem nenhum nó
	T->qnt_clientes = 0;
	T->qnt_operacoes = 0;
	if(T == NULL){
		printf("ERRO DE MEMORIA\n");
	}
	return T;
}

no* criar_no (int id, int valor){ //cria o nó para ser inserido na avl
	no* Node;
	Node = malloc (sizeof(no)); //aloca a memoria necessária
	if(Node == NULL){
		printf("ERRO DE MEMORIA\n");
	}
	Node->esq = NULL; //ambos os filhos serão nulos, já que é um novo nó criado
	Node->dir = NULL;
	Node->id = id;
	Node->saldo = valor;
	Node->qnt = 1;
	
	return Node;
}



int alt_sub (no* x){ //retorna a altura da subárvore
	int alt_dir = 0, alt_esq = 0;
	
	if (x->esq != NULL){
		alt_esq = alt_sub(x->esq);
	}
	if (x->dir != NULL){
		alt_dir = alt_sub(x->dir);
	}
	int h = 1;
	if (alt_dir > alt_esq){
		h += alt_dir;
	}
	else{
		h += alt_esq;
	}
	return h;
}


int fb(no* x){//retorna o fator de balanceamento de determinado nó
	int fb=0;
	if(x->dir != NULL){
		fb += alt_sub (x->dir);
	}
	if(x->esq != NULL){
		fb -= alt_sub (x->esq);
	}
	return fb;
}



no* minimo (no* x){//retorna o nó minimo
	while (x->esq != NULL){
		x = x->esq;
	}
	return x;
}

no* maximo (no* x){//retorna o nó máximo
	while (x->dir != NULL){
		x = x->dir;
	}
	return x;
}

no* sucessor (no* x){ //retorna o sucessor de um determinado nó
	if (x->dir != NULL){
		return minimo (x->dir);
	}
	no* y = NULL;
	if(x->pai != NULL){
		y = x->pai;
	}
	while (y!=NULL && x==y->dir){
		x=y;
		y=y->pai;
	}
	return y;
}

no* predecessor (no* x){ //retorna o predecessor de um determinado nó
	if (x->esq != NULL){
		return maximo (x->esq);
	}
	no* y = NULL;
	if(x->pai != NULL){
		y = x->pai;
	}
	while (y!=NULL && x==y->esq){
		x=y;
		y=y->pai;
	}
	return y;
}


void rot_esq (arvore* T, no* x){ //rotação à esquerda
	no* y = x->dir;
	x->dir = y->esq;
	if(y->esq != NULL){
		y->esq->pai = x;
	}
	y->esq = x;
	y->pai = x->pai;
	if(T->raiz == x){
		T->raiz = y;
	}
	else{
		if(x->pai->dir == x){
			x->pai->dir = y;
		}
		else {
			x->pai->esq = y;
		}
	}
	x->pai = y;
}


void rot_dir (arvore* T, no* x){ //rotação à direita
	no* y = x->esq;
	x->esq = y->dir;
	if(y->dir != NULL){
		y->dir->pai = x;
	}
	y->dir = x;
	y->pai = x->pai;
	if(T->raiz == x){
		T->raiz = y;
	}
	else{
		if(x->pai->dir == x){
			x->pai->dir = y;
		}
		else {
			x->pai->esq = y;
		}
	}
	x->pai = y;
}


void rot_dupla_esq (arvore* T, no* x){ //rotação dupla à esquerda
	rot_dir (T, x->dir);	
	rot_esq (T, x);
}

void rot_dupla_dir (arvore* T, no* x){//rotação dupla à direita
	rot_esq (T, x->esq);	
	rot_dir (T, x);
}

void balanceamento (arvore* T, no* x){ //balanceia a árvore
	
	if (fb(x) == 2){ //se o fator de balanceamento do nó for 2
		no* y = x->dir; //checa o da direita
		if (fb(y) == 1){ //se o fator for 1
			rot_esq (T,x); //faz rotação à esquerda
		}
		else if (fb(y) == -1){ //se o fator for -1
			rot_dupla_esq (T,x); //faz rotação dupla à esquerda
		}
	}
	
	else if (fb(x) == -2){ //se o fator de balanceamento do nó for -2
		no* y = x->esq; //checa o da esquerda
		if (fb(y) == -1){ //se o fator for -1
			rot_dir (T,x); //faz rotação à direita
		}
		else if (fb(y) == 1){//se for 1
			rot_dupla_dir (T,x);//faz rotação dupla
		}
	}
}



void inserir_avl (arvore* T, no* x, no* z){ //insere o nó na avl


	if (x == NULL){ // se a raiz for nula, insere na raiz
		T->raiz = z;
		T->qnt_clientes = 1;
		T->qnt_operacoes = 1;
	}


	else { 
		if (z->id == x->id){ //se o nó tiver o mesmo id de um nó que já existe na avl
			T->qnt_operacoes++;
			x->qnt++;
			x->saldo += z->saldo;
			free(z); //libera-se a memoria do no novo e apenas edita-se o antigo
		}
		else if (z->id < x->id){ //se o nó novo tiver um id menor que o seu pai, (o primeiro pai sendo a raiz) ele é alocado à esquerda
			if(x->esq == NULL){ //se não houver mais nenhum à esquerda, ele é inserido
				T->qnt_operacoes++;
				T->qnt_clientes++;
				x->esq = z;
				z->pai = x;
			}
			else{
				inserir_avl(T, x->esq, z); //se houver, a função entra novamente, até que encontre o espaço vazio para o nó
			}
		}
		else if (z->id > x->id){//se o nó tiver um id maior que seu pai, (o primeiro pai sendo a raiz), ele é alocado à direita
			if (x->dir == NULL){//se não houver mais nenhum à direita, ele é inserido
				T->qnt_operacoes++;
				T->qnt_clientes++;
				x->dir = z;
				z->pai = x;
			}
			else{
				inserir_avl(T, x->dir, z);//se houver, a função entra novamente, até que encontre o espaço vazio para o nó 
			}
		}
		balanceamento (T, x); //balanceia-se a avl
	}
}



void transplante (arvore* T, no* u, no* v){ //troca-se a posição de um nó com o outro
	if (T->raiz == u){
		T->raiz = v;
	}
	else if (u == u->pai->esq){
		u->pai->esq = v;
	}
	else{
		u->pai->dir = v;
	}	
	if (v != NULL){
		v->pai = u->pai;
	}
	free(u);
}



void remover_avl (arvore* T, no* x, int k){ //remove um nó da avl

	if (k < x->id){ 
		if (x->esq != NULL){
			remover_avl (T, x->esq, k);
			balanceamento (T, x);
		}
	}
	else if (k > x->id){
		if (x->dir != NULL){
			remover_avl (T, x->dir, k);
			balanceamento (T, x);
		}
	}
	else{
		k = x-> id;
		// CASO 1
		if (x->esq == NULL){
			transplante (T, x, x->dir);
		}
		// CASO 2
		else if (x->dir == NULL){
			transplante (T, x, x->esq);
		}
		// CASO 3
		else {
			no* y = minimo (x->dir);
			x->id = y->id;
			x->qnt = y->qnt;
			x->saldo = y->saldo;
			remover_avl(T, x->dir, y->id);
		}
	}
}


int consulta_avl (no* x, int id){ //consulta um nó da avl
	if (x == NULL){	//se não existe, retorna 0
		return 0;
	}
	if (x->id == id){ //se for o nó atual, retorna 1
		return 1;
	}
	else if (x->id > id){ //se for menor, pesquisa à esquerda
		return consulta_avl (x->esq, id); 
	}
	else{//se não, pesquisa à direita
		return consulta_avl (x->dir, id);
	}
}


void listar_avl_crescente(no* x, no* fim){ //lista em ordem crescente
	while(x != NULL){
		printf ("%i %i %i\n", x->id, x->qnt, x->saldo);
		if(x == fim){
			break;
		}
		x = sucessor(x); //utilizando o sucessor
	}
}

void listar_avl_decrescente(no* x, no* fim){ //lista em ordem decrescente
	while(x!=NULL){
		printf ("%i %i %i\n", x->id, x->qnt, x->saldo);
		if(x == fim){
			break;
		}
		x = predecessor(x); //utilizando o predecessor
	}
}


void listar_avl_nivel(no* x, int k){ 
	if(k==0){
		printf ("%i %i %i\n", x->id, x->qnt, x->saldo);
	}
	if(k>0){
		if(x->esq != NULL){
			listar_avl_nivel (x->esq, k-1);
		}
		if(x->dir != NULL){
			listar_avl_nivel (x->dir, k-1);
		}
	}
}

void listar_avl ( no* node_ptr )
{
	if ( node_ptr != NULL )
	{
		printf ( "No = %d, altura = %d, FATBAL = %d\n", node_ptr->id, alt_sub ( node_ptr ), fb ( node_ptr ) );
		listar_avl ( node_ptr->esq );
		listar_avl ( node_ptr->dir );
	}
}
