/* 
 * File:   BinaryTreeInterface.h
 * Author: thiago
 *
 * Created on 1 de Setembro de 2016, 09:32
 */

#ifndef BINARYTREEINTERFACE_H
#define	BINARYTREEINTERFACE_H

class BinaryTreeInterface {
public:
    BinaryTreeInterface();
    BinaryTreeInterface(const BinaryTreeInterface& orig);
    virtual ~BinaryTreeInterface();
    
    virtual unsigned long long int getId() = 0;
    
private:

};

#endif	/* BINARYTREEINTERFACE_H */

