#include <iostream>
#include "func.h"

using namespace std;

int returnAge(int yr, int mo, int day){
    int todayYr, todayMo, todayDy, age;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    todayYr = 1900 + ltm->tm_year;
    todayMo = 1 + ltm->tm_mon;
    todayDy = ltm->tm_mday;
    age = todayYr - yr;
    if(yr > todayYr){
        throw "It's impossible!";
    }
    if(mo > todayMo){
        age--;
    }
    else if(mo == todayMo){
        if(day > todayDy){
            age--;
        }
    }
    return age;
}

//Try-Throw-Catch
//Try - try out the statement within the bracket
//Throw - if exception is caught, throw error message
//Catch - if error message is thrown, catch it and print it!

//You can get driver's license in Ontario if you are 16!
//The legal age of drinking in Ontario is 19.
bool canDrinkorDrive(int y, int m, int d){
    try{
        int age = returnAge(y,m,d);
        cout << "Your age is " << age << endl;
        if(age < 16) throw "You cannot drive in Ontario";
        if(age < 19) throw "You cannot legally drink in Ontario";
        cout << "Congratulations - you are a grown-up!" << endl;
    }
    catch(const char* str){
        cout << "Exception: " << str << endl;
        return false;
    }
    return true;
}

//Make 10-word input. If larger then it will return catch
void inputStr(string type){
    int len = type.length();
    int maxSize = 10;
    char * toCopy = new char[maxSize];
    try{
        if(toCopy == NULL) throw "No content in string";
        for(int i=0; i<len; i++){
            if(i>maxSize-1) throw i;
            toCopy[i] = type[i];
        }
        if(len < maxSize){
            for(int i = len; i<maxSize; i++){
                toCopy[i] = '\0';
            }
            toCopy[maxSize] = '\0';
        }
        cout << toCopy << endl;
    }
    catch(const char* str){
        cout << "Exception: " << str << endl;
    }
    catch(int i){
        cout << "Index " << i << " is out of range" << endl;
    }
    return;
}