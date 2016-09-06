/* 
 * File:   Node.h
 * Author: thiago
 *
 * Created on 1 de Setembro de 2016, 15:14
 */

#ifndef NODE_H
#define	NODE_H

class Node {
public:
    Node();
    Node(const Node& orig);
    virtual ~Node();
    
    Node* GetDown() const;

    void SetDown(Node* down);

    unsigned long long int GetId() const;

    void SetId(unsigned long long int id);

    void* GetLeaf() const;

    void SetLeaf(void* leaf);

    Node* GetLeft() const;

    void SetLeft(Node* left);

    Node* GetMother() const;

    void SetMother(Node* mother);

    unsigned long long int GetRageLeft() const;

    void SetRageLeft(unsigned long long int rageLeft);

    unsigned long long int GetRageRigth() const;

    void SetRageRigth(unsigned long long int rageRigth);

    Node* GetRight() const;

    void SetRight(Node* right);

    
private:
    Node *mother;
    Node *right;
    Node *left;
    Node *down;
    unsigned long long int id;
    unsigned long long int rageLeft;
    unsigned long long int rageRigth;
    void *leaf;


};

#endif	/* NODE_H */

