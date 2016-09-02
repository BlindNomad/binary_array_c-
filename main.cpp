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
int main(int argc, char** argv) {

    FolhaTeste *folha;
    
    BinaryTreeArray binaryArray;
    
    folha = new FolhaTeste();
    folha->setId(1);
    binaryArray.Add(folha);
    
    for (int i = 0; i < 5000; i++){
        folha = new FolhaTeste();
        folha->setId(rand() % 20000);
        binaryArray.Add(folha);
    }
    
    
    
//    FolhaTeste folha2;
//    FolhaTeste folha3;
//    FolhaTeste folha4;
//    
//    folha.setId(10);
//    folha2.setId(1);
//    
//    folha3.setId(20);
//    folha4.setId(30);
//    
//    BinaryTreeArray binaryArray;
//    
//    if (binaryArray.Add(&folha3)){
//        printf("|||||||||||||||Certo!\n");
//    }
//    if (binaryArray.Add(&folha)){
//        printf("|||||||||||||||Certo!\n");
//    }
//    if (binaryArray.Add(&folha2)){
//        printf("|||||||||||||||Certo!\n");
//    }
//    if (binaryArray.Add(&folha4)){
//        printf("|||||||||||||||Certo!\n");
//    }
    
    long long int tmpBusca;
    
    do {
    printf("---------------------------------------------\n");
    
    printf("Digite o id: ");
    scanf("%llu", &tmpBusca);
    printf("\n");
    
            
    FolhaTeste *folhaS;
    
    folhaS = (FolhaTeste *) binaryArray.search(tmpBusca);
    
    if (folhaS == NULL){
        printf("Folha nao encontrada\n");
    }else{
        printf("Encontrado %llu\n", folhaS->getId());
    }
    }while(tmpBusca > 0);
    
    return 0;
}

