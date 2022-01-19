#include <iostream>
#include "func.h"

using namespace std;

/****** PersonalInfo class ******/
PersonalInfo::PersonalInfo(){
    name = "";
    birthYear = 1900;
    birthMonth = 1;
    birthDay = 1;
    isMarried = false;
}

PersonalInfo::PersonalInfo(PersonalInfo & rhs){
    name = rhs.name;
    birthYear = rhs.birthYear;
    birthMonth = rhs.birthMonth;
    birthDay = rhs.birthDay;
    isMarried = rhs.isMarried;
}

PersonalInfo::~PersonalInfo(){

}

void PersonalInfo::setInfo(string n, int y, int m, int d, bool ism){
    name = n;
    birthYear = y;
    birthMonth = m;
    birthDay = d;
    isMarried = ism;
}

void PersonalInfo::setName(string n){
    name = n;
}

void PersonalInfo::setBirthday(int y, int m, int d){
    birthYear = y;
    birthMonth = m;
    birthDay = d;
}

void PersonalInfo::setMarried(bool ism){
    isMarried = ism;
}

string PersonalInfo::getName(){
    return name;
}

int PersonalInfo::getbirthYear(){
    return birthYear;
}

int PersonalInfo::getbirthMonth(){
    return birthMonth;
}

int PersonalInfo::getbirthDay(){
    return birthDay;
}

bool PersonalInfo::getisMarried(){
    return isMarried;
}

void PersonalInfo::print() const{
    cout << "Name: " << name <<", Birthday: " << birthYear <<"/" << birthMonth << "/" << birthDay;
    if(isMarried){
        cout << "Married: Yes" << endl;
    }
    else{
        cout << "Married: No" << endl;
    }
}


/****** AdditionalInfo class ******/
AdditionalInfo::AdditionalInfo(){
    emailAddr = "";
    address = "";
    sex = 0;
}   

AdditionalInfo::AdditionalInfo(AdditionalInfo & rhs): PersonalInfo(rhs){
    emailAddr = rhs.emailAddr;
    address = rhs.address;
    sex = rhs.sex;
}

AdditionalInfo::~AdditionalInfo(){

}

void AdditionalInfo::setAddInfo(string nm, int y, int m, int d, bool ism, string ma, string ad, char sx){
    setInfo(nm, y, m, d, ism);
    emailAddr = ma;
    address = ad;
    sex = sx;
}
void AdditionalInfo::setemailAddr(string ma){
    emailAddr = ma;
}
void AdditionalInfo::setAddr(string ad){
    address = ad;
}
void AdditionalInfo::setSex(char sx){
    sex = sx;
}

string AdditionalInfo::getemailAddr(){
    return emailAddr;
}
string AdditionalInfo::getAddr(){
    return address;
}
char AdditionalInfo::getSex(){
    return sex;
}

void AdditionalInfo::print() const{
    PersonalInfo::print();
    cout << "E-mail address: " << emailAddr << endl;
    cout << "Address: " << address << endl;
    cout << "Sex: " << sex << endl;
}


/****** FullContact class ******/
FullContact::FullContact(){
    phoneNumber = "";
}

FullContact::FullContact(FullContact & rhs): AdditionalInfo(rhs), PhoneInfo(rhs){
    phoneNumber = rhs.phoneNumber;
}

FullContact::~FullContact(){

}

void FullContact::setFullContact(string nm, int y, int m, int d, bool ism, string ma, string ad, char sx, string mo, string im, string pn){
    setAddInfo(nm, y, m, d, ism, ma, ad, sx);
    setPhoneInfo(mo,im);
    phoneNumber = pn;
}

void FullContact::setphoneNumber(string pn){
    phoneNumber = pn;
}

string FullContact::getphoneNumber(){
    return phoneNumber;
}

void FullContact::print() const{
    AdditionalInfo::print();
    PhoneInfo::print();
    cout << "Phone number: " << phoneNumber << endl;
}


/****** PhoneInfo class ******/
PhoneInfo::PhoneInfo(){
    model = "";
    IMEI = "";
}
PhoneInfo::PhoneInfo(PhoneInfo & rhs){
    model = rhs.model;
    IMEI = rhs.IMEI;
}
PhoneInfo::~PhoneInfo(){

}

void PhoneInfo::setPhoneInfo(string mo, string im){
    model = mo;
    IMEI = im;
}

void PhoneInfo::setModel(string mo){
    model = mo;
}

void PhoneInfo::setIMEI(string im){
    IMEI = im;
}

string PhoneInfo::getModel(){
    return model;
}
string PhoneInfo::getIMEI(){
    return IMEI;
}

void PhoneInfo::print() const{
    cout << "Phone model: " << model << endl;
    cout << "IMEI: " << IMEI << endl;
}

