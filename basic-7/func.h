#ifndef _func_h
#define _func_h

#include <iostream>

class Node{
    private:
        Node * left;
        Node * right;
        int key;
    public:
        Node();
        Node(int k);
        Node(Node * l, Node * r, int k);
        ~Node();
        
        int getKey();
        Node * getLeft();
        Node * getRight();

        void setKey(int k);
        void setLeft(Node * l);
        void setRight(Node * r);

        void print() const;
};

class BST{
    private:
        Node * head;
    public:
        BST();
        BST(const BST & other);
        ~BST();

        BST& operator=(const BST & rhs);

        bool Insert(int k);
        bool Delete(int k);

        void clear();

        void print() const;

        void inorderTraversal(BST* a);
        void preorderTraversal(BST* a);
        void postorderTraversal(BST* a);
};

#endif