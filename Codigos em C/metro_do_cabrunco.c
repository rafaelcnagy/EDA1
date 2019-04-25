#include <stdlib.h>
#include <stdio.h>


typedef struct node{
	int pos;	
	struct node *prox;
}no;

typedef struct PILHA {
	no *ini;
	no *fim;
} pilha; 

no* criaNo (int pos){
	no* retorno=malloc(sizeof(no));
	retorno->pos = pos;
	
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



int main(){

	int t, q, i, j;
	scanf(" %i %i", &t, &q);
	while(t != 0 && q != 0){

		int pos[t], ward = 0;



		for(i=0; i<t; i++){
			scanf(" %i", &pos[i]);
		}
		for(j=0; j<q; j++){
			int s, d;
			scanf(" %i %i", &s, &d);
		
			pilha* P = malloc(sizeof(pilha));
			P->ini = NULL; P->fim = NULL;
			
			no* r = criaNo(s);
			inserePilha(P,r);
			
			int resp=0;


			int memais[10000001]={}, memenos[10000001]={};

			while(P->ini != NULL && resp == 0){
				no* retorno = removePilha(P);
				//printf("GOGO %i\n", retorno->pos);
				for(i=0; i<t; i++){

					int aux = 2*pos[i] - retorno->pos;
					
					if(aux == d){
						resp=1;
						break;
					}
					
					if(aux>=0 && aux<=10000000 && memais[aux] == 0 || aux<0 && aux >= -10000000 && memenos[-aux] == 0){
						if(aux>=0)
							memais[aux]=1;
						else
							memenos[-aux]=1;
						no* novo = criaNo(aux);
						inserePilha(P,novo);
					}
					
				}
				//free(retorno);
			}


			if(ward == 0)
				ward=1;
			else
				printf(" ");

			if(resp == 1)
				printf("Y");
			else
				printf("N");			
		}
		printf("\n");

		scanf(" %i %i", &t, &q);
	}
}