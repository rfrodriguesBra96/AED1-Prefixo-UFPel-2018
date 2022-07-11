CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDLIBS=-lm

.PHONY: pilha fila all clean


all: test
	./test


pilha.o: pilha.c
fila.o: fila.c
# coloque outras dependencias aqui


test: pilha.o fila.o calc.o test.c




clean:
	rm -f *.o test

