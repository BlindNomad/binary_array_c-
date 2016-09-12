/* 
 * File:   main.cpp
 * Author: thiago
 *
 * Created on 30 de Agosto de 2016, 16:19
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>


#include "Test.h"
#include "BinaryTreeArray.h"

using namespace std;

/*
 * 
 */

void printValue(void *value) {
    Test *folha;

    folha = (Test *) value;

    printf("Folha %llu\n", folha->getId());

    delete(folha);

}

int main(int argc, char** argv) {

    Test *test;

    unsigned long long int checkId[10000];

    BinaryTreeArray binaryArray;

    test = new Test();
    test->setId(16);
    binaryArray.Add(test, 16, false);

    for (int i = 0; i < 10; i++) {
        test = new Test();
        test->setId(rand() % 15);
        checkId[i] = test->getId();
        if (!binaryArray.Add(test, test->getId(), false)) {
            delete(test);
        } else {

            printf("Inserido %llu\n", test->getId());
        }
    }

    Test *folhaS;

    for (int i = 0; i < 10; i++) {

        folhaS = (Test*) binaryArray.search(checkId[i]);
        if (folhaS == NULL) {
            printf("Erro ao buscar id: %llu\n", checkId[i]);
            exit(0);
        }
    }


    long long int tmpBusca;

    do {
        printf("---------------------------------------------\n");

        printf("Digite o id: ");
        scanf("%llu", &tmpBusca);
        printf("\n");

        folhaS = (Test *) binaryArray.search(tmpBusca);

        if (folhaS == NULL) {
            printf("Folha nao encontrada\n");
        } else {
            printf("Encontrado %llu\n", folhaS->getId());
        }
    } while (tmpBusca > 0);

    binaryArray.forEach(&printValue);

    binaryArray.free();

    return 0;
}

