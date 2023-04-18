#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// FUNÇÕES DA LISTA:

void listaInicializar(Lista *lista) {
  lista->sentinela =
      (Node *)malloc(sizeof(Node)); // aloca um nó na memória e guarda o enderço
                                    // no campo sentinela do cabeçalho da lista
  lista->sentinela->anterior = lista->sentinela->proximo = lista->sentinela;
}

void listaDestruir(Lista *lista) {
  Iterador i = iteradorPrimeiro(lista);
  while (iteradorValido(i)) {
    i = listaRemoverElemento(i);
  }
  free(lista->sentinela);
  lista->sentinela = NULL;
}

int listaInserirInicio(Lista *lista, T dado) {
  Node *novo = (Node *)malloc(sizeof(Node));
  if (!novo)
    return 0;

  novo->data = dado;

  Node *primeiro = lista->sentinela->proximo;
  novo->anterior = lista->sentinela;
  novo->proximo = primeiro;
  primeiro->anterior = novo;
  lista->sentinela->proximo = novo;

  return 1;
}

int listaInserirFim(Lista *lista, T dado) {
  Node *novo = (Node *)malloc(sizeof(Node));
  if (!novo)
    return 0;

  novo->data = dado;

  Node *ultimo = lista->sentinela->anterior;
  novo->anterior = ultimo;
  novo->proximo = lista->sentinela;
  ultimo->proximo = novo;
  lista->sentinela->anterior = novo;

  return 1;
}

Iterador listaRemoverElemento(Iterador i) {
  if (iteradorValido(i)) {
    Node *ant = i.node->anterior;
    Node *prox = i.node->proximo;
    Node *n = i.node;

    ant->proximo = prox;
    prox->anterior = ant;
    i.node = ant->proximo;

    free(n);
  }
  return i;
}

int comparaDado(T dado1, T dado2) {
  return dado1.naipe == dado2.naipe && dado1.valor == dado2.valor && dado1.visivel == dado2.visivel;
}

int listaQuantidade(Lista *lista) {
  Iterador i = iteradorPrimeiro(lista);
  int quantidade = 0;
  while (iteradorValido(i)) {
    quantidade++;
    i = iteradorProximo(i);
  }
  return quantidade;
}

void listaSplit(Iterador i, Lista *lista) {
  Node *p = i.lista->sentinela->anterior; 
  Node *q = i.node->anterior; 

  lista->sentinela->anterior = i.lista->sentinela->anterior;
  lista->sentinela->proximo = i.node; 
  
  p->proximo = lista->sentinela;
  i.node->anterior = lista->sentinela;

  i.lista->sentinela->anterior = q;

  q->proximo = i.lista->sentinela;
}

void listaAppend(Lista *lista1, Lista *lista2) {
  Node *p = lista1->sentinela->proximo;
  Node *q = lista2->sentinela->anterior;

  q->proximo = p;
  p->anterior = q;

  Node *r = lista1->sentinela->anterior;
  lista2->sentinela->anterior = r;
  r->proximo = lista2->sentinela;

  lista1->sentinela->anterior = lista1->sentinela->proximo = lista1->sentinela;
}

// FUNÇÕES DO ITERADOR:

Iterador iteradorPrimeiro(Lista *lista) {
  Iterador i;
  i.lista = lista;
  i.node = lista->sentinela->proximo;
  return i;
}
Iterador iteradorUltimo(Lista *lista) {
  Iterador i;
  i.lista = lista;
  i.node = lista->sentinela->anterior;
  return i;
}

int iteradorValido(Iterador i) { return i.node != i.lista->sentinela; }

T iteradorElemento(Iterador i) { return i.node->data; }

Iterador iteradorProximo(Iterador i) {
  Iterador j;
  j.lista = i.lista;
  j.node = i.node->proximo;
  return j;
}

Iterador iteradorAnterior(Iterador i) {
  Iterador j;
  j.lista = i.lista;
  j.node = i.node->anterior;
  return j;
}

Iterador iteradorProcura(Lista *lista, T dado) {
  Iterador j = iteradorPrimeiro(lista);
  while (iteradorValido(j)) {
    if (comparaDado(j.node->data, dado)) {
      break;
    } else {
      j = iteradorProximo(j);
    }
  }
  return j; // retorna ou um válido (achou) ou o sentinela (não achou)
}
