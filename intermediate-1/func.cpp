#include <iostream>
#include "func.h"

using namespace std;



/********** Edge Class **********/

Edge::Edge(int sid, int eid, int id, bool oneway){
    startNodeID = sid;
    endNodeID = eid;
    edgeID = id;
    oneDir = oneway;
}

Edge::~Edge(){

}


Road::Road(int sid, int eid, int id, bool oneway, string tp): Edge(sid,eid,oneway,id){
    Type = tp;
}

Road::~Road(){

}

Rail::Rail(int sid, int eid, int id, bool oneway, string tp): Edge(sid,eid,oneway,id){
    Type = tp;
}

Rail::~Rail(){

}

/********** Node Class **********/


Node::Node(double x, double y, int id){
    xCoord = x;
    yCoord = y;
    nodeID = id;
}

Node::~Node(){

}


NodeFeature::NodeFeature(double x, double y, int id, string tp): Node(x, y, id){
    Type = tp;
}

NodeFeature::~NodeFeature(){

}

/********** Graph Class **********/

