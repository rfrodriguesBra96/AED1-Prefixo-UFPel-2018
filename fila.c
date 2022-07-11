#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila *create_fila(int cap){
	struct fila *f = NULL;
	f = (struct fila*)malloc(sizeof(struct fila));
	if(f == NULL){
		return NULL;
	}
	f->inicio = 0;
	f->tam = 0;
	f->capacidade = cap;
	f->array = (int*)malloc(cap * sizeof(int));
	if(f->array == NULL){
		return NULL;
	}
		return f;
}

int tamanho_fila(FILA *f){
	return f->tam;
}

void exibirFila(FILA *f){
	int i = f->inicio;
	int temp;
	for(temp = 0; temp < f->tam; temp++){
		printf("%c", f->array[i]);
		i = (i+1) % f->capacidade; /* Verifica se não estrapolou o tamanho do array. */
	}
}

int insereFila(FILA *f, int val){
	if(f->tam >= f->capacidade){
		return 0;
	}
	int pos = (f->inicio + f->tam) % f->capacidade;
	f->array[pos] = val;
	f->tam++;
	return 1;
}

int excluirElemFila(FILA *f){
	if(f->tam == 0){
		return 0;
	}
	f->inicio = (f->inicio + 1) % f->capacidade;
	f->tam--;
	return 1;
}

int filaIsEmpty(FILA *f){
	if(f->tam == 0){
		return 1;
	}
		return 0;
}