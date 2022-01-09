#ifndef _func_h
#define _func_h

#include <string>
#include <iostream>

using namespace std;

struct birthday {int yr, mo, day;};

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
        PersonalInfo(string n, birthday * bpr);
        PersonalInfo(string n, int y, int m, int d, PersonalInfo * nxt);
        PersonalInfo(string n, birthday * bpr, PersonalInfo * nxt);
        ~PersonalInfo();

        string getName();
        const string getName() const;
        birthday * getBirthday(); 
        const birthday * getBirthday() const; 
        PersonalInfo * getNext();
        const PersonalInfo * getNext() const;

        void setNext(PersonalInfo * item);
        bool hasNext() const;

        void setName(string n);
        void setBirthday(int y, int m, int d);
        void print() const;
};

class InfoList{
    private:
        PersonalInfo * head;
    public:
        InfoList();
        InfoList(const InfoList & src);
        ~InfoList();

        InfoList & operator=(const InfoList & rhs);

        PersonalInfo * LocateInList(string n);
        PersonalInfo * LocateInList(string n, int y, int m, int d);

        void insertAtHead(PersonalInfo * nptr);
        void insertAtTail(PersonalInfo * nptr);
        void deleteInfo(string n);
        void deleteInfo(string n, int y, int m, int d);

        void print() const; //traverse and print list
};

#endif