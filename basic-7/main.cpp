//Binary search tree of numbers

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    int opr, num;
    BST tree;
    while(1){
        cout << "1) Insert 2) Search 3) Delete 4) Clear " << endl;
        cout << "5) in-order 6) pre-order 7) post-order, other keys to exit" << endl;
        cout << "Insert operation: ";
        cin >> opr;

        if(opr == 1){
            cout << "Number to insert: ";
            cin >> num;
            tree.Insert(num);
        }
        else if(opr == 2){
            cout << "Number to search: ";
            cin >> num;
            if(tree.Search(tree.gethead(),num)){
                cout << num << " is found" << endl;
            }
            else{
                cout << num << " not found" << endl;
            }
        }
        else if(opr == 3){
            cout << "Number to delete: ";
            cin >> num;
            //tree.Delete(num);
        }
        else if(opr == 4){
            //tree.clear();
            tree.delete_tree(tree.gethead());
        }
        else if(opr == 5){
            tree.inorderTraversal(tree.gethead());
        }   
        else if(opr == 6){
            tree.preorderTraversal(tree.gethead());
        }
        else if(opr == 7){
            tree.postorderTraversal(tree.gethead());
        }
        else{
            break;
        }
    }

    tree.clear();
    
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   