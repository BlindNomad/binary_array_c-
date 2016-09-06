/* 
 * File:   main.cpp
 * Author: thiago
 *
 * Created on 30 de Agosto de 2016, 16:19
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>


#include "FolhaTeste.h"
#include "BinaryTreeArray.h"

using namespace std;

/*
 * 
 */

void printValue(void *value) {
    FolhaTeste *folha;

    folha = (FolhaTeste *) value;

    printf("Folha %llu\n", folha->getId());

    delete(folha);

}

int main(int argc, char** argv) {

    FolhaTeste *folha;

    unsigned long long int checkId[10000];

    BinaryTreeArray binaryArray;

    folha = new FolhaTeste();
    folha->setId(16);
    binaryArray.Add(folha, 16, false);

    for (int i = 0; i < 10; i++) {
        folha = new FolhaTeste();
        folha->setId(rand() % 15);
        checkId[i] = folha->getId();
        if (!binaryArray.Add(folha, folha->getId(), false)) {
            delete(folha);
        } else {

            printf("Inserido %llu\n", folha->getId());
        }
    }

    FolhaTeste *folhaS;

    for (int i = 0; i < 10; i++) {

        folhaS = (FolhaTeste*) binaryArray.search(checkId[i]);
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

        folhaS = (FolhaTeste *) binaryArray.search(tmpBusca);

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

