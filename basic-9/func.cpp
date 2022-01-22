#include <iostream>
#include "func.h"

using namespace std;


//PersonName class
PersonName::PersonName(){
    next = NULL;
    key = 0;
    name = "";
}

PersonName::PersonName(string nm){
    next = NULL;
    name = nm;

    int keyAdd = 0;
    for(int i = 0; i < nm.length(); i++){
        keyAdd += (int) nm[i];
    }

    key = keyAdd;
}

PersonName::~PersonName(){

}

void PersonName::setName(string nm){
    name = nm;

    int keyAdd = 0;
    for(int i = 0; i < nm.length(); i++){
        keyAdd += (int) nm[i];
    }
    
    key = keyAdd;
}

string PersonName::getName(){
    return name;
}

void PersonName::print() const{
    cout << key << " : " << name << endl;
}

//HashTable class
HashTable::HashTable(){

}

HashTable::~HashTable(){
    delete Hash;
}

void HashTable::insertElement(string nm){

}

bool HashTable::searchElement(string nm){

}

bool HashTable::deleteElement(string nm){

}

void HashTable::printTable(){

}

bool HashTable::deleteTable(){

}