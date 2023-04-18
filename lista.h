// doubly linked list

#ifndef LISTA
#define LISTA

// tipo de dado armazenado nos nós
typedef struct _carta { 
  char naipe;
  int valor;
  int visivel;
} T;

// struct dos nós
typedef struct _node { 
  T data; // os índices 0, 1 e 2 indicam respectivamente, o naipe, o valor e a visibilidade da carta
  struct _node *proximo;
  struct _node *anterior;
} Node;

// cabeçalho da lista (alocado estaticamente pelo usuário em sua aplicação)
// o usário utiliza esse tipo para declarar listas
typedef struct _lista {
  Node *sentinela; // ponteiro para o nó sentinela
} Lista;

// struct do iterador (relaciona o cabeçalho da lista com um de seus nós)
// o usuário utiliza esse tipo para declarar iteradores
typedef struct _iterador {
  Node *node;   // ponteiro para um nó da lista
  Lista *lista; // ponteiro para o cabeçalho da lista
} Iterador;

// FUNÇÕES DA LISTA -----------------------------------

void listaInicializar(Lista *); 
void listaDestruir(Lista *);

// retornam 1 para sucesso e 0 para erro
int listaInserirInicio(Lista *, T);
int listaInserirFim(Lista *, T); 

Iterador listaRemoverElemento(Iterador); 

int comparaDado(T dado1, T dado2);

// retorna a quantidade de nós da lista (fora a sentinela)
int listaQuantidade(Lista *); 

void listaSplit(Iterador, Lista *); 
// primeiro parâmtro: Iterador que indica a lista que será dividade (i.lista) e
// o primeiro nó da cadeia (i.node) segundo parâmetro: Lista declarada pelo
// usuário que recebe os nós separados

void listaAppend(Lista *lista1, Lista *lista2); 
// lista1: será adicionada no final da lista2
// lista2: lista2+lista1;

// FUNÇÕES DO ITERADOR -----------------------------------

Iterador iteradorPrimeiro(Lista *); 
Iterador iteradorUltimo(Lista *);   

int iteradorValido(Iterador); 
T iteradorElemento(Iterador); 

Iterador iteradorProximo(Iterador);  
Iterador iteradorAnterior(Iterador); 

Iterador iteradorProcura(Lista *, T); 

#endif