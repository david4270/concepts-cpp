#include <iostream>
#include "func.h"

using namespace std;

/****** Node ******/
Node::Node(){
    left = NULL;
    right = NULL;
    key = 0;
}

Node::Node(int k){
    left = NULL;
    right = NULL;
    key = k;
}

Node::Node(Node * l, Node * r, int k){
    left = l;
    right = r;
    key = k;
}

Node::~Node(){

}

int Node::getKey(){
    return key;
}

Node* Node::getLeft(){
    return left;
}

Node * Node::getRight(){
    return right;
}

void Node::setKey(int k){
    key = k;
}

void Node::setLeft(Node * l){
    left = l;
}

void Node::setRight(Node * r){
    right = r;
}

void Node::print() const{
    cout << key << endl;
}

/****** BST ******/
BST::BST(){
    head = NULL;
}

BST::BST(const BST & other){
    head->setKey(other.head->getKey());
    
}

BST::~BST(){
    if(head == NULL) return;
    delete_tree(head);
}

BST & BST::operator=(const BST & rhs){

}

void BST::Insert(int k){
    //if the BST is called and head is null, set it up
    if(head == NULL){
        head->setKey(k);
        head->setLeft(NULL);
        head->setRight(NULL);
        return;
    }
    //otherwise run insert_tree
    insert_tree(head,k);
}

void BST::insert_tree(Node * ptr, int k){
    //if key found, return as there is no need to insert
    if(ptr->getKey() == k) return; 
    
    //if key is smaller, proceed left
    if(ptr->getKey() > k){
        //if end of tree, insert left
        if(ptr->getLeft()==NULL){
            ptr->setLeft(&Node(k));
            return;
        }
        else insert_tree(ptr->getLeft(),k);
    }
    //if key is larger, proceed right
    if(ptr->getKey() < k){
        //if end of tree, insert right
        if(ptr->getRight()==NULL){
            ptr->setRight(&Node(k));
            return;
        }
        else insert_tree(ptr->getRight(),k);
    }

}

bool BST::Search(Node * ptr, int k){
    //if key found, return true
    if(ptr->getKey() == k) return true;
    //if reached end of tree and not found key, return false
    else if(ptr->getLeft() == NULL && ptr->getRight()==NULL) return false;
    //if key is smaller, proceed left
    if(ptr->getKey() > k) Search(ptr->getLeft(),k);
    //if key is larger, proceed right
    if(ptr->getKey() < k) Search(ptr->getRight(),k);
}

void BST::Delete(int k){

}

void BST::clear(){
    if(head == NULL) return;
    delete_tree(head);
}

void BST::delete_tree(Node * rt){
    if(rt == NULL) return;
    delete_tree(rt->getLeft());
    delete_tree(rt->getRight());
    rt = NULL;
}

void BST::print() const{

}

void BST::inorderTraversal(){

}

void BST::preorderTraversal(){

}

void BST::postorderTraversal(){

}