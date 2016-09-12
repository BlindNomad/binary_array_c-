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
    this->tmpi = 0;
}

BinaryTreeArray::BinaryTreeArray(const BinaryTreeArray& orig) {
}

BinaryTreeArray::~BinaryTreeArray() {
    if (this->root != NULL) {
        this->free();
        delete(this->root);
    }
}

int BinaryTreeArray::add(void *leaf, unsigned long long id, bool replace) {

    Node *node_tmp, *node_tmp2;

    node_tmp = NULL;

    if (id > this->treeSize) {
        this->treeSize = id;
        node_tmp = this->root;
        this->root = new Node();
        this->root->SetId(id / 2);
        this->root->SetLeaf(NULL);
        this->root->SetLeft(NULL);
        this->root->SetMother(NULL);
        this->root->SetRageLeft(0);
        this->root->SetRageRigth(id);
        this->root->SetRight(NULL);
        this->tmpi++;
        node_tmp2 = this->createNode(this->root, id, 0);
        node_tmp2->SetLeaf(leaf);

        this->transferNode(node_tmp);
        this->free(node_tmp);
        return 1;
    }

    node_tmp = this->createNode(this->root, id, 0);

    if (node_tmp->GetLeaf() == NULL || replace == true) {
        if (node_tmp->GetLeaf() != NULL) {
            node_tmp->SetLeaf(leaf);
            return -1;
        }
        node_tmp->SetLeaf(leaf);
        return 1;
    } else {
        return 0;
    }

}

void BinaryTreeArray::transferNode(Node* node) {
    if (node->GetLeaf() != NULL) {
        this->Add(node->GetLeaf(), node->GetId(), false);
    }
    if (node->GetLeft() != NULL) {
        this->transferNode(node->GetLeft());
    }
    if (node->GetRight() != NULL) {
        this->transferNode(node->GetRight());
    }

}

void* BinaryTreeArray::search(long long int id) {

    Node *node;

    if (id > this->treeSize) {
        return NULL;
    }

    node = this->findNode(this->root, id);
    if (node == NULL || node->GetLeaf() == NULL) {
        return NULL;
    }

    return (void *) node->GetLeaf();
}

int BinaryTreeArray::middle(unsigned long long int begin, unsigned long long int end) {

    return (end - begin) / 2;

}

Node* BinaryTreeArray::createNode(Node* node, unsigned long long int id, unsigned long long int level) {

    level++;

    if (node->GetId() == id) {
        return node;
    } else if (id > node->GetId()) {
        if (node->GetRight() == NULL) {
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
            Node *nodeTmp;
            nodeTmp = new Node();
            long long int middle = this->middle(node->GetRageLeft(), node->GetId());
            middle += node->GetRageLeft();
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

void BinaryTreeArray::free() {
    this->nextNode(this->root, BinaryTreeArray::deleteNode);

    this->root = NULL;

}

void BinaryTreeArray::free(Node* root) {
    this->nextNode(root, BinaryTreeArray::deleteNode);
    root = NULL;
}

void BinaryTreeArray::deleteNode(Node* node) {
    delete(node);

}

Node* BinaryTreeArray::findNode(Node* node, unsigned long long int id) {

    if (node->GetId() == id) {
        return node;
    } else if (id > node->GetId()) {
        if (node->GetRight() == NULL) {
            return NULL;
        }
        this->findNode(node->GetRight(), id);
    } else {
        if (node->GetLeft() == NULL) {
            return NULL;
        }
        this->findNode(node->GetLeft(), id);
    }

}

void BinaryTreeArray::forEach(valueFunc callback) {
    this->nextValue(this->root, callback);
}

void BinaryTreeArray::nextValue(Node* node, valueFunc callback) {

    if (node->GetLeaf() != NULL) {
        callback(node->GetLeaf());
    }
    if (node->GetLeft() != NULL) {
        this->nextValue(node->GetLeft(), callback);
    }
    if (node->GetRight() != NULL) {
        this->nextValue(node->GetRight(), callback);
    }

}

void BinaryTreeArray::nextNode(Node* node, nodeFunc callback) {
    if (node->GetLeft() != NULL) {
        this->nextNode(node->GetLeft(), callback);
    }

    if (node->GetRight() != NULL) {
        this->nextNode(node->GetRight(), callback);
    }

    callback(node);
}


