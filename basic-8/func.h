#ifndef _func_h
#define _func_h

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int returnAge(int yr, int mo, int day);

class PersonalInfo{
    private:
        string name;
        int birthYear;
        int birthMonth;
        int birthDay;
        int age;
        bool isMarried;
    public:
        PersonalInfo();
        PersonalInfo(string n, int y, int m, int d, bool ism);
        PersonalInfo(PersonalInfo & rhs);
        ~PersonalInfo();
        
        void setInfo(string n, int y, int m, int d, bool ism);
        void setName(string n);
        void setBirthday(int y, int m, int d);
        void setMarried(bool ism);

        string getName();
        int getbirthYear();
        int getbirthMonth();
        int getbirthDay();
        int getAge();
        bool getisMarried();

        void print() const;
};

class AdditionalInfo: public PersonalInfo{
    private:
        string emailAddr;
        string address;
        char sex;
    public:
        AdditionalInfo();
        AdditionalInfo(string nm, int y, int m, int d, bool ism, string ma, string ad, char sx);
        AdditionalInfo(AdditionalInfo & rhs);
        ~AdditionalInfo();

        void setAddInfo(string nm, int y, int m, int d, bool ism, string ma, string ad, char sx);
        void setemailAddr(string ma);
        void setAddr(string ad);
        void setSex(char sx);

        string getemailAddr();
        string getAddr();
        char getSex();

        void print() const;
    
};

//All IMEIs used are completely fictional
class PhoneInfo {
    private:
        string model;
        string IMEI;
    public:
        PhoneInfo();
        PhoneInfo(string mo, string im);
        PhoneInfo(PhoneInfo & rhs);
        ~PhoneInfo();

        void setPhoneInfo(string mo, string im);
        void setModel(string mo);
        void setIMEI(string im);

        string getModel();
        string getIMEI();

        void print() const;

};

class FullContact: public AdditionalInfo, public PhoneInfo{
    private:
        string phoneNumber;
    public:
        FullContact();
        FullContact(string nm, int y, int m, int d, bool ism, string ma, string ad, char sx, string mo, string im, string pn);
        FullContact(FullContact & rhs);
        ~FullContact();

        void setFullContact(string nm, int y, int m, int d, bool ism, string ma, string ad, char sx, string mo, string im, string pn);
        void setphoneNumber(string pn);

        string getphoneNumber();

        void print() const;
    
};



#endif