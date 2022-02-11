#include <iostream>
#include "func.h"

using namespace std;



/********** Edge Class **********/

Edge::Edge(){
    start = NULL;
    end = NULL;
    edgeID = 0;
}

Edge::Edge(Node * st, Node * ed, int id){
    start = st;
    end = ed;
    edgeID = 0;
}

Edge::~Edge(){

}

Road::Road(): Edge(){
    Type = "";
}

Road::Road(Node * st, Node * ed, int id, string tp): Edge(st,ed,id){
    Type = tp;
}

Road::~Road(){

}

Rail::Rail(): Edge(){
    Type = "";
}

Rail::Rail(Node * st, Node * ed, int id, string tp): Edge(st,ed,id){
    Type = tp;
}

Rail::~Rail(){

}

/********** Node Class **********/

Node::Node(){
    xCoord = 0;
    yCoord = 0;
    nodeID = 0;
}

Node::Node(double x, double y, int id){
    xCoord = x;
    yCoord = y;
    nodeID = id;
}

Node::~Node(){

}

NodeFeature::NodeFeature(): Node(){
    Type = "";
}

NodeFeature::NodeFeature(double x, double y, int id, string tp): Node(x, y, id){
    Type = tp;
}

NodeFeature::~NodeFeature(){

}

/********** Graph Class **********/

