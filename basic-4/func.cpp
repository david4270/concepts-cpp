#include <iostream>
#include "func.h"

using namespace std;

/*************** InfoList *****************/
//Linkedlist of PersonalInfo

InfoList::InfoList(){
    head = NULL;
}

InfoList::InfoList(const InfoList & src){
    PersonalInfo * ptr = src.head;
    PersonalInfo * last = NULL;
    PersonalInfo * nptr = NULL;
    head = NULL;

    while(ptr != NULL){
        nptr = new PersonalInfo(ptr->getName(), ptr->getBirthday());
        if(last == NULL) head = nptr;
        else last->setNext(nptr);
        ptr = ptr -> getNext();
        last = nptr;
    }
}

InfoList::~InfoList(){
    PersonalInfo * ptr;
    while(head != NULL){
        ptr = head;
        head = ptr->getNext();
        delete ptr;
    }
}

InfoList & InfoList::operator = (const InfoList & rhs){
    if (this == &rhs) return (*this);

    //Delete list of *this
    PersonalInfo * ptr;
    while(head != NULL){
        ptr = head;
        head = ptr->getNext();
        delete ptr;
    }

    //Copy constructor code - allocate new PersonalInfo and copy from rhs
    ptr = rhs.head;
    PersonalInfo * last = NULL;
    PersonalInfo * nptr = NULL;
    head = NULL;

    while(ptr != NULL){
        nptr = new PersonalInfo(ptr->getName(), ptr->getBirthday());
        if(last == NULL) head = nptr;
        else last->setNext(nptr);
        ptr = ptr -> getNext();
        last = nptr;
    }
    return (*this);
}

PersonalInfo * InfoList::LocateInList(string n){
    PersonalInfo * tptr = head;
    while(tptr != NULL){
        if(tptr->getName() == n) break;
        tptr = tptr->getNext();
    }
    return tptr;
}

PersonalInfo * InfoList::LocateInList(string n, int y, int m, int d){
    PersonalInfo * tptr = head;
    while(tptr != NULL){
        if(tptr->getName() == n){
            if(tptr->getBirthday()->yr == y){
                if(tptr->getBirthday()->mo == m){
                    if(tptr->getBirthday()->day == d){
                        break;
                    }
                }
            }
        }
        tptr = tptr->getNext();
    }
    return tptr;
}

void InfoList::insertAtHead(PersonalInfo * nptr){
    nptr -> setNext(head);
    head = nptr;
}

void InfoList::insertAtTail(PersonalInfo * nptr){
    if(head == NULL){
        head = nptr;
        nptr->setNext(NULL);
    }
    else{
        PersonalInfo * tptr = head;
        while(tptr->getNext() != NULL){
            tptr = tptr->getNext();
        }
        tptr->setNext(nptr);
        nptr->setNext(NULL);
    }
}

void InfoList::deleteInfo(string n){
    if(head == NULL) return;
    PersonalInfo * tptr = head;
    PersonalInfo * pptr = NULL;
    while(tptr != NULL){
        if(tptr->getName() == n) break;
        pptr = tptr;
        tptr = tptr->getNext();
    }
    if(tptr == NULL) return;
    if(tptr == head){
        head = head -> getNext();
        delete tptr;
        return;
    }
    pptr -> setNext(tptr->getNext());
    delete tptr;
}

void InfoList::deleteInfo(string n, int y, int m, int d){
    if(head == NULL) return;
    PersonalInfo * tptr = head;
    PersonalInfo * pptr = NULL;
    while(tptr != NULL){
        if(tptr->getName() == n){
            if(tptr->getBirthday()->yr == y){
                if(tptr->getBirthday()->mo == m){
                    if(tptr->getBirthday()->day == d){
                        break;
                    }
                }
            }
        }
        pptr = tptr;
        tptr = tptr->getNext();
    }
    if(tptr == NULL) return;
    if(tptr == head){
        head = head -> getNext();
        delete tptr;
        return;
    }
    pptr -> setNext(tptr->getNext());
    delete tptr;
}

void InfoList::print() const{
    PersonalInfo * tptr = head;
    while(tptr != NULL){
        tptr->print();
        tptr = tptr->getNext();
    }
}

/*************** PersonalInfo **************/
//Personal information container
   
PersonalInfo::PersonalInfo(const PersonalInfo & src){
    bd_ptr = new struct birthday;
    name = src.name;
    bd_ptr -> yr = src.bd_ptr -> yr;
    bd_ptr -> mo = src.bd_ptr -> mo;
    bd_ptr -> day = src.bd_ptr -> day;
    next = src.next;
}

PersonalInfo& PersonalInfo::operator=(const PersonalInfo & rhs){
    bd_ptr = new struct birthday;
    name = rhs.name;
    bd_ptr -> yr = rhs.bd_ptr -> yr;
    bd_ptr -> mo = rhs.bd_ptr -> mo;
    bd_ptr -> day = rhs.bd_ptr -> day;
    next = rhs.next;
    return (*this);
}

PersonalInfo::PersonalInfo(){
    bd_ptr = new struct birthday;
    name = "";
    bd_ptr -> yr = 1900;
    bd_ptr -> mo = 1;
    bd_ptr -> day = 1;
    next = NULL;
}

PersonalInfo::PersonalInfo(string n, int y, int m, int d){
    bd_ptr = new struct birthday;
    name = n;
    bd_ptr -> yr = y;
    bd_ptr -> mo = m;
    bd_ptr -> day = d;
    next = NULL;
}

PersonalInfo::PersonalInfo(string n, birthday * bpr){
    bd_ptr = new struct birthday;
    name = n;
    bd_ptr = bpr;
    next = NULL;
}

PersonalInfo::PersonalInfo(string n, int y, int m, int d, PersonalInfo * nxt){
    bd_ptr = new struct birthday;
    name = n;
    bd_ptr -> yr = y;
    bd_ptr -> mo = m;
    bd_ptr -> day = d;
    next = nxt;
}

PersonalInfo::PersonalInfo(string n, birthday * bpr, PersonalInfo * nxt){
    bd_ptr = new struct birthday;
    name = n;
    bd_ptr = bpr;
    next = nxt;
}


PersonalInfo::~PersonalInfo(){
    delete bd_ptr;
}

string PersonalInfo::getName(){
    return name;
}

const string PersonalInfo::getName() const{
    return name;
}

birthday * PersonalInfo::getBirthday(){
    return bd_ptr;
}

const birthday * PersonalInfo::getBirthday() const {
    return bd_ptr;
}


PersonalInfo * PersonalInfo::getNext(){
    return next;
}

const PersonalInfo * PersonalInfo::getNext() const {
    return next;
}

void PersonalInfo::setNext(PersonalInfo * item){
    next = item;
}

bool PersonalInfo::hasNext() const{
    //If next is not null (has next), return true
    return (next != NULL);
}

void PersonalInfo::setName(string n){
    name = n;
}

void PersonalInfo::setBirthday(int y, int m, int d){
    bd_ptr -> yr = y;
    bd_ptr -> mo = m;
    bd_ptr -> day = d;
}

void PersonalInfo::print() const{
    cout << "Name: " << name << " , Birthday: " << bd_ptr -> yr << "/" << bd_ptr -> mo << "/" << bd_ptr -> day << endl;
}