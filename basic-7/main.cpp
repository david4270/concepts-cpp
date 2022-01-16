//Binary search tree of numbers

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    int opr, num;
    bool toEnd = false;
    BST tree;
    while(1){
        cout << "1) Insert 2) Search 3) Delete 4) Clear " << endl;
        cout << "5) in-order 6) pre-order 7) post-order, other keys to exit" << endl;
        cout << "Insert operation: ";
        cin >> opr;

        switch(opr){
            case 1:
                cout << "Number to insert: ";
                cin >> num;
                tree.Insert(num);
                break;
            case 2:
                cout << "Number to search: ";
                cin >> num;
                if(tree.search_elem(tree.gethead(),num)){
                    cout << num << " is found" << endl;
                }
                else{
                    cout << num << " not found" << endl;
                }
                break;
            case 3:
                cout << "Number to delete: ";
                cin >> num;
                tree.sethead(tree.delete_elem(tree.gethead(),num));
                break;
            case 4: tree.clear(); break;
            case 5: tree.inorderTraversal(tree.gethead()); break;
            case 6: tree.preorderTraversal(tree.gethead()); break;
            case 7: tree.postorderTraversal(tree.gethead()); break;
            default: toEnd = true; break;
        }
        if (toEnd) break;
    }

    tree.clear();
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   