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
        PersonalInfo();
        PersonalInfo(string n, int y, int m, int d, bool ism);
        ~PersonalInfo();
        
        void setName(string n);
        void setBirthday(int y, int m, int d);
        void setMarried(bool ism);

        string getName();
        int getbirthYear();
        int getbirthMonth();
        int getbirthDay();
        bool getisMarried();

        void print() const;
};

class AdditionalInfo: public PersonalInfo{
    private:
        string mailAddr;
        string address;
        char sex;
    public:
        AdditionalInfo();
        AdditionalInfo(string ma, string ad, char sx);
        ~AdditionalInfo();

        void setmailAddr(string ma);
        void setAddr(string ad);
        void setSex(char sx);

        string getmailAddr();
        string getAddr();
        char getSex();

        void print() const;
    
};

class FullContact: public AdditionalInfo, public PhoneInfo{
    private:
        string phoneNumber;
    public:
        FullContact();
        FullContact(string pn);
        ~FullContact();

        void setphoneNumber(string pn);

        string getphoneNumber();

        void print() const;
    
};

class PhoneInfo {
    private:
        string model;
        string IMEI;
    public:
        PhoneInfo();
        PhoneInfo(string mo, string im);
        ~PhoneInfo();

        void setModel(string mo);
        void setIMEI(string im);

        string getModel();
        string getIMEI();

        void print() const;

};

#endif