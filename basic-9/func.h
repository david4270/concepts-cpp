#ifndef _func_h
#define _func_h

#include <iostream>
#include <string>

using namespace std;

class PersonName{
    private:
        PersonName * next;
        int key;
        string name;
    public:
        PersonName();
        PersonName(string nm);
        ~PersonName();

        void setName(string nm);
        void setNext(PersonName * nxt);

        string getName();
        int getKey();
        PersonName * getNext();

        void print() const;
};

class HashTable{
    private:
        PersonName * Hash[10];

    public:
        HashTable();
        ~HashTable();

        void insertElement(string nm);
        bool searchElement(string nm);
        bool deleteElement(string nm);

        void printTable();
        void deleteTable();
};



#endif