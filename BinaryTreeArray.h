/* 
 * File:   BinaryTreeArray.h
 * Author: thiago
 *
 * Created on 1 de Setembro de 2016, 09:11
 */

#ifndef BINARYTREEARRAY_H
#define	BINARYTREEARRAY_H

#include <list>

#include "BinaryTreeInterface.h"
#include "Node.h"


typedef enum __size_tree {
    __TREE_8BITS = 8,
    __TREE_10BITS = 10,
    __TREE_24BITS = 24,
    __TREE_32BITS = 32,
    __TREE_64BITS = 64,
    __TREE_128BITS = 128,
    __TREE_256BITS = 256

} __SIZE_TREE;


class BinaryTreeArray {
public:   
    
    BinaryTreeArray();
    BinaryTreeArray(const BinaryTreeArray& orig);
    virtual ~BinaryTreeArray();
    
    int Add(BinaryTreeInterface *leaf);
    
    void *search(long long int id);
    
private:
    
    Node *root;
    
    std::list<Node *> leafs;
    unsigned long long int treeSize;
           
    int middle(unsigned long long int begin, unsigned long long int end);
    
    Node *createNode(Node *node, unsigned long long int id, unsigned long long int level);
    Node *findNode(Node *node, unsigned long long int id);
    void transferNode(Node *root, Node *node);
    
};

#endif	/* BINARYTREEARRAY_H */

