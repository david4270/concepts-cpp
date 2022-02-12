#include <iostream>
#include "func.h"

using namespace std;



/********** Edge Class **********/

Edge::Edge(int sid, int eid, int id, bool oneway){
    startNodeID = sid;
    endNodeID = eid;
    edgeID = id;
    oneDir = oneway;
    length = 0.0;
    //Calculate length!
}

Edge::~Edge(){

}

pair<int,int> Edge::getStartEndNodeID(){
    pair<int,int> toreturn;
    toreturn.first = startNodeID;
    toreturn.second = endNodeID;
    return toreturn;
}

void Edge::printEdgeData(){
    cout << "Start at: " << startNodeID << ", Ends at: " << endNodeID << ", ID: " << edgeID;
    if(oneDir){
        cout << ", one-way, ";
    }
    else{
        cout << ", both-way, ";
    }
    cout << "Length: " << length << endl;
}

int Edge::getID(){
    return edgeID;
}

void Edge::setLength(double len){
    length = len;
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

pair<double,double> Node::getXY(){
    pair<double,double> toreturn;
    toreturn.first = xCoord;
    toreturn.second = yCoord;
    return toreturn;
}

int Node::getID(){
    return nodeID;
}

void Node::printNodeData(){
    cout << "X Coord: " << xCoord << ", Y Coord: " << yCoord << ", ID: " << nodeID << endl;
}

void Node::addInitEdgeID(int eid){
    connectedEdgeList.push_back(eid);
}

NodeFeature::NodeFeature(double x, double y, int id, string tp): Node(x, y, id){
    Type = tp;
}

NodeFeature::~NodeFeature(){

}

/********** Graph Class **********/
Graph::Graph(){    
}

Graph::~Graph(){
    listEdges.clear();
    listNodes.clear();
}

// Have to check if the id already exists
void Graph::addNode(double x, double y, int id){
    Node toPush(x,y,id);
    listNodes.push_back(toPush);
}

// Have to check if 1) the id already exists and 2) startid and endid exists
void Graph::addEdge(int sid, int eid, int id, bool oneway){
    Edge toPush(sid,eid,id,oneway);
    Node start = findNode(sid);
    Node end = findNode(eid);
    start.addInitEdgeID(id);
    pair<double,double> startXY = start.getXY();
    pair<double,double> endXY = end.getXY();
    double len = sqrt(pow(endXY.first - startXY.first,2)+pow(endXY.second - startXY.second,2));
    toPush.setLength(len);

    listEdges.push_back(toPush);
}

vector<Node> Graph::getlistNodes(){
    return listNodes;
}

vector<Edge> Graph::getlistEdges(){
    return listEdges;
}

void Graph::printlistNodesData(){
    if(!listNodes.empty()){
        for(int i = 0; i < listNodes.size(); i++){
            listNodes[i].printNodeData();
        }
    }
    else{
        cout << "listNodes empty" << endl;
    }
}

void Graph::printlistEdgesData(){
    if(!listEdges.empty()){
        for(int i = 0; i < listEdges.size(); i++){
            listEdges[i].printEdgeData();
        }
    }
    else{
        cout << "listEdges empty" << endl;
    }
}

Node Graph::findNode(int nID){
    for(Node nd: listNodes){
        if(nd.getID() == nID){
            return nd;
        }
    }
}

Edge Graph::findEdge(int eID){
    for(Edge eg: listEdges){
        if(eg.getID() == eID){
            return eg;
        }
    }
}

/********** Functions **********/





