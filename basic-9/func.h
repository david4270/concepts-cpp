#ifndef _func_h
#define _func_h

#include <iostream>
#include <string>

class HashTable{
    private:
        PersonName * Hash[10];

    public:
        void insertElement(string nm);
        bool searchElement(string nm);
        bool deleteElement(string nm);

        void printTable();
        bool deleteTable();


};

class PersonName{
    private:
        PersonName * next;
        int key;
        string name;
    public:
        PersonName();
        PersonName(string name);
        ~PersonName();

        void setName(string name);
        string getName();

        void print() const;
};

#endif