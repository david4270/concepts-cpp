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


double calculator(string inputLine){
    vector<string> inputList;
    vector<string> inputSplit;
    string substr, bracInput, tempStr, finCalc;
    double subflt, temp;
    char subchar;
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

    return stod(tempStr);
}