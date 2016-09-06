/* 
 * File:   BinaryTreeArray.h
 * Author: thiago
 *
 * Created on 1 de Setembro de 2016, 09:11
 */

#ifndef BINARYTREEARRAY_H
#define	BINARYTREEARRAY_H

#include <list>
#include "Node.h"


typedef void (*valueFunc)(void *value);

typedef void (*nodeFunc)(Node *node);


class BinaryTreeArray {
public:   
    
    BinaryTreeArray();
    BinaryTreeArray(const BinaryTreeArray& orig);
    virtual ~BinaryTreeArray();
    
    int Add(void *leaf, unsigned long long id, bool replace);
    
    void *search(long long int id);
    
    void forEach(valueFunc callback);
    void free();
    
private:
    
    Node *root;
    unsigned long long int treeSize;
    
    int tmpi;
    
    int middle(unsigned long long int begin, unsigned long long int end);
    
    Node *createNode(Node *node, unsigned long long int id, unsigned long long int level);
    Node *findNode(Node *node, unsigned long long int id);
    void transferNode(Node *node);
    
    //void freeNode(Node *root, Node *node);
    
    void nextValue(Node *node, valueFunc callback);
    
    void nextNode(Node *node, nodeFunc callback);
    
    static void deleteNode(Node *node);

    void free(Node *root);
    
};

#endif	/* BINARYTREEARRAY_H */

