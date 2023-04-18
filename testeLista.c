#include "Unity/unity.h"
#include "pilha.h"

void setUp(void){};
void tearDown(void){};

void teste0() {

    Lista lista; 
    listaInicializar(&lista);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);

    TEST_ASSERT_EQUAL(7, lista.sentinela->proximo->data.valor);
    listaDestruir(&lista);

}

void teste1() {

    Lista lista; 
    listaInicializar(&lista);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;

    listaInserirFim(&lista, cartas[0]);
    listaInserirFim(&lista, cartas[1]);
    listaInserirFim(&lista, cartas[2]);

    TEST_ASSERT_EQUAL(7, lista.sentinela->anterior->data.valor);
    listaDestruir(&lista);

}

void teste2() {

    Lista lista; 
    listaInicializar(&lista);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);

    listaDestruir(&lista);

    TEST_ASSERT( lista.sentinela == NULL);
}

void teste3() {

    Lista lista; 
    listaInicializar(&lista);

    T cartas[3]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    int qtd = listaQuantidade(&lista);

    TEST_ASSERT_EQUAL(3, qtd);
    listaDestruir(&lista);

}

void teste4() {

    Lista lista; 
    listaInicializar(&lista);

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    int qtd = listaQuantidade(&lista);

    TEST_ASSERT_EQUAL(3, qtd);
    listaDestruir(&lista);

}

void teste5() {

    Lista lista, listaReserva; 
    listaInicializar(&lista); listaInicializar(&listaReserva);

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorProcura(&lista, cartas[2]);

    listaSplit(i, &listaReserva);

    int qtd = listaQuantidade(&lista);
    int qtdReserva = listaQuantidade(&listaReserva);

    TEST_ASSERT( qtd == 1 && qtdReserva == 3 );
    listaDestruir(&lista); listaDestruir(&listaReserva);

}

void teste6() {

    Lista lista, listaReserva; 
    listaInicializar(&lista); listaInicializar(&listaReserva);

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[2].naipe = 'P'; cartas[2].valor = 8; cartas[2].visivel = 0;

    T cartasReserva[4]; 
    cartas[0].naipe = 'P'; cartas[0].valor = 1; cartas[0].visivel = 1;
    cartas[1].naipe = 'E'; cartas[1].valor = 2; cartas[1].visivel = 0;
    cartas[2].naipe = 'C'; cartas[2].valor = 3; cartas[2].visivel = 1;
    cartas[2].naipe = 'O'; cartas[2].valor = 4; cartas[2].visivel = 0;


    listaInserirFim(&lista, cartas[0]); listaInserirFim(&listaReserva, cartasReserva[0]);
    listaInserirFim(&lista, cartas[1]); listaInserirFim(&listaReserva, cartasReserva[1]);
    listaInserirFim(&lista, cartas[2]); listaInserirFim(&listaReserva, cartasReserva[2]);
    listaInserirFim(&lista, cartas[3]); listaInserirFim(&listaReserva, cartasReserva[3]);

    listaAppend(&listaReserva, &lista);

    int qtd = listaQuantidade(&lista);

    TEST_ASSERT_EQUAL(8, qtd);
    listaDestruir(&lista); listaDestruir(&listaReserva);

}

void teste7() {

    Lista lista, listaReserva; 
    listaInicializar(&lista); listaInicializar(&listaReserva);

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorProcura(&lista, cartas[2]);
    
    listaSplit(i, &listaReserva);
    listaAppend(&listaReserva, &lista);

    int qtd = listaQuantidade(&lista);

    TEST_ASSERT( qtd == 4 );
    listaDestruir(&lista); listaDestruir(&listaReserva);

}

void teste8() {

    Lista lista; 
    listaInicializar(&lista); 

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;


    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorPrimeiro(&lista);

    
    TEST_ASSERT( i.node->data.valor == 8 );
    listaDestruir(&lista);

}

void teste9() {

    Lista lista; 
    listaInicializar(&lista);

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorUltimo(&lista);

    TEST_ASSERT( i.node->data.valor == 5 );
    listaDestruir(&lista);

}

void teste10() {

    Lista lista; 
    listaInicializar(&lista); 

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;

    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorPrimeiro(&lista);
    Iterador j = iteradorProximo(i);
    Iterador k = iteradorProximo(j);
    
    TEST_ASSERT( k.node->data.valor == 6 );
    listaDestruir(&lista);

}

void teste11() {

    Lista lista; 
    listaInicializar(&lista); 

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;


    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorPrimeiro(&lista);
    Iterador j = iteradorProximo(i);
    Iterador k = iteradorProximo(j);
    Iterador n = iteradorAnterior(k);
    
    TEST_ASSERT( n.node->data.valor == 7 );
    listaDestruir(&lista);

}

void teste12() {

    Lista lista; 
    listaInicializar(&lista); 

    T cartas[4]; 
    cartas[0].naipe = 'O'; cartas[0].valor = 5; cartas[0].visivel = 1;
    cartas[1].naipe = 'C'; cartas[1].valor = 6; cartas[1].visivel = 0;
    cartas[2].naipe = 'E'; cartas[2].valor = 7; cartas[2].visivel = 1;
    cartas[3].naipe = 'P'; cartas[3].valor = 8; cartas[3].visivel = 0;


    listaInserirInicio(&lista, cartas[0]);
    listaInserirInicio(&lista, cartas[1]);
    listaInserirInicio(&lista, cartas[2]);
    listaInserirInicio(&lista, cartas[3]);

    Iterador i = iteradorProcura(&lista, cartas[2]);
    
    
    TEST_ASSERT( i.node->data.valor == 7 );
    listaDestruir(&lista);

}



int main () { // Realiza a execução dos testes

    UNITY_BEGIN();

    RUN_TEST(teste0);
    RUN_TEST(teste1);
    RUN_TEST(teste2);
    RUN_TEST(teste3);
    RUN_TEST(teste4);
    RUN_TEST(teste5);
    RUN_TEST(teste6);
    RUN_TEST(teste7);
    RUN_TEST(teste8);
    RUN_TEST(teste9);
    RUN_TEST(teste10);
    RUN_TEST(teste11);
    RUN_TEST(teste12);

    return UNITY_END();
}