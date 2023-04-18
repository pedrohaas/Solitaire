#include <stdlib.h>
#include "Unity/unity.h"
#include "pilha.h"

// Funcoes necessarias para o ambiente de testes unity
void setUp(void){}; 
void tearDown(void){};
//

void teste0() { // Verifica a funcionalidade da função pilhaInicializa

    Pilha stack;
    pilhaInicializa(&stack);

    TEST_ASSERT( stack.topo == 0 ); // Testa a igualdade
    pilhaDestroi(&stack);

}

void teste1() { // Verifica a funcionalidade da função pop/retirar topo

    Pilha stack; pilhaInicializa(&stack);
    T cartas; cartas.naipe = 'O'; cartas.valor = 5; cartas.visivel = 1;

    push(&stack, cartas);
    pop(&stack);
    int verifica = pilhaVazia(&stack);
    pilhaDestroi(&stack);

    TEST_ASSERT_EQUAL(1,verifica);
    
}

void teste2() { // Verifica a funcionalidade da função topo

    Pilha stack; pilhaInicializa(&stack);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;

    push(&stack, cartas[0]);
    push(&stack, cartas[1]);
    push(&stack, cartas[2]);
    int qtd = topo(&stack);

    TEST_ASSERT_EQUAL(3,qtd);
    pilhaDestroi(&stack);

}

void teste3() { // Verifica a funcionalidade da função pilhaTopo

    Pilha stack; pilhaInicializa(&stack);
    T cartas; 
    cartas.naipe = 'O'; cartas.valor = 5; cartas.visivel = 1;
    
    push(&stack, cartas);
    T topo = pilhaTopo(&stack);

    TEST_ASSERT(  topo.naipe == 'O' && topo.valor == 5 && topo.visivel == 1  );
    pilhaDestroi(&stack);

}


void teste4() { // Verifica a funcionalidade da função push/inserir

    Pilha stack; pilhaInicializa(&stack);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; 
    cartas[1].naipe = 'C'; cartas[1].valor = 6; 
    cartas[2].naipe = 'E'; cartas[2].valor = 7; 

    push(&stack, cartas[0]);
    push(&stack, cartas[1]);
    push(&stack, cartas[2]);
    T cartaTopo = pilhaTopo(&stack);
    int qtd = topo(&stack);

    TEST_ASSERT(  cartaTopo.naipe == 'E' && cartaTopo.valor == 7  && qtd == 3 );
    pilhaDestroi(&stack);

}

void teste5() { // Verifica a funcionalidade da função push/inserir

    Pilha stack; pilhaInicializa(&stack);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; 
    cartas[1].naipe = 'C'; cartas[1].valor = 6; 
    cartas[2].naipe = 'E'; cartas[2].valor = 7; 

    push(&stack, cartas[0]);
    push(&stack, cartas[1]);
    push(&stack, cartas[2]);
    push(&stack, cartas[2]);
    push(&stack, cartas[1]);
    push(&stack, cartas[0]);
    pop(&stack); pop(&stack); pop(&stack); pop(&stack); pop(&stack); pop(&stack);
    T cartaTopo = pilhaTopo(&stack);
    int qtd = topo(&stack);
    pilhaDestroi(&stack);

    TEST_ASSERT_MESSAGE(  cartaTopo.valor == 5  && qtd == 0, "Este teste deve falhar!" );
    
}

void teste6() { // 

    

}


int main () { // Realiza a execução dos testes

    UNITY_BEGIN(); // Funcao para iniciar o UNITY

    RUN_TEST(teste0); // Executa o primeiro e os demais testes
    RUN_TEST(teste1);
    RUN_TEST(teste2);
    RUN_TEST(teste3);
    RUN_TEST(teste4);
    RUN_TEST(teste5);
    RUN_TEST(teste6);

    return UNITY_END(); // Funcao para encerrar o UNITY

}