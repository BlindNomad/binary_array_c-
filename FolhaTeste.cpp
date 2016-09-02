/* 
 * File:   FolhaTeste.cpp
 * Author: thiago
 * 
 * Created on 1 de Setembro de 2016, 14:24
 */

#include "FolhaTeste.h"


FolhaTeste::FolhaTeste() {
}

FolhaTeste::FolhaTeste(const FolhaTeste& orig) {
}

FolhaTeste::~FolhaTeste() {
}

unsigned long long int FolhaTeste::getId() {
    return this->id;
}

void FolhaTeste::setId(unsigned long long id) {
    this->id = id;
}

