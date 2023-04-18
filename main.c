#include "jogo.h"
#include "lista.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Troca duas posicoes de vetores
void swap(T vetor[], int i, int j) {
  T aux;

  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;

  return;
}

void aleatoriza(T vetor[], int n) {
  for (int i = 0; i < n; i++) {

    int j = i + rand() % (n - i);

    swap(vetor, i, j);
  }
}

int main(int argc, char const *argv[]) {
  T cartas[52];
  time_t tempo;
  // Semente para aleatorizar os vetores
  srand((unsigned)time(&tempo));

  criaBaralho(cartas);

  // 6 pilhas: uma pro jogador virar as cartas, outra pro jogador pegar as
  // cartas viradas, e uma pra cada naipe
  Pilha pilhaVirada, pilhaVisivel, pilhasF[4];
  // 7 fileiras na mesa cada uma comecando com o numero d cartas do seu numero
  Lista fileiras[7];

  aleatoriza(cartas, 52);

  inicializaJogo(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);

  preparaMesa(fileiras, &pilhaVirada, cartas);

  printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
  int op, fileira1, fileira2, pilha, desistir = 0;
  T cartaTemp, cartaAux;
  Lista aux;
  listaInicializar(&aux);
  while (!desistir) {
    op = 0;
    
    printf("O que deseja fazer?\n1- Operacao nas fileiras.\n2- Operacao nos "
           "deques.\n3- Desistir do jogo.\n");
    scanf("%d", &op);
    switch (op) {

      case 1: {
        printf("Selecione uma das fileiras: 1-7\n");
        scanf("%d", &fileira1);
        if (fileira1 > 7 || fileira1 < 1) {
          printf("Opcao invalida!\n");
          break;
        }
        if (listaQuantidade(&fileiras[fileira1 - 1]) == 0) {
          printf("Esta fileira esta vazia!");
          break;
        }
        printf("Qual carta da fileira %d voce deseja selecionar?\nDigite a "
               "primeira letra do naipe da carta seguida do seu valor numerico "
               "separados por espaco:\n",
               fileira1);
        scanf(" %c %d", &cartaTemp.naipe, &cartaTemp.valor);
        cartaTemp.visivel = 1;
        while (!iteradorValido(
            iteradorProcura(&fileiras[fileira1 - 1], cartaTemp))) {
          printf("Esta carta, [%c  %02d], nao esta visivel. Escolha outra.\n",
                 cartaTemp.naipe, cartaTemp.valor);
          scanf(" %c %d", &cartaTemp.naipe, &cartaTemp.valor);
        }
        printf("Para onde voce deseja mover essa carta?\n1- Mover para "
               "fileira.\n2- Mover para pilha.\n");
        
        op = 0;
        while ((op != 1) && (op != 2)) {
          scanf("%d", &op);
          if ((op != 1) && (op != 2)) {
            printf("Essa opcao eh invalida. Escolha novamente.\n");
          }
        }
  
        switch (op) {
  
          case 1: {
            printf("Selecione uma das fileiras: 1-7\n");
            scanf("%d", &fileira2);
            if (fileira2 > 7 || fileira2 < 1) {
              printf("Opcao invalida!\n");
              break;
            }
            if (listaQuantidade(&fileiras[fileira2 - 1]) != 0) {
              cartaAux = iteradorElemento(iteradorUltimo(&fileiras[fileira2 - 1]));
              if (comparaCor(cartaTemp, cartaAux)) {
                printf("Movimento invalido! Motivo: Mesma cor de naipe.\n");
                break;
              } else {
                if (cartaTemp.valor != cartaAux.valor - 1) {
                  printf("Movimento invalido! Motivo: Valores de cartas nao sequenciais.\n");
                  break;
                } else {
                  listaSplit(iteradorProcura(&fileiras[fileira1 - 1], cartaTemp),
                             &aux);
                  listaAppend(&aux, &fileiras[fileira2 - 1]);
                  if(listaQuantidade(&fileiras[fileira1-1]) != 0){
                    cartaAux = iteradorElemento(iteradorUltimo(&fileiras[fileira1 - 1]));
                    if (!(cartaAux.visivel)) {
                      mudaVisibilidade(&fileiras[fileira1 - 1]);
                    }
                  }
                }
              }
            } else if (listaQuantidade(&fileiras[fileira2 - 1]) == 0){
              if (cartaTemp.valor == 13) {
                listaSplit(iteradorProcura(&fileiras[fileira1 - 1], cartaTemp), &aux);
                listaAppend(&aux, &fileiras[fileira2 - 1]);
                if(listaQuantidade(&fileiras[fileira1-1]) != 0){
                  cartaAux = iteradorElemento(iteradorUltimo(&fileiras[fileira1 - 1]));
                  if (!(cartaAux.visivel)) {
                    mudaVisibilidade(&fileiras[fileira1 - 1]);
                  }
                }
              } else {
                printf("Somente reis podem ser inseridos em fileiras vazias!\n");
                break;
              }
            }
            printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
            break;
          }
    
          case 2: {
            if (comparaDado(iteradorElemento(iteradorUltimo(&fileiras[fileira1-1])), cartaTemp)) {
            switch (cartaTemp.naipe) {
    
              case 'C': {
                if (inserePilhaF(&pilhasF[0], cartaTemp)) {
                  listaRemoverElemento(iteradorUltimo(&fileiras[fileira1 - 1]));
                  if(listaQuantidade(&fileiras[fileira1-1]) != 0){
                    mudaVisibilidade(&fileiras[fileira1 - 1]);
                  }
                  break;
                } else {
                  printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                }
                break;
              }
      
              case 'O': {
                if (inserePilhaF(&pilhasF[1], cartaTemp)) {
                  listaRemoverElemento(iteradorUltimo(&fileiras[fileira1 - 1]));
                  if(listaQuantidade(&fileiras[fileira1-1]) != 0){
                    mudaVisibilidade(&fileiras[fileira1 - 1]);
                  }
                  break;
                } else {
                  printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                }
                break;
              }
      
              case 'P': {
                if (inserePilhaF(&pilhasF[2], cartaTemp)) {
                  listaRemoverElemento(iteradorUltimo(&fileiras[fileira1 - 1]));
                  if(listaQuantidade(&fileiras[fileira1-1]) != 0){
                    mudaVisibilidade(&fileiras[fileira1 - 1]);
                  }
                  break;
                } else {
                  printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                }
                break;
              }
      
              case 'E': {
                if (inserePilhaF(&pilhasF[3], cartaTemp)) {
                  listaRemoverElemento(iteradorUltimo(&fileiras[fileira1 - 1]));
                  if(listaQuantidade(&fileiras[fileira1-1]) != 0){
                    mudaVisibilidade(&fileiras[fileira1 - 1]);
                  }
                  break;
                } else {
                  printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                }
                break;
              }
              
            }
            printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
            break;

          } else {
            printf("Nao eh possivel colocar essa carta nas pilhas!\n");
            printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
          }
          }
          
        }
  
        break;
      }
  
      case 2: {
        printf("1- Virar carta.\n2- Pegar carta.\n");
        scanf("%d", &pilha);
        while ((pilha != 1) && (pilha != 2)) {
          printf("Opcao invalida!");
          printf("1- Virar carta.\n2- Pegar carta.\n");
          scanf("%d", &pilha);
        }
        switch (pilha) {
  
          case 1: {
            if (pilhaVazia(&pilhaVirada)) {
              while (!pilhaVazia(&pilhaVisivel)) {
                push(&pilhaVirada, pilhaTopo(&pilhaVisivel));
                pop(&pilhaVisivel);
              }
              printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
              break;
            }
            push(&pilhaVisivel, pilhaTopo(&pilhaVirada));
            pop(&pilhaVirada);
            printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
            break;
          }
    
          case 2: {
            if (pilhaVazia(&pilhaVisivel)) {
              printf("O Deque Visivel esta vazio!\n");
              break;
            }
            printf("Vai querer colocar a carta em\n1- Pilha?\n2- Fileira?\n");
            scanf("%d", &op);
            while ((op != 1) && (op != 2)) {
              printf("Opcao invalida!");
              printf("Vai querer colocar a carta em\n1- Pilha?\n2- Fileira?\n");
              scanf("%d", &op);
            }
            cartaTemp = pilhaTopo(&pilhaVisivel);
            switch (op) {
    
              case 1: {
                switch (cartaTemp.naipe) {
                  
                  case 'C': {
                    if (inserePilhaF(&pilhasF[0], cartaTemp)) {
                      pop(&pilhaVisivel);
                      break;
                    } else {
                      printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                    }
                    break;
                  }
                  
                  case 'O': {
                    if (inserePilhaF(&pilhasF[1], cartaTemp)) {
                      pop(&pilhaVisivel);
                      break;
                    } else {
                      printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                    }
                    break;
                  }
                  
                  case 'P': {
                    if (inserePilhaF(&pilhasF[2], cartaTemp)) {
                      pop(&pilhaVisivel);
                      break;
                    } else {
                      printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                    }
                    break;
                  }
                  
                  case 'E': {
                    if (inserePilhaF(&pilhasF[3], cartaTemp)) {
                      pop(&pilhaVisivel);
                      break;
                    } else {
                      printf("Nao eh possivel colocar essa carta nas pilhas!\n");
                    }
                    break;
                  }
                  
                }
                printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
                break;
              }
      
              case 2: {
                printf("Selecione uma fileira 1-7:\n");
                scanf("%d", &fileira2);
                if (listaQuantidade(&fileiras[fileira2 - 1]) != 0) {
                  cartaAux =
                      iteradorElemento(iteradorUltimo(&fileiras[fileira2 - 1]));
                  if (comparaCor(cartaTemp, cartaAux)) {
                    printf("Movimento invalido! Motivo: Mesma cor de naipe.\n");
                    break;
                  } else {
                    if (cartaTemp.valor == cartaAux.valor - 1) {
                      pop(&pilhaVisivel);
                      listaInserirFim(&fileiras[fileira2 - 1], cartaTemp);
                    } else {
                      printf("Movimento invalido! Motivo: Valores de cartas nao sequenciais.\n");
                      break;
                    }
                  }
                } else if (listaQuantidade(&fileiras[fileira2 - 1]) == 0){
                  if (cartaTemp.valor == 13) {
                    listaInserirInicio(&fileiras[fileira2 - 1], cartaTemp);
                    pop(&pilhaVisivel);
                  } else {
                    printf("Somente reis podem ser inseridos em fileiras vazias!\n");
                    break;
                  }
                }
                printaMesa(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
                break;
              }
              
            }
            break;
          }
          
        }
        break;
      }
  
      case 3: {
        desistir = 1;
        break;
      }
  
      default: {
        printf("Opcao invalida!\n");
        break;
      }
    
    }
    
    if (pilhaVazia(&pilhaVirada) && pilhaVazia(&pilhaVisivel)) {
      int vazias = 1;
      for (int i = 0; i < 7; i++) {
        if (listaQuantidade(&fileiras[i]) != 0) {
          vazias = 0;
        }
      }
      if (vazias) {
        printf("Parabens! Voce terminou o jogo!!!\n");
        desistir = 1;
      }
    }
    
  }
  
  fimJogo(fileiras, &pilhaVirada, &pilhaVisivel, pilhasF);
  listaDestruir(&aux);


  return (0);
}
