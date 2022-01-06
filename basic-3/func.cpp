#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "func.h"

using namespace std;

//https://thispointer.com/find-all-occurrences-of-a-sub-string-in-a-string-c-both-case-sensitive-insensitive/
void findOccurrances(vector<size_t> &vec, string toAnalyze, string toFind){
    size_t pos = toAnalyze.find(toFind); //first occurrance
    size_t prevPos = 0;
    string temp = toAnalyze.substr(pos+1);
    while(pos != string::npos){
        vec.push_back(pos+prevPos); 
        prevPos = pos+prevPos+1;
        pos = temp.find(toFind);
        temp = temp.substr(pos+1);
    }
}

void bracketTester(vector<size_t> & leftBracketPos, vector<size_t> & rightBracketPos){
    for(size_t pos : leftBracketPos){
        cout << pos << " ";
    }
    cout << endl;
            
    for(size_t pos : rightBracketPos){
        cout << pos << " ";
    }
    cout << endl;
}


void orderBrackets(vector<size_t> & leftBracketPos, vector<size_t> & rightBracketPos, vector<pair<size_t,size_t>> & bracketList){
    
    for(int i = 0; i < leftBracketPos.size(); i++){
        
        while( ((leftBracketPos[i+1] < rightBracketPos[i]) && (leftBracketPos[i+1] > leftBracketPos[i])) ||  ((leftBracketPos[i] > rightBracketPos[i]) ) ){
            if((leftBracketPos[i+1] < rightBracketPos[i]) && (leftBracketPos[i+1] > leftBracketPos[i])){
                if(rightBracketPos[i] > rightBracketPos[i+1]){
                    rightBracketPos.push_back(rightBracketPos[i]);
                    rightBracketPos.erase(rightBracketPos.begin() + i);
                }
                else{
                    leftBracketPos.push_back(leftBracketPos[i]);
                    leftBracketPos.erase(leftBracketPos.begin() + i);
                }
                
            }
            
            if ((leftBracketPos[i] > rightBracketPos[i])){
                rightBracketPos.push_back(rightBracketPos[i]);
                rightBracketPos.erase(rightBracketPos.begin() + i);
            }
            
            //bracketTester(leftBracketPos,rightBracketPos);
        }
       
        bracketList.push_back(make_pair(leftBracketPos[i], rightBracketPos[i]));
        cout << "(" << leftBracketPos[i] << "," << rightBracketPos[i] << ")" << endl;
        
    }
    cout << endl;
}

string calcProc(string inputLine){
    vector<string> inputList;
    string substr, bracInput;
    double subflt, temp;
    char subchar;
    stringstream calcStream (inputLine);
    bool evenOrder = false;

    while(!calcStream.eof()){
        if(!evenOrder){
            calcStream >> subflt;
            cout << subflt <<endl;
            
            inputList.push_back(to_string(subflt));
            evenOrder = true;

        }
        else{
            calcStream >> subchar;
            cout << subchar <<endl;
            if(subchar == '+' || subchar == '-' || subchar == '*' || subchar == '/' || subchar == '^'){
                inputList.push_back(string(1,subchar));
            }
            else break;
            evenOrder = false;
        }
        
        if(calcStream.eof() || calcStream.fail()){
            break;
        }

       // cout << calcStream.peek() << endl;
        
        if(calcStream.peek() == 32){
            break;
        }
    }

    for(int i = 0; i < inputList.size(); i++){
        cout << inputList[i] << " ";
    }
    cout << endl;

    //Exponential
    for(int i = 0; i < inputList.size(); i++){
       if(inputList[i] == "^"){
            temp =  pow(stod(inputList[i-1]), stod(inputList[i+1]));
            inputList[i-1] = to_string(temp);
            inputList.erase(inputList.begin()+i);
            inputList.erase(inputList.begin()+i);
            i--;
       }
    }

    //Multiplication/Division
    for(int i = 0; i < inputList.size(); i++){
       if(inputList[i] == "*"){
            temp =  stod(inputList[i-1]) * stod(inputList[i+1]);
            inputList[i-1] = to_string(temp);
            inputList.erase(inputList.begin()+i);
            inputList.erase(inputList.begin()+i);
            i--;
       }

       if(inputList[i] == "/"){
            temp =  stod(inputList[i-1]) / stod(inputList[i+1]);
            inputList[i-1] = to_string(temp);
            inputList.erase(inputList.begin()+i);
            inputList.erase(inputList.begin()+i);
            i--;
       }
    }

    //Addition/Subtraction
    for(int i = 0; i < inputList.size(); i++){
       if(inputList[i] == "+"){
            temp =  stod(inputList[i-1]) + stod(inputList[i+1]);
            inputList[i-1] = to_string(temp);
            inputList.erase(inputList.begin()+i);
            inputList.erase(inputList.begin()+i);
            i--;
       }

       if(inputList[i] == "-"){
            temp =  stod(inputList[i-1]) - stod(inputList[i+1]);
            inputList[i-1] = to_string(temp);
            inputList.erase(inputList.begin()+i);
            inputList.erase(inputList.begin()+i);
            i--;
       }
    }

    return(inputList[0]);

}