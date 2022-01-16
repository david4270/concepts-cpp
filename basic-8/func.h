#ifndef _func_h
#define _func_h

#include <iostream>
#include <string>

class PersonalInfo{
    private:
        string name;
        int birthYear;
        int birthMonth;
        int birthDay;
        bool isMarried;
    public:

    
};

class AdditionalInfo: public PersonalInfo{
    private:
        string mailAddr;
        string address;
        char sex;
    public:

    
};

class FullContact: public AdditionalInfo, public PhoneInfo{
    private:
        string phoneNumber;
    public:

    
};

class PhoneInfo {
    private:
        string model;
        string IMEI;
    public:


};

#endif