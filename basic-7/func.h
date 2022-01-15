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
        void copy(Node * ptr, Node * rhsptr);

        void Insert(int k);
        void Delete(int k);
        bool Search(Node * ptr, int k);

        void insert_tree(Node * ptr, int k);

        void clear();
        void delete_tree(Node * rt);

        Node* gethead();

        void inorderTraversal(Node * rt);
        void preorderTraversal(Node * rt);
        void postorderTraversal(Node * rt);
};

#endif