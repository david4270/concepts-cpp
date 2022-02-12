// Minimap project using inheritance and graph

#include <iostream>
#include "func.h"

using namespace std;

int main(){
    Graph myMap;
    myMap.addNode(0.1253,0.2145,1);
    myMap.addNode(0.3464,0.7452,2);
    myMap.addNode(0.4564,0.3456,3);
    myMap.addNode(0.5634,0.4754,4);
    myMap.printlistNodesData();
    myMap.addEdge(2,1,1,true);
    myMap.addEdge(4,2,2,true);
    myMap.addEdge(3,4,3,true);
    myMap.addEdge(1,3,4,true);
    myMap.addEdge(3,2,5,true);
    myMap.printlistEdgesData();
    return 0;
}

// How to compile this code
// g++ -std=c++11 -c main.cpp
// g++ -std=c++11 -c func.cpp 
// g++ -std=c++11 main.o func.o -o main.exe   