//Linked list-alike class + Dynamic allocation of classes

#include <iostream>
#include "func.h"

using namespace std;

int main(){

    PersonalInfo David("David Song", 1999, 7, 24);
    David.print();

    PersonalInfo Ian("Ian Webster", 2000, 3, 25); // need check, anyways
    Ian.print();

    PersonalInfo Mymy("Mymy Tran", 2000, 2, 3);
    Mymy.print();

    PersonalInfo Yixin("Yixin Tian", 1999, 10, 27);
    Yixin.print();

    PersonalInfo Junho("Jun Ho Sung", 1999, 9, 21);
    Junho.print();

    cout << 1 << endl;

    InfoList a, b, c;
    
    a.insertAtTail(& David);
    a.print();

    cout << 2 << endl;

    a.insertAtTail(& Ian);
    a.print();

    cout << 3 << endl;

    a.insertAtTail(& Mymy);
    a.print();

    cout << 4 << endl;

    a.insertAtTail(& Yixin);
    a.print();

    cout << 5 << endl;

    a.insertAtTail(& Junho);
    a.print();

    cout << 6 << endl;

    b.operator=(a);
    b.print();

    cout << 7 << endl;
    /*
    a.deleteInfo("David Song", 1999, 7, 24);
    a.print();

    cout << 8 << endl;
    */
    a.deleteInfo("Jun Ho Sung");
    a.print();

    cout << 9 << endl;

    a.insertAtHead(& Junho);
    a.print();
    
    cout << 10 << endl;

    cout << a.LocateInList("Mymy Tran") -> getBirthday() -> day << endl;

    cout << 11 << endl;

    b.print();

    cout << 12 << endl;

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
        cout << "Type operation. 1. Add, 2. Search, 3. Delete" << endl;
        cin >> operation;
        if(operation == 1){
            PersonalInfo * k = new PersonalInfo(name,yr,mo,day);
            //k->print();
            c.insertAtTail(k);
            c.print();
            cout << endl;
            //delete k;
        }
        else if(operation == 2){
            cout << c.LocateInList(name,yr,mo,day) -> getName() << endl;
            cout << c.LocateInList(name,yr,mo,day) -> getBirthday() -> yr << endl;
            cout << c.LocateInList(name,yr,mo,day) -> getBirthday() -> mo << endl;
            cout << c.LocateInList(name,yr,mo,day) -> getBirthday() -> day << endl;
        }
        else if(operation == 3){
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