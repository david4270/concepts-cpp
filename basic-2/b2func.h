#ifndef _b2func_h
#define _b2func_h

#include <iostream>

class Day{
    private:
        int day;
        int month;
        int year;
    public:
        Day();
        Day(int y, int m, int d);
        ~Day();
        void setDay(int d);
        void setMonth(int m);
        void setYear(int y);
        void setDMY(int y, int m, int d);
        void print();
};

#endif