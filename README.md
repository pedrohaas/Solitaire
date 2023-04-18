# Projeto prático em grupo para a disciplina de Estrutura de Dados
Desenvolve-se o jogo de cartas Paciência (_Solitaire_) em C utilizando Pilhas e Listas duplamente encadeadas com sentinela e circular.

## Sobre o desenvolvimento
Elabora-se o jogo de paciência em C utilizando e respeitando o conceito de encapsulamento dos seguintes Tipos Abstratos de Dados (TADs):
* Pilhas dinamicamente alocadas e sequenciais: para armazenar o monte auxiliar de cartas e os montes dos conjuntos de cartas do mesmo naipe;
* Listas cirulares duplamente encadeadas com sentinela e iterador: para armazenar as 7 fileiras de cartas;

## [Documentação](https://lauranaomiseto.github.io/Paciencia/)

### Sobre a nossa Pilha

* <strong> Struct Pilha</strong>: Contem 2 campos, topo, responsável por definir o número do topo da Pilha e *carta, um ponteiro para as posições da Pilha alocada dinamicamente;

* <strong>void pilhaInicializa(Pilha *stack)</strong>: essa função é responsável por inicializar a pilha criada pelo usuário, alocando o espaço para 52 cartas (a quantidade de cartas em um baralho) e definindo o topo da pilha como valor zero;

* <strong>void pilhaDestroi(Pilha *stack)</strong>: função que desaloca a pilha criada usando a função pop;

* <strong>int pilhaVazia(Pilha *stack)</strong>: retorna a comparação entre o topo e o valor inteiro zero, de forma que se a pilha estiver vazia irá retornar o valor na função, caso contrário, o valor zero;

* <strong>void push(Pilha *stack, T item)</strong>: função que coloca um item no topo da pilha, recebe além da pilha, um item do tipo T (vide pilha.h), após colocar o elemento no topo do vetor, o topo é incrementado;

* <strong>void pop(Pilha *stack)</strong>: função que retira o elemento do topo da pilha, ao decrementar o valor de topo, antes faz-se necessário verificar se a pilha já não está vazia usando a função pilhaVazia;

* <strong>T pilhaTopo(Pilha *stack)</strong>: retorna o elemento no topo da pilha, o usuário deve verificar se a pilha não está vazia, caso esteja vazia retorna lixo de memória;

* <strong>void pilhaPrinta(Pilha *stack)</strong>: função responsável por realizar o printf da pilha no terminal.

### Sobre a nossa Lista

* <strong>Struct Lista</strong>: Cabeçalho da lista, cuja alocação deve ser feita de forma estática pelo usuário;

* <strong>Struct Iterador</strong>: Iterador cuja alocação deve ser feita de forma estática pelo usuário;

* <strong>void listaInicializar(Lista *)</strong>: Inicializa a lista alocando o nó sentinela;

* <strong>void listaDestruir(Lista *)</strong>: Desaloca os nós da lista e o sentinela;

* <strong>int listaInserirInicio(Lista *, T)</strong>: Aloca um novo nó com o dado do parâmetro e insere no início da lista. Retorna 1 para sucesso e 0 para erro;

* <strong>int listaInserirFim(Lista *, T)</strong>: Aloca um novo nó com od ado do parâmetro e strongere no final da lista. Retorna 1 para sucesso e 0 para erro;

* <strong>int listaRemoverElemento(Iterador)</strong>: Remove o nó indicado pelo iterador recebido. Retorna um iterador com o próximo nó. O usuário deve verificar se o iterador é válido após o retorno;

* <strong>int comparaDado(T dado1, T dado2)</strong>: Compara dados de dois elementos; 

* <strong>int listaQuantidade(Lista *)</strong>: Conta a quantidade de elementos válidos na lista. Retorna um inteiro;

* <strong>void listaSplit(Iterador, Lista *)</strong>: Separa a lista indicada pelo iterador em duas cadeias. O nó apontado pelo iterador passa a ser o primeiro elemento da segunda cadeia, atribuída na lista indicada pelo segundo parâmetro da função;

* <strong>void listaAppend(Lista *lista1, Lista *lista2)</strong>: Junta duas listas. A lista do primeiro parâmetro é concatenada no final da lista do segundo parâmetro;

* <strong>Iterador iteradorPrimeiro(Lista *)</strong>: Retorna o iterador com o primeiro nó válido da lista;

* <strong>Iterador iteradorUltimo(Lista *)</strong>: Retorna o iterador com o último nó válido da lista;

* <strong>int iteradorValido(Iterador)</strong>: Verifica se o nó apontado pelo iterador é válido, isto é, se o nó não é o sentinela. Retorna 1 para válido e 0 para inváido;

* <strong>T iteradorElemento(Iterador)</strong>: Retorna o dado armazenado no nó indicado pelo iterador;

* <strong>iteradorProximo(Lista*)</strong>: Retorna o iterador posterior ao indicado no parâmetro;

* <strong>Iterador iteradorAnterior(Iterador)</strong>: Retorna o iterador anterior ao indicado no parâmetro;

* <strong>Iterador iteradorProcura(Lista *, T)</strong>: Retorna um iterador com o nó que contém o dado indicado no parâmetro. O usuário deve verificar se o iterador é válido após o retorno.

### Sobre jogo.h e jogo.c
Essas bibliotecas são responsáveis pelas funções relacionadas estritamente ao jogo de paciência, tais como printar no terminal de forma organizada as cartas e também funções utilizadas no desenvolvimento do jogo em si, como comparar as cartas e seus naipes.

## Sobre o jogo
No Paciência, o objetivo é formar quatro conjuntos com as cartas do mesmo naipe. Para isso, é preciso revelar aquelas que estão ocultas nas fileiras, movimentando as demais em ordem decrescente, sendo o Rei (K) a maior e o Ás (A) a menor, e intercalando cores. Há ainda um monte com cartas que podem ser viradas para ajudar na movimentação.

## Sobre os testes unitários
Para a execução dos testes unitários deste projeto foi utilizado o framework unity para testes unitários em c, disponível em http://www.throwtheswitch.org/unity 

testePilha.c: testa as funções da biblioteca pilha.h
testeLista.c: testa as funções da biblioteca lista.h

Para a execução no terminal dos testes deve ser feito da seguinte forma:

Para a pilha:
```
gcc pilha.c testePilha.c Unity/unity.c -o teste1.x
```
```
./teste1.x
```

Para a lista:
```
gcc lista.c testeLista.c Unity/unity.c -o teste2.x
```
```
./teste2.x
```

## Autores:
* Amanda Perina Kouchi
* Beatriz Rogers Tripoli Barbosa
* Laura Naomi Seto
* Pedro Henrique Alves de Araujo Silva
