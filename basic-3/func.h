#ifndef _func_h
#define _func_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void findOccurrances(vector<size_t> &vec, string toAnalyze, string toFind);
void bracketTester(vector<size_t> & leftBracketPos, vector<size_t> & rightBracketPos);
void orderBrackets(vector<size_t> & leftBracketPos, vector<size_t> & rightBracketPos, vector<pair<size_t,size_t>> & bracketList);
string calcProc(string inputLine);

#endif