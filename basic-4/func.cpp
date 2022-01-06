#include <iostream>
#include "func.h"

using namespace std;

PersonalInfo::PersonalInfo(){
    bd_ptr = new struct _birthday;
    name = "";
    bd_ptr -> yr = 1900;
    bd_ptr -> mo = 1;
    bd_ptr -> day = 1;
}

PersonalInfo::PersonalInfo(string n, int y, int m, int d){
    bd_ptr = new struct _birthday;
    name = n;
    bd_ptr -> yr = y;
    bd_ptr -> mo = m;
    bd_ptr -> day = d;
}

PersonalInfo::PersonalInfo(const PersonalInfo & src){
    bd_ptr = new struct _birthday;
    name = src.name;
    bd_ptr -> yr = src.bd_ptr -> yr;
    bd_ptr -> mo = src.bd_ptr -> mo;
    bd_ptr -> day = src.bd_ptr -> day;
}

PersonalInfo::~PersonalInfo(){
    delete bd_ptr;
}

void PersonalInfo::setName(string n){
    name = n;
}

void PersonalInfo::setBirthday(int y, int m, int d){
    bd_ptr -> yr = y;
    bd_ptr -> mo = m;
    bd_ptr -> day = d;
}

void PersonalInfo::print(){
    cout << "Name: " << name << " , Birthday: " << bd_ptr -> yr << "/" << bd_ptr -> mo << "/" << bd_ptr -> day << endl;
}