#ifndef Jogo_H
#define Jogo_H

#include "lista.h"
#include "pilha.h"


void printarFileira(Lista *); // ok

void mudaVisibilidade(Lista *fileira);

int inserePilhaF(Pilha *pilha, T carta);

// Escreve as 52 cartas, 13 de cada naipe todas viradas pra baixo a principio
void criaBaralho(T cartas[]);
// Inicializa as listas e as pilhas usadas no jogo
void inicializaJogo(Lista fileiras[], Pilha *virada, Pilha *visivel, Pilha finais[]);
// Destroi as listas e as pilhas usadas no jogo
void fimJogo(Lista fileiras[], Pilha *virada, Pilha *visivel, Pilha finais[]);
// Prepara a mesa de paciencia
void preparaMesa(Lista fileiras[], Pilha *virada, T cartas[]);
// Imprime a mesa com as filas e cartas
void printaMesa(Lista fileiras[], Pilha *virada, Pilha *visivel, Pilha pilhasF[]);
// Imprime uma carta
void printaCarta(T carta);
// Imprime o vetor cartas
void printaBaralho(T cartas[]);

void printaPilha(Pilha *stack);
// Compara os naipes das cartas
int comparaNaipe(T carta1, T carta2);
// Compara a cor das cartas
int comparaCor(T carta1, T carta2);

#endif