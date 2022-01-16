#include <iostream>
#include "func.h"

using namespace std;

/****** Node ******/
//Default Constructor
Node::Node(){
    left = NULL;
    right = NULL;
    key = 0;
}

//Constructor with key
Node::Node(int k){
    left = NULL;
    right = NULL;
    key = k;
}

//Constructor with key, left and right pointers
Node::Node(Node * l, Node * r, int k){
    left = l;
    right = r;
    key = k;
}

//Destructor
Node::~Node(){

}

//get key
int Node::getKey(){
    return key;
}

//get left
Node* Node::getLeft(){
    return left;
}

//get right
Node * Node::getRight(){
    return right;
}

//set key
void Node::setKey(int k){
    key = k;
}

//set left
void Node::setLeft(Node * l){
    left = l;
}

//set right
void Node::setRight(Node * r){
    right = r;
}

//print
void Node::print() const{
    cout << key << endl;
}

/****** BST ******/
//default constructor
BST::BST(){
    head = NULL;
}

//copy constructor
BST::BST(const BST & other){
    Node * rhsptr = other.head;
    if(rhsptr != NULL){
        head->setKey(rhsptr->getKey());
        copy(head, rhsptr);
    }
}

//default destructor
BST::~BST(){
    if(head == NULL) return;
    delete_tree(head);
}

//operator=
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

//copy
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

//Insert number
void BST::Insert(int k){
    //if the BST is called and head is null, set it up
    if(head == NULL){
        Node * temp = new Node(k);
        head = temp;
        return;
    }
    //otherwise run insert_tree
    insert_elem(head,k);
}

//Subfunction of Insert
void BST::insert_elem(Node * ptr, int k){
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
        //otherwise proceed left
        else insert_elem(ptr->getLeft(),k);
    }
    //if key is larger, proceed right
    if(ptr->getKey() < k){
        //if end of tree, insert right
        if(ptr->getRight()==NULL){
            ptr->setRight(temp);
            return;
        }
        //otherwise proceed right
        else insert_elem(ptr->getRight(),k);
    }

    delete temp;
}

//Search key
bool BST::search_elem(Node * ptr, int k){
    if(ptr == NULL) return false; 
    //if key found, return true
    if(ptr->getKey() == k) return true;
    //if reached end of tree and not found key, return false
    else if(ptr->getLeft() == NULL && ptr->getRight()==NULL) return false; 
    //if key is smaller, proceed left
    else if(ptr->getKey() > k) return search_elem(ptr->getLeft(),k);
    //if key is larger, proceed right
    else if(ptr->getKey() < k) return search_elem(ptr->getRight(),k);
    else return false;
}

//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
Node* BST::delete_elem(Node * ptr, int k){

    if(ptr == NULL){
        return ptr;
    }
    //if key is smaller, proceed left
    if(ptr->getKey() > k){
        ptr->setLeft(delete_elem(ptr->getLeft(), k));
    }
    //if key is larger, proceed right
    else if(ptr->getKey() < k){
        ptr->setRight(delete_elem(ptr->getRight(), k));
    }
    //key found
    else{
        //If no children
        if(ptr->getLeft() == NULL && ptr->getRight()==NULL){
            return NULL;
        }
        //If one child
        else if(ptr->getLeft() == NULL){
            Node * tmp = ptr->getRight();
            delete ptr;
            return tmp;
        }
        else if(ptr->getRight() == NULL){
            Node * tmp = ptr->getLeft();
            delete ptr;
            return tmp;
        }
        //If two children
        Node * tmp = findMinimum(ptr->getRight()); //find successor
        ptr->setKey(tmp->getKey());
        ptr->setRight(delete_elem(ptr->getRight(), tmp->getKey()));
    }
    return ptr;
    
}

//Clear tree
void BST::clear(){
    delete_tree(head);
    head = NULL;
}

//subfunction of clear
void BST::delete_tree(Node * rt){
    if(rt == NULL) return;

    delete_tree(rt->getLeft());
    delete_tree(rt->getRight());

    cout << "Removed " << rt->getKey() << endl;
    delete rt;
    //rt = NULL;
}

//get head
Node * BST::gethead(){
    return head;
}

//set head
void BST::sethead(Node * ptr){
    head = ptr;
}

//minimum of subtree
Node* BST::findMinimum(Node * ptr){
    while(ptr->getLeft()!=NULL){
        ptr = ptr->getLeft();
    }
    return ptr;
}

//maximum of subtree
Node* BST::findMaximum(Node * ptr){
    while(ptr->getRight()!=NULL){
        ptr = ptr->getRight();
    }
    return ptr;
}

//in-order traversal
void BST::inorderTraversal(Node * rt){
    if(rt == NULL) return;
    if(rt != NULL){
        inorderTraversal(rt->getLeft());
        cout << rt->getKey() << endl;
        inorderTraversal(rt->getRight());
    }
}

//pre-order traversal
void BST::preorderTraversal(Node * rt){
    if(rt == NULL) return;
    if(rt != NULL){
        cout << rt->getKey() << endl;
        preorderTraversal(rt->getLeft()); 
        preorderTraversal(rt->getRight());
    }
}

//post-order traversal
void BST::postorderTraversal(Node * rt){
    if(rt == NULL) return;
    if(rt != NULL){
        postorderTraversal(rt->getLeft()); 
        postorderTraversal(rt->getRight());
        cout << rt->getKey() << endl;
    }
}