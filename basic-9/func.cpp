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

void PersonName::setNext(PersonName * nxt){
    next = nxt;
}

string PersonName::getName(){
    return name;
}

int PersonName::getKey(){
    return key;
}

PersonName * PersonName::getNext(){
    return next;
}

void PersonName::print() const{
    cout << key << " : " << name << endl;
}

//HashTable class
HashTable::HashTable(){
    for(int i = 0; i < 10 ; i++){
        Hash[i] = NULL;
    }
}

HashTable::~HashTable(){
    //use deleteTable code
    deleteTable();
}

void HashTable::insertElement(string nm){
    PersonName * temp = new PersonName;
    temp->setName(nm);

    int keyBackup = temp->getKey();
    int loc;

    //Hash function
    loc = keyBackup % 10;
    
    if(Hash[loc] == NULL){
        Hash[loc] = temp;
        temp->setNext(NULL);
    }
    else{
        PersonName * tptr = Hash[loc];
        while(tptr->getNext() != NULL){
            tptr = tptr->getNext();
        }
        tptr->setNext(temp);
        temp->setNext(NULL);  
    }
}


bool HashTable::searchElement(string nm){
    int keyAdd = 0;
    int loc;
    for(int i = 0; i < nm.length(); i++){
        keyAdd += (int) nm[i];
    }
    loc = keyAdd % 10;
    if(Hash[loc] == NULL){
        return false;
    }
    else{
        PersonName * tptr = Hash[loc];
        while(tptr != NULL){
            if(tptr->getName() != nm){
                tptr = tptr->getNext();
            }
            else{ //if nm found
                return true;
            }
        }
        //if tptr reaches NULL then nm cannot be found
        return false;
    }
}

bool HashTable::deleteElement(string nm){
    int keyAdd = 0;
    int loc;
    for(int i = 0; i < nm.length(); i++){
        keyAdd += (int) nm[i];
    }
    loc = keyAdd % 10;
    if(Hash[loc] == NULL){
        return false;
    }
    else{
        PersonName * tptr = Hash[loc];
        PersonName * nptr;
        while(tptr != NULL){
            if(tptr->getName() == nm){
                break;
            }
            nptr = tptr;
            tptr = tptr->getNext();
            
        }
        if(tptr == NULL) return false;
        if(tptr == Hash[loc]){
            Hash[loc] = tptr->getNext();
            delete tptr;
            return true;
        }
        nptr->setNext(tptr->getNext());
        delete tptr;
        return true;
    }
}

void HashTable::printTable(){
    PersonName * ptr;
    for(int i = 0; i < 10; i++){
        ptr = Hash[i];
        if(ptr == NULL){
            //nothing
        }
        else{
            ptr = Hash[i];
            while(ptr != NULL){
                cout << i << " : ";
                ptr->print();
                ptr = ptr->getNext();
            }
        }
    }
}

void HashTable::deleteTable(){
    PersonName * ptr;
    PersonName * pvs;
    for(int i = 0; i < 10; i++){
        ptr = Hash[i];
        while(ptr != NULL){
            pvs = ptr;
            ptr = ptr->getNext();
            delete pvs;
        }
    }
    cout << "Deleted Table" << endl;
}