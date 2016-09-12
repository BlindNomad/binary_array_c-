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

/**
 * It is class inserts the objects passed in a list, organized in the form of binary tree.
 * The class contains the following methods:
 * add -> to add new content.
 * search -> Search a given.
 * forEach -> Accesses all the data called the callback function to each meeting.
 * free -> All the nodes of the tree.
 */
class BinaryTreeArray {
public:   
    
    /**
     * Constructor
     */
    BinaryTreeArray();
    BinaryTreeArray(const BinaryTreeArray& orig);
    virtual ~BinaryTreeArray();
    
    /**
     * Adds the dowel pointer on the informed id. Returns 1 for OK, -1 when it replaced a pointer that was already allocated and 0 in case of error.
     * @param leaf Pointer data to be stored.
     * @param id single given identifier.
     * @param replace
     * @return Returns 1 for OK, -1 when it replaced a pointer that was already allocated and 0 in case of error.
     */
    int add(void *leaf, unsigned long long id, bool replace);
    
    /**
     * Returns the pointer stored in the designated identifier.
     * @param id Identifier.
     * @return  Pointer stored.
     */
    void *search(long long int id);
    
    /**
     * Passa por todos os nós, chamando a função de callback a cada encontro com o ponteiro armazenado.
     * @param callback
     */
    void forEach(valueFunc callback);
    
    /**
     * Free all nodes.
     */
    void free();
    
private:
    
    Node *root;
    unsigned long long int treeSize;
    
    int tmpi;
    
    int middle(unsigned long long int begin, unsigned long long int end);
    
    Node *createNode(Node *node, unsigned long long int id, unsigned long long int level);
    Node *findNode(Node *node, unsigned long long int id);
    void transferNode(Node *node);
    
    void nextValue(Node *node, valueFunc callback);
    
    void nextNode(Node *node, nodeFunc callback);
    
    static void deleteNode(Node *node);

    void free(Node *root);
    
};

#endif	/* BINARYTREEARRAY_H */

