#include "pilha.h"
#include "lista.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pilhaInicializa(Pilha *stack) { // Inicializa a pilha

  stack->carta = (T*) malloc(52 * sizeof(T));
  stack->topo = 0;

} 

void pilhaDestroi(Pilha *stack) { // desaloca a pilha atraves da chamada da funcao pop enquanto a pilha nao estiver vazia
  while (!pilhaVazia(stack)) {
    pop(stack);
  }
  free(stack->carta);
}

int pilhaVazia(Pilha *stack) { return stack->topo == 0; } // retorna 1 caso a pilha esteja vazia e 0 caso não esteja

void push(Pilha *stack, T item) { // insere um elemento no topo da pilha e incrementa o topo
  stack->carta[stack->topo++] = item;
}

void pop(Pilha *stack) { // retira o elemento do topo da pilha e decrementa o topo
  if (!pilhaVazia(stack)) {
    stack->topo--;
  }
}

T pilhaTopo(Pilha *stack) { // retorna o elemento do topo da pilha
  if (!pilhaVazia(stack)) {
    return stack->carta[stack->topo - 1];
  }
}

int topo(Pilha *stack) { return stack->topo; } // retorna a quantidade de elementos da pilha