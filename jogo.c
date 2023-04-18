#include "lista.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void printaCarta(T carta) {
  if ((2 <= carta.valor) && (carta.valor <= 10)) {
    printf("[%c  %02d] ", carta.naipe, carta.valor);
  } else {
    switch (carta.valor) {
    case 1: {
      printf("[%c   A] ", carta.naipe);
      break;
    }
    case 11: {
      printf("[%c   J] ", carta.naipe);
      break;
    }
    case 12: {
      printf("[%c   Q] ", carta.naipe);
      break;
    }
    case 13: {
      printf("[%c   K] ", carta.naipe);
      break;
    }
    }
  }
}

int inserePilhaF(Pilha *pilha, T carta) {
  if (pilhaVazia(pilha)) {
    if (carta.valor != 1) {
      return 0;
    } else {
      push(pilha, carta);
      return 1;
    }
  } else {
    if (carta.valor != pilhaTopo(pilha).valor + 1) {
      return 0;
    } else {
      push(pilha, carta);
      return 1;
    }
  }
}

void mudaVisibilidade(Lista *fileira) {
  T n;
  n = iteradorElemento(iteradorUltimo(fileira));
  n.visivel = 1;
  listaRemoverElemento(iteradorUltimo(fileira));
  listaInserirFim(fileira, n);
}

void printarFileira(Lista *fileira) {
  if (listaQuantidade(fileira) == 0) {
    printf("[    ] ");
  } else {
    for (Iterador i = iteradorPrimeiro(fileira); iteradorValido(i);
         i = iteradorProximo(i)) {
      if (iteradorElemento(i).visivel) {
        printaCarta(iteradorElemento(i));
      } else if (!iteradorElemento(i).visivel) {
        printf("[  #  ] ");
      }
    }
  }
  printf("\n");
}

void criaBaralho(T cartas[]) {
  for (int i = 0, j = 1; i < 52; i++, j++) {
    if (j > 13) {
      j = 1;
    }
    cartas[i].valor = j;
    cartas[i].visivel = 0;
    if ((i >= 0) && (i <= 12)) {
      cartas[i].naipe = 'C'; // ♥
    }
    if ((i >= 13) && (i <= 25)) {
      cartas[i].naipe = 'P'; // ♣
    }
    if ((i >= 26) && (i <= 38)) {
      cartas[i].naipe = 'O'; // ♦
    }
    if ((i >= 39) && (i <= 51)) {
      cartas[i].naipe = 'E'; // ♠
    }
  }
}

void inicializaJogo(Lista fileiras[], Pilha *virada, Pilha *visivel,Pilha finais[]) {
  pilhaInicializa(virada);
  pilhaInicializa(visivel);
  for (int i = 0; i < 4; i++) {
    pilhaInicializa(&finais[i]);
  }
  for (int i = 0; i < 7; i++) {
    listaInicializar(&fileiras[i]);
  }
}

void fimJogo(Lista fileiras[], Pilha *virada, Pilha *visivel, Pilha finais[], Lista aux) {
  for (int i = 0; i < 7; i++) {
    listaDestruir(&fileiras[i]);
  }

  pilhaDestroi(virada);
  pilhaDestroi(visivel);
  for (int i = 0; i < 4; i++) {
    pilhaDestroi(&finais[i]);
  }
}

void preparaMesa(Lista fileiras[], Pilha *virada, T cartas[]) {

  // Vai inserir um total de 28 cartas distribuidas pelas filas, com a primeira
  // tendo 1 carta, a segunda tendo 2, etc
  for (int i = 0, j = 0; i < 28; i++) {
    if ((i == 1) || (i == 3) || (i == 6) || (i == 10) || (i == 15) ||
        (i == 21)) {
      j++;
    }
    listaInserirFim(&fileiras[j], cartas[i]);
  }
  // Insere o restante das cartas na pilha virada
  for (int i = 28; i < 52; i++) {
    cartas[i].visivel = 1;
    push(virada, cartas[i]);
  }

  for (int i = 0; i < 7; i++) {
    mudaVisibilidade(&fileiras[i]);
  }
}

void printaMesa(Lista fileiras[], Pilha *virada, Pilha *visivel, Pilha pilhasF[]) {

  printf("\n\n---------------------------------------------------------------------------------------\n\n");

  printf("Pilhas Finais:\n");
  for (int i = 0; i < 4; i++) {
    T cartaTopo = pilhaTopo(&pilhasF[i]);
    if (!pilhaVazia(&pilhasF[i])) {
      printaCarta(cartaTopo);
    } else {
      switch (i) {
      case 0: {
        printf("|  C  | ");
        break;
      }
      case 1: {
        printf("|  O  | ");
        break;
      }
      case 2: {
        printf("|  P  | ");
        break;
      }
      case 3: {
        printf("|  E  | ");
        break;
      }
      }
    }
  }  

  printf("\n\n---------------------------------------------------------------------------------------\n\n");

  for (int i = 0; i < 7; i++) {
      printf("Fileira %d:\n", i + 1);
      printarFileira(&fileiras[i]);
    }
  
  printf("\n\n---------------------------------------------------------------------------------------\n\n");
  
  printf("Deque virado:        Deque visivel:\n");
  if (!pilhaVazia(virada)) {
    printf("  [  #  ]               ");
  } else {
    printf("  [     ]               ");
  }

  //printf("Deque visivel:\n");
  if (!pilhaVazia(visivel)) {
    T cartaTopo = pilhaTopo(visivel);
    printaCarta(cartaTopo);
  } else {
    printf("[     ] ");
  }

  printf("\n\n---------------------------------------------------------------------------------------\n");

  
}

void printaBaralho(T cartas[]) {
  for (int i = 0; i < 52; i++) {
    printaCarta(cartas[i]);
  }
  printf("\n");
}

void pilhaPrinta(Pilha *stack) {
  int aux = stack->topo - 1;
  printf("Pilha:\n");
  while (aux >= 0) {
    printaCarta(stack->carta[aux]);
    aux--;
  }
  printf("\n");
}

int comparaNaipe(T carta1, T carta2) { return carta1.naipe == carta2.naipe; }

int comparaCor(T carta1, T carta2) {
  if (carta1.naipe == 'O' && carta2.naipe == 'C' ||
      carta1.naipe == 'C' && carta2.naipe == 'O' ||
      carta1.naipe == 'E' && carta2.naipe == 'P' ||
      carta1.naipe == 'P' && carta2.naipe == 'E' ||
      carta1.naipe == carta2.naipe) {
    return 1;
  } else {
    return 0;
  }
}