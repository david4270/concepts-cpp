//Hash tables WITHOUT STL functions - chaining

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    HashTable names;
    int toDo;
    string ip;
    bool toEnd = false;
    while(!toEnd){
        ip = "";
        cout << "Insert your operation. 1) Insert 2) Search 3) Delete 4) Print table" << endl;
        cout << "Press any other key to EXIT... : ";
        cin >> toDo;
        cin.ignore();
        cout << toDo << endl;
        switch(toDo){
            case 1:
                cout << "Which name do you want to input?: ";
                getline(cin,ip);
                names.insertElement(ip);
                break;
            case 2:
                cout << "Which name do you want to search?: ";
                getline(cin,ip);
                if(names.searchElement(ip)){
                    cout << ip << " found" << endl;
                }
                else{
                    cout << ip << " not found" << endl;
                }
                break;
            case 3:
                cout << "Which name do you want to delete?: ";
                getline(cin,ip);
                if(names.deleteElement(ip)){
                    cout << "Successfully deleted " << ip << endl;
                }
                else{
                    cout << "Unable to delete " << ip << endl;
                }
                break;
            case 4:
                cout << endl;
                names.printTable();
                cout << endl;
                break;
            default:
                toEnd = true;
                break;
        }
    }
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   