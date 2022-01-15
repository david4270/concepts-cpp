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
    Node * rhsptr = other.head;
    if(rhsptr != NULL){
        head->setKey(rhsptr->getKey());
        copy(head, rhsptr);
    }
}

BST::~BST(){
    if(head == NULL) return;
    delete_tree(head);
}

BST & BST::operator=(const BST & rhs){
    if(this == &rhs) return *this;
    Node * ptr = head;
    Node * rhsptr = rhs.head;
    if(rhsptr != NULL){
        ptr->setKey(rhsptr->getKey());
        copy(ptr, rhsptr);
    }

    return *this;
}

void BST::copy(Node * ptr, Node * rhsptr){
    if(rhsptr != NULL){
        //left side
        Node * left = new Node(rhsptr->getLeft()->getLeft(),rhsptr->getLeft()->getRight(),rhsptr->getLeft()->getKey());
        ptr->setLeft(left);
        copy(ptr->getLeft(), rhsptr->getLeft());
        //right side
        Node * right = new Node(rhsptr->getRight()->getLeft(),rhsptr->getRight()->getRight(),rhsptr->getRight()->getKey());
        ptr->setLeft(left);
        copy(ptr->getLeft(), rhsptr->getLeft());
    }
}

void BST::Insert(int k){
    //if the BST is called and head is null, set it up
    if(head == NULL){
        Node * temp = new Node(k);
        head = temp;
        return;
    }
    //otherwise run insert_tree
    insert_tree(head,k);
}

void BST::insert_tree(Node * ptr, int k){
    //if key found, return as there is no need to insert
    if(ptr->getKey() == k) return; 

    Node * temp = new Node(k);
    
    //if key is smaller, proceed left
    if(ptr->getKey() > k){
        //if end of tree, insert left
        if(ptr->getLeft()==NULL){
            ptr->setLeft(temp);
            return;
        }
        else insert_tree(ptr->getLeft(),k);
    }
    //if key is larger, proceed right
    if(ptr->getKey() < k){
        //if end of tree, insert right
        if(ptr->getRight()==NULL){
            ptr->setRight(temp);
            return;
        }
        else insert_tree(ptr->getRight(),k);
    }

    delete temp;
    temp = NULL;

}

bool BST::Search(Node * ptr, int k){
    if(ptr == NULL) return false; 
    //if key found, return true
    if(ptr->getKey() == k) return true;
    //if reached end of tree and not found key, return false
    else if(ptr->getLeft() == NULL && ptr->getRight()==NULL) return false; 
    //if key is smaller, proceed left
    else if(ptr->getKey() > k) return Search(ptr->getLeft(),k);
    //if key is larger, proceed right
    else if(ptr->getKey() < k) return Search(ptr->getRight(),k);
    else return false;
}

void BST::Delete(int k){
    //Need work
}

//Not working. Need to fix -> seems like it is not properly done, since double clear does not work
void BST::clear(){
    if(head == NULL) return;
    delete_tree(head);
}

void BST::delete_tree(Node * rt){
    if(rt == NULL) return;
    delete_tree(rt->getLeft());
    delete_tree(rt->getRight());
    delete rt;
    rt = NULL;
}

Node * BST::gethead(){
    return head;
}

void BST::inorderTraversal(Node * rt){
    if(rt == NULL) return;
    if(rt != NULL){
        inorderTraversal(rt->getLeft());
        cout << rt->getKey() << endl;
        inorderTraversal(rt->getRight());
    }
}

void BST::preorderTraversal(Node * rt){
    if(rt == NULL) return;
    if(rt != NULL){
        cout << rt->getKey() << endl;
        preorderTraversal(rt->getLeft()); 
        preorderTraversal(rt->getRight());
    }
}

void BST::postorderTraversal(Node * rt){
    if(rt == NULL) return;
    if(rt != NULL){
        postorderTraversal(rt->getLeft()); 
        postorderTraversal(rt->getRight());
        cout << rt->getKey() << endl;
    }
}