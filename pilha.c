#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct stack *create_stack(int tam){
	struct stack *s = NULL;
	
	s = (struct stack*)malloc(sizeof(struct stack));
	
	if(s == NULL){
		return NULL;
	}
	
	s->topo = -1;
	s->capacidade = tam;
	s->array = (int*)malloc(tam * sizeof(int));
	
	if(s->array == NULL){
		return NULL;
	}
	
	return s;
}

int stackIsEmpty(struct stack *s){
	if(s == NULL){
		return 0;
	}
	if(s->topo == -1){
		return 1;
	}
		return 0;
}

int isFull(struct stack *s){
	if(s == NULL){
		return 0;
	}
	if(s->topo == s->capacidade-1){
		return 1;
	}
		return 0;
}

int peek(struct stack *s){
	if(s == NULL){
		return 0;
	}
	if(stackIsEmpty(s) == 1){
		return 0;
	}
		return s->array[s->topo];
}

int pop(struct stack *s){
	if(s == NULL){
		return 0;
	}
	if(stackIsEmpty(s) == 1){
		return 0;
	}
	s->topo -= 1;
		return 1;
}

int push(struct stack *s, int val){
	if(s == NULL){
		return 1;
	}
	if(isFull(s) == 1){
		return 0;
	}
	s->topo += 1;
	s->array[s->topo] = val;
		return 1;
}

// Simplesmente para testes... ... ...
/*int main(){
	STACK *p;
	p = create_stack(10);
	push(p,71);
	printf("%c\n", peek(p));
}*/