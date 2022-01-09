//Linked list-alike class + Dynamic allocation of classes

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    InfoList c;

    while(1){
        string name;
        int yr,mo,day, operation;

        cout << "Type name" << endl;
        cin.ignore();
        getline(cin,name);
        cout << "Type birth year" << endl;
        cin >> yr;
        cout << "Type birth month" << endl;
        cin >> mo;
        cout << "Type birth day" << endl;
        cin >> day;
        cout << "Type operation. 1. Add at the back, 2. Add at the front, 3. Search, 4. Delete" << endl;
        cin >> operation;
        if(operation == 1){
            PersonalInfo * k = new PersonalInfo(name,yr,mo,day);
            c.insertAtTail(k);
            c.print();
            cout << endl;
        }
        else if(operation == 2){
            PersonalInfo * k = new PersonalInfo(name,yr,mo,day);
            c.insertAtHead(k);
            c.print();
            cout << endl;
        }
        else if(operation == 3){
            cout << c.LocateInList(name,yr,mo,day) -> getName() << endl;
            cout << c.LocateInList(name,yr,mo,day) -> getBirthday() -> yr << endl;
            cout << c.LocateInList(name,yr,mo,day) -> getBirthday() -> mo << endl;
            cout << c.LocateInList(name,yr,mo,day) -> getBirthday() -> day << endl;
        }
        else if(operation == 4){
            c.deleteInfo(name,yr,mo,day);
            c.print();
            cout << endl;
        }
        else{
            break;
        }
        
    }

    
    
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   