/* 
 * File:   FolhaTeste.h
 * Author: thiago
 *
 * Created on 1 de Setembro de 2016, 14:24
 */

#ifndef FOLHATESTE_H
#define	FOLHATESTE_H

#include "BinaryTreeInterface.h"

class FolhaTeste: public BinaryTreeInterface{
public:
    FolhaTeste();
    FolhaTeste(const FolhaTeste& orig);
    virtual ~FolhaTeste();
    

    virtual unsigned long long int getId();

    void setId(unsigned long long id);
    
    
private:
    
    unsigned long long id;

};

#endif	/* FOLHATESTE_H */

