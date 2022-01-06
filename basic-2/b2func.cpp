#include <iostream>
#include "b2func.h"

using namespace std;

Day::Day(){
    day = 1;
    month = 1;
    year = 1900;
}

Day::Day(int y, int m, int d){
    day = d;
    month = m;
    year = y;
}

Day::~Day(){

}

void Day::setDay(int d){
    day = d;
}

void Day::setMonth(int m){
    month = m;
}

void Day::setYear(int y){
    year = y;
}

void Day::setDMY(int y, int m, int d){
    day = d;
    month = m;
    year = y;
}

void Day::print(){
    cout << "Selected day is " << year << "." << month << "." << day << endl;
}