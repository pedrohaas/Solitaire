#ifndef Pilha_H
#define Pilha_H

#include "lista.h"

typedef struct Pilha {

    T *carta;
    unsigned topo;

} Pilha;

void pilhaInicializa(Pilha *stack); // Inicializa a pilha com topo = 0
void pilhaDestroi(Pilha *stack); // Desaloca a Pilha
void push(Pilha *stack, T item); // Insere um elemento no topo da pilha
void pop(Pilha *stack); // Remove o elemento do topo da pilha
int pilhaVazia(Pilha *stack); // Verifica se a Pilha esta vazia
T pilhaTopo(Pilha *stack); // retorna o elemento no topo da pilha
int topo(Pilha *stack); // retorna o numero de elementos da pilha

#endif
