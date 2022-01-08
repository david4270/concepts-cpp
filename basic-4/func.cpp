#include <iostream>
#include "func.h"

using namespace std;

/*************** InfoList *****************/
InfoList::InfoList(){

}

InfoList::InfoList(const InfoList & src){

}

InfoList::~InfoList(){

}


/*************** PersonalInfo **************/

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

PersonalInfo::~PersonalInfo(){
    delete bd_ptr;
}


birthday & PersonalInfo::getBirthday(){
    return * bd_ptr;
}

const birthday & PersonalInfo::getBirthday() const {
    return * bd_ptr;
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