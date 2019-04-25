#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"

int main(){

	int operacao;
	char ch;

	heap *FILA;

	FILA = fila_cria();


	while(1)
	{

		printf("\nMenu:\n1 - Enfileirar (Push)\n2 - Retirar topo (Pop)\n3 - Mostrar elementos em ordem\n4 - Esvaziar a fila\n5 - Sair\n\nDigite sua operação: ");
		scanf("%d", &operacao);

		switch(operacao)
		{

			case 1:
				printf("\nDigite o valor que será adicionado: ");
				scanf(" %c", &ch);
				fila_insere(&FILA, ch);
				break;

			case 2:
				if(fila_vazia(FILA))
					printf("\nA pilha não tem elementos! Impossível desenfileirar.\n");
				else
				{
					//fila_libera(FILA);
					fila_remove(&FILA);

				}
				break;

			case 3:
				//if(fila_vazia(FILA))
				//	printf("\nA fila não tem elementos!\n");
				//else
					//print_dir(FILA);
					fila_imprime(&FILA);

				break;

			case 4:
				if(fila_vazia(FILA))
					printf("\nA fila não tem elementos! Impossível esvaziá-la.\n");
				else
					fila_libera(FILA);
				//	FILA = fila_cria();
				break;

			case 5:

				exit(0);

			default:
				printf("\nOperação inexistente. Olhe o menu com cuidado!\n");
				break;


		}


	}





	return 0;
}
