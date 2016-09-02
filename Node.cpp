/* 
 * File:   Node.cpp
 * Author: thiago
 * 
 * Created on 1 de Setembro de 2016, 15:14
 */

#include "Node.h"
#include "BinaryTreeArray.h"

Node::Node() {
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

Node* Node::GetDown() const {
    return down;
}

unsigned long long int Node::GetId() const {
    return id;
}

BinaryTreeInterface* Node::GetLeaf() const {
    return leaf;
}

Node* Node::GetLeft() const {
    return left;
}

Node* Node::GetMother() const {
    return mother;
}

unsigned long long int Node::GetRageLeft() const {
    return rageLeft;
}

unsigned long long int Node::GetRageRigth() const {
    return rageRigth;
}

Node* Node::GetRight() const {
    return right;
}

void Node::SetDown(Node* down) {
    this->down = down;
}

void Node::SetId(unsigned long long int id) {
    this->id = id;
}

void Node::SetLeaf(BinaryTreeInterface* leaf) {
    this->leaf = leaf;
}

void Node::SetLeft(Node* left) {
    this->left = left;
}

void Node::SetMother(Node* mother) {
    this->mother = mother;
}

void Node::SetRageLeft(unsigned long long int rageLeft) {
    this->rageLeft = rageLeft;
}

void Node::SetRageRigth(unsigned long long int rageRigth) {
    this->rageRigth = rageRigth;
}

void Node::SetRight(Node* right) {
    this->right = right;
}

