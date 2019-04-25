#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "avl.c"


int main(){
		
	arvore* T = criar_avl();
		
	char operacao;
	scanf("%c", &operacao);
	
	while ( operacao != 'f'){ //menu de operação, quando entrar no F, finaliza o processo
		
				
		int id, op, valor, nivel;
		
		if(operacao == 'i'){ //insere o nó
			scanf("%i %i %i", &id, &op, &valor);
			if(op == 1){
				valor *= -1; //negativo se for saque, positivo se for depósito
			}
			no* x = criar_no(id, valor); //cria o nó
			inserir_avl(T, T->raiz, x); //chama a função inserir da avl.c, e insere o nó
		}
			
		else if (operacao == 'c'){ //pesquisa o nó
			scanf("%i", &id);
			if (consulta_avl (T->raiz, id) == 0){ //chama a função consulta, e se o valor for 0, significa que o nó não existe
				printf ("nao ");
			}
			printf ("existe no com chave: %i\n", id); //retorna o valor
		}
			
		else if (operacao == 'r'){ //remove o nó
			scanf(" %i", &id);
			if(consulta_avl (T->raiz, id) == 1){ //chama a função consulta
				remover_avl(T, T->raiz, id); //se existir, remove o nó
			}
		}
		
		else if (operacao == 'p'){ //lista a avl em uma das ordens
			char ordem;
			scanf(" %c", &ordem);
				if(T->raiz != NULL){
				if(ordem == 'c'){ //lista crescente
					listar_avl_crescente (minimo(T->raiz), maximo(T->raiz));
				}
				else if (ordem == 'd'){ // lista decrescente
					listar_avl_decrescente (maximo(T->raiz), minimo(T->raiz));
				}
			}
		}		
			
		else if (operacao == 'n'){ //lista o nível
			scanf(" %i", &nivel);
			if(T->raiz != NULL && alt_sub(T->raiz) >= nivel){
				listar_avl_nivel (T->raiz, nivel-1);
			}
		}
			
		else if (operacao == 'h'){ //informa altura
			if(T->raiz == NULL){
				printf("0\n");				}
			else{
				printf("%i\n", alt_sub (T->raiz));
			}
		}
		scanf(" %c", &operacao);
	}
	
	printf ("-+- Inicio relatorio -+-\n"); //relatório final
	printf ("%i\n", T->qnt_clientes);
	while (T->raiz != NULL){ //imprime e remove os nós da avl
		printf("%i %i %i\n", T->raiz->id, T->raiz->qnt, T->raiz->saldo);
		remover_avl (T, T->raiz, T->raiz->id);
	}
	printf ("-+- Fim relatorio -+-\n");
}
