/* 
 * File:   BinaryTreeArray.cpp
 * Author: thiago
 * 
 * Created on 1 de Setembro de 2016, 09:11
 */

#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "BinaryTreeArray.h"

BinaryTreeArray::BinaryTreeArray() {
    this->treeSize = 0;
    this->root = new Node();
    this->root->SetId(0);
    this->root->SetLeaf(NULL);
    this->root->SetLeft(NULL);
    this->root->SetMother(NULL);
    this->root->SetRageLeft(0);
    this->root->SetRageRigth(0);
    this->root->SetRight(NULL);
}

BinaryTreeArray::BinaryTreeArray(const BinaryTreeArray& orig) {
}

BinaryTreeArray::~BinaryTreeArray() {
}

int BinaryTreeArray::Add(BinaryTreeInterface* leaf) {

    Node *node_tmp, *node_tmp2;

    node_tmp = NULL;

    printf("Adicionando um novo no\n");

    if (leaf->getId() > this->treeSize) {
        this->treeSize = leaf->getId();
        printf("Criando uma nova arvore\n");
        node_tmp = this->root;
        this->root = new Node();
        this->root->SetId(leaf->getId() / 2);
        this->root->SetLeaf(NULL);
        this->root->SetLeft(NULL);
        this->root->SetMother(NULL);
        this->root->SetRageLeft(0);
        this->root->SetRageRigth(leaf->getId());
        this->root->SetRight(NULL);
        node_tmp2 = this->createNode(this->root, leaf->getId(), 0);
        node_tmp2->SetLeaf(leaf);
        this->transferNode(node_tmp, node_tmp);
        delete(node_tmp);
        return 1;
    }

    printf("Criando um novo no --- \n");
    node_tmp = this->createNode(this->root, leaf->getId(), 0);

    if (node_tmp->GetLeaf() == NULL) {
        printf("Adicionado ao no a folha %llu\n", leaf->getId());
        node_tmp->SetLeaf(leaf);
        return 1;
    } else {
        return 0;
    }

}

void BinaryTreeArray::transferNode(Node* root, Node* node) {

//    printf("**************Transferindo arvore*****************\n");
    if (node == root) {
//        printf("T No root\n");
        if (root->GetLeft() == NULL && root->GetRight() == NULL) {
            if (root->GetLeaf() != NULL) {
                this->Add(root->GetLeaf());
            }
            return;
        } else if (root->GetLeft() != NULL) {
//            printf("Root -> Pegando perna esquerda\n");
            this->transferNode(root, root->GetLeft());
            return;
        } else {
//            printf("Root -> Pegando perna Direita\n");
            this->transferNode(root, root->GetRight());
            return;
        }
    }

    if (node->GetLeft() == NULL && node->GetRight() == NULL) {
//        printf("Folha %p\n", node);
        Node *pai;
        if (node->GetLeaf() != NULL) {
            this->Add(node->GetLeaf());
        }
        pai = node->GetMother();

//        printf("Direita %p, Esquerda %p, Noh %p\n", pai->GetRight(), pai->GetLeft(), node);
        //        sleep(1);

        if (pai->GetRight() == node) {
//            printf("Apagando a direita %p\n", pai->GetRight());
            delete(pai->GetRight());
            //this->leafs.push_back(node);
            pai->SetRight(NULL);
        } else if (pai->GetLeft() == node) {
//            printf("Apagando a esquerda %p\n", pai->GetLeft());
            delete(pai->GetLeft());
            //this->leafs.push_back(node);
            pai->SetLeft(NULL);
        }
        this->transferNode(root, pai);
    } else if (node->GetRight() != NULL) {
//        printf("Pegando perna direita\n");
        this->transferNode(root, node->GetRight());
    } else {
//        printf("Pegando perna esquerda\n");
        this->transferNode(root, node->GetLeft());
    }

}

void* BinaryTreeArray::search(long long int id) {

    Node *node;

    node = this->findNode(this->root, id);
    if (node == NULL || node->GetLeaf() == NULL) {
        return NULL;
    }

    printf("Retornando %llu\n", node->GetLeaf()->getId());

    return (void *) node->GetLeaf();
}

int BinaryTreeArray::middle(unsigned long long int begin, unsigned long long int end) {

    return (end - begin) / 2;

}

Node* BinaryTreeArray::createNode(Node* node, unsigned long long int id, unsigned long long int level) {

    level++;

//    printf("Nivel %llu\n", level);

//    printf("No passado %llu\n", node->GetId());

    //    sleep(1);

    if (node->GetId() == id) {
//        printf("No encontrado!!! ********************************\n");
        return node;
    } else if (id > node->GetId()) {
        if (node->GetRight() == NULL) {
//            printf("Criando no a direita\n");
            Node *nodeTmp;
            nodeTmp = new Node();
            long long int middle = this->middle(node->GetId(), node->GetRageRigth());
            if (middle == 0) {
                nodeTmp->SetId(node->GetId() + 1);
            } else {
                nodeTmp->SetId(node->GetId() + middle);
            }
            nodeTmp->SetMother(node);
            nodeTmp->SetRageLeft(node->GetId());
            nodeTmp->SetRageRigth(node->GetRageRigth());
            nodeTmp->SetLeft(NULL);
            nodeTmp->SetRight(NULL);
            nodeTmp->SetDown(NULL);
            nodeTmp->SetLeaf(NULL);
            node->SetRight(nodeTmp);
        }

        return this->createNode(node->GetRight(), id, level);
    } else if (id < node->GetId()) {
        if (node->GetLeft() == NULL) {
//            printf("Criando no a esquerda\n");
            Node *nodeTmp;
            nodeTmp = new Node();
            long long int middle = this->middle(node->GetRageLeft(), node->GetId());
            middle += node->GetRageLeft();
//            printf("Meio %llu\n", middle);
            nodeTmp->SetId(middle);
            nodeTmp->SetMother(node);
            nodeTmp->SetRageLeft(node->GetRageLeft());
            nodeTmp->SetRageRigth(node->GetId());
            nodeTmp->SetLeft(NULL);
            nodeTmp->SetRight(NULL);
            nodeTmp->SetDown(NULL);
            nodeTmp->SetLeaf(NULL);
            node->SetLeft(nodeTmp);
        }
        return this->createNode(node->GetLeft(), id, level);
    }
}

Node* BinaryTreeArray::findNode(Node* node, unsigned long long int id) {

    if (node->GetId() == id) {
        printf("Encontrou o no!!!\n");
        return node;
    } else if (id > node->GetId()) {
        printf("Procurando pela direita %llu\n", node->GetId());
        if (node->GetRight() == NULL) {
            return NULL;
        }
        this->findNode(node->GetRight(), id);
    } else {
        printf("Procurando pela esquerda %llu\n", node->GetId());
        if (node->GetLeft() == NULL) {
            return NULL;
        }
        this->findNode(node->GetLeft(), id);
    }

}

