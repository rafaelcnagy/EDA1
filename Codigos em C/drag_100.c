#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int countC, countG;	
	struct node *prox;
}no;

typedef struct PILHA {
	no *ini;
	no *fim;
} pilha; 

no* criaNo (int countC, int countG){
	no* retorno=malloc(sizeof(no));
	retorno->countC = countC;
	retorno->countG = countG;
	
	return retorno;
}


void inserePilha (pilha *P, no *k) {
    if(P->ini == NULL){
    	P->ini = k;
    	P->fim = k;
    }
    else{
    	P->fim->prox = k;
    	P->fim = k;
    }
}


no* removePilha (pilha *P) {
    no* retorno;
           
    retorno = P->ini;
    if(P->ini == P->fim){
    	P->ini = NULL; P->fim = NULL;
    }
    else{
	    P->ini = P->ini->prox;
    }
   
    return retorno;
}



int main(void){

	int g, cabCort[10], cabNasc[10], i, resp=0;


	scanf(" %i", &g);
	while(g != 0){
		resp = 0;

		int memo[1000];
		for(i=0; i<1000; i++)
			memo[i]=0;

		for(i=0; i<g; i++)
			scanf(" %i", &cabCort[i]);	
		for(i=0; i<g; i++)
			scanf(" %i", &cabNasc[i]);
		
		pilha* P = malloc(sizeof(pilha));
		P->ini = NULL; P->fim = NULL;
	
		no* r = criaNo(100,0);
		inserePilha(P,r);
		
	
		//retorno = removePilha(P);
		//printf("%i %i", retorno->countC, retorno->countG);
		while(P->ini != NULL && resp == 0){
			no* retorno = removePilha(P);

			for(i=0; i<g; i++){
				if(retorno->countC - cabCort[i] == 0){
					resp = retorno->countG + 1;
				}
				if(retorno->countC - cabCort[i] > 0 && memo[retorno->countC - cabCort[i] + cabNasc[i]] == 0 && retorno->countC - cabCort[i] + cabNasc[i] <= 1000){
					no* novo = criaNo(retorno->countC - cabCort[i] + cabNasc[i], retorno->countG+1);
					inserePilha(P, novo);
					memo[retorno->countC - cabCort[i] + cabNasc[i]] = 1;
				}
			}
			free(retorno);
		}
	
		if(resp == 0)
			printf("cavaleiro morreu\n");
		else
			printf("%i\n", resp);
	
		scanf(" %i", &g);	
	}
}