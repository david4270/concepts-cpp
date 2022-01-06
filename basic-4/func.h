#ifndef _func_h
#define _func_h

#include <string>
#include <iostream>

using namespace std;

struct _birthday {int yr, mo, day;};

class PersonalInfo{
    private:
        PersonalInfo * next;
        string name;
        struct _birthday * bd_ptr;
        bool isMarried;
    public:
        PersonalInfo();
        PersonalInfo(string n, int y, int m, int d);
        PersonalInfo(const PersonalInfo & src);
        ~PersonalInfo();
        void setName(string n);
        void setBirthday(int y, int m, int d);
        void print();
};

#endif