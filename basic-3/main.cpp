//Input and Output, Streams + Vectors and Pair

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "func.h"

using namespace std;

// Accept arguments!
// Example: 3 + 1 -> Returns 4
// Example: 3 Add 1 -> Returns 4
// Example: 3 Add 1 - 2 -> Returns 2

int main(){
    vector<string> inputList;
    vector<string> inputSplit;
    string inputLine, substr, bracInput, tempStr, finCalc;
    double subflt, temp;
    char subchar;

    getline(cin,inputLine);

    inputLine.erase(remove_if(inputLine.begin(), inputLine.end(), ::isspace), inputLine.end());

    //Deal with brackets

    vector<size_t> leftBracketPos, rightBracketPos;
    vector<pair<size_t,size_t>> bracketList;

    findOccurrances(leftBracketPos,inputLine, "(");
    findOccurrances(rightBracketPos,inputLine, ")");

    //bracketTester(leftBracketPos,rightBracketPos);

    int ctr = 0;

    for(int i=0; i <= inputLine.length(); i++){
        if(find(leftBracketPos.begin(),leftBracketPos.end(),i) != leftBracketPos.end()){
            inputSplit.push_back(inputLine.substr(ctr,i-ctr));
            inputSplit.push_back("(");
            ctr = i+1;
        }
        else if(find(rightBracketPos.begin(), rightBracketPos.end(),i) != rightBracketPos.end()){
            inputSplit.push_back(inputLine.substr(ctr,i-ctr));
            inputSplit.push_back(")");
            ctr = i+1;
        }
    }
    inputSplit.push_back(inputLine.substr(ctr,inputLine.length()-ctr));
    
    for(int i = 0; i < inputSplit.size(); i++){
        cout << inputSplit[i] << " ";
    }
    cout << endl;
       
    
    if(leftBracketPos.size() != rightBracketPos.size()){
        cout << "Wrong Input" << endl;
        return 0;
    }

    leftBracketPos.clear();
    rightBracketPos.clear();

    for(size_t i = 0; i < inputSplit.size(); i++){
        if(inputSplit[i] == "("){
            leftBracketPos.push_back(i);
        }
        else if(inputSplit[i] == ")"){
            rightBracketPos.push_back(i);
        }
    }

    //bracketTester(leftBracketPos,rightBracketPos);
    orderBrackets(leftBracketPos,rightBracketPos,bracketList);
    
    for(pair<size_t,size_t> bkl : bracketList){
        cout << "(" << bkl.first << "," << bkl.second << ")" << endl;

        bracInput = "";

        for (size_t i = bkl.first+1; i < bkl.second; i++){
            if(inputSplit[i] != ""){
                bracInput.append(inputSplit[i]);
            }
        }
        cout << bracInput << endl;

        tempStr = calcProc(bracInput);

        cout << tempStr << endl;
        for (size_t i = bkl.first; i <= bkl.second; i++){
            if(i == bkl.first){
                inputSplit[i]=tempStr;
            }
            else{
                inputSplit[i]="";
            }
        }
        for(int i = 0; i < inputSplit.size(); i++){
            cout << inputSplit[i] << " ";
        }
        cout << endl;
    }
    
    //After calculating brackets
    for(int i = 0; i < inputSplit.size(); i++){
        if(inputSplit[i] != ""){
            finCalc.append(inputSplit[i]);
        }
    }
    cout << finCalc << endl;

    tempStr = calcProc(finCalc);
    cout << tempStr << endl;

    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   