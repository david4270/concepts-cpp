#include <iostream>
#include "func.h"

using namespace std;

/****** Node ******/
Node::Node(){

}

Node::Node(int k){

}

Node::Node(Node * l, Node * r, int k){

}

Node::~Node(){

}

int Node::getKey(){

}

Node* Node::getLeft(){

}

Node * Node::getRight(){

}

void Node::setKey(int k){

}

void Node::setLeft(Node * l){

}

void Node::setRight(Node * r){

}

void Node::print() const{

}

/****** BST ******/
BST::BST(){

}

BST::BST(const BST & other){

}

BST::~BST(){

}

BST & BST::operator=(const BST & rhs){

}

bool BST::Insert(int k){

}

bool BST::Delete(int k){

}

void BST::clear(){

}

void BST::print() const{

}

void BST::inorderTraversal(BST * a){

}

void BST::preorderTraversal(BST * a){

}

void BST::postorderTraversal(BST * a){

}