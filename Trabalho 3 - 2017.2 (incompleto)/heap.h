#ifndef HEAP_H_
#define HEAP_H_


typedef struct HEAP heap;

heap* fila_cria();
void fila_insere(heap **FILA, char ch);
int fila_vazia(heap *FILA);
void fila_imprime(heap **FILA);
void fila_remove(heap **FILA);
void fila_libera(heap *FILA);
void ordem(heap **FILA, int pos);
void min_heapify(heap **FILA, int pos);
int fila_quantidade(heap *FILA);
int search_node(heap *FILA, char ch, int *x);
void remove_top(heap **FILA, int qtd);
heap* get_last(heap **FILA, int qtd);

#endif
