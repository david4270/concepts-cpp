#ifndef _func_h
#define _func_h

#include <string>
#include <iostream>

using namespace std;

struct birthday {int yr, mo, day;};

class InfoList{
    private:
        PersonalInfo * head;
    public:
        InfoList();
        InfoList(const InfoList & src);
        ~InfoList();

        InfoList & operator=(const InfoList & rhs);

        void print() const;
};

class PersonalInfo{
    private:
        PersonalInfo * next;
        string name;
        struct birthday * bd_ptr;
        bool isMarried;
        PersonalInfo(const PersonalInfo & src);
        PersonalInfo& operator=(const PersonalInfo & rhs);
    public:
        PersonalInfo();
        PersonalInfo(string n, int y, int m, int d);
        ~PersonalInfo();

        birthday& getBirthday(); 
        const birthday& getBirthday() const; 
        PersonalInfo * getNext();
        const PersonalInfo * getNext() const;

        void setNext(PersonalInfo * item);
        bool hasNext() const;

        void setName(string n);
        void setBirthday(int y, int m, int d);
        void print() const;
};

#endif