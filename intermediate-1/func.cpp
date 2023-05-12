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

/********** Edge Features Classes **********/

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
    cout << "X Coord: " << xCoord << ", Y Coord: " << yCoord << ", ID: " << nodeID << ", Edge IDs";
    for(int ed: connectedEdgeList){
        cout << " - " << ed;
    }
    cout << endl;
}

void Node::addInitEdgeID(int edid){
    connectedEdgeList.push_back(edid);
}


/********** Node Feature Class **********/

NodeFeature::NodeFeature(double x, double y, int id, string tp): Node(x, y, id){
    Type = tp;
}

NodeFeature::~NodeFeature(){

}

/********** Graph Class **********/
Graph::Graph(){    
}

Graph::~Graph(){
    for(int i = 0; i < listNodes.size(); i++){
        delete listNodes[i];
    }
    for(int i = 0; i < listEdges.size(); i++){
        delete listEdges[i];
    }
    listEdges.clear();
    listNodes.clear();
}

void Graph::addNode(double x, double y, int id){
    int testIdx;
    testIdx = checkNode(id);
    if(testIdx >= 0){
        cout << "Node " << id << " already exists, failed to insert" << endl;
        return;
    }
    Node * toPush = new Node(x,y,id);
    listNodes.push_back(toPush);
}

void Graph::addEdge(int sid, int eid, int id, bool oneway){
    int startIdx, endIdx, testIdx;
    Node * start;
    Node * end;
    testIdx = checkEdge(id);
    if(testIdx >= 0){
        cout << "Edge " << id << " already exists, failed to insert" << endl;
        return;
    }
    Edge * toPush = new Edge(sid,eid,id,oneway);
    startIdx = checkNode(sid);
    endIdx = checkNode(eid);
    if(startIdx >= 0 && endIdx >= 0){
        start = findNode(startIdx);
        end = findNode(endIdx);
    }
    else{
        delete toPush;
        cout << "Cannot insert edge " << id << endl;
        return;
    }
    start->addInitEdgeID(id);
    pair<double,double> startXY = start->getXY();
    pair<double,double> endXY = end->getXY();
    double len = sqrt(pow(endXY.first - startXY.first,2)+pow(endXY.second - startXY.second,2));
    toPush->setLength(len);

    listEdges.push_back(toPush);
}

vector<Node *> Graph::getlistNodes(){
    return listNodes;
}

vector<Edge *> Graph::getlistEdges(){
    return listEdges;
}

void Graph::printlistNodesData(){
    if(!listNodes.empty()){
        for(int i = 0; i < listNodes.size(); i++){
            listNodes[i] -> printNodeData();
        }
    }
    else{
        cout << "listNodes empty" << endl;
    }
}

void Graph::printlistEdgesData(){
    if(!listEdges.empty()){
        for(int i = 0; i < listEdges.size(); i++){
            listEdges[i] -> printEdgeData();
        }
    }
    else{
        cout << "listEdges empty" << endl;
    }
}

int Graph::checkNode(int nID){
    for(int i = 0; i < listNodes.size(); i++){
        if(listNodes[i]->getID() == nID){
            return i;
        }
    }
    return -1;
}

int Graph::checkEdge(int eID){
    for(int i = 0; i < listEdges.size(); i++){
        if(listEdges[i]->getID() == eID){
            return i;
        }
    }
    return -1;
}

Node * Graph::findNode(int idx){
    return listNodes[idx];
}

Edge * Graph::findEdge(int idx){
    return listEdges[idx];
}

/********** Functions **********/


void nodeImport(Graph & myMap){
    string fname = "node.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
            stringstream str(line);
            while(getline(str, word, ',')){
                row.push_back(word);
            }
            content.push_back(row);
        }
    }
    else cout << "Cannot open " << fname << endl;

    for(int i=1;i<content.size();i++){
		myMap.addNode(stod(content[i][1]), stod(content[i][2]), stoi(content[i][0]));
	}

    //myMap.printlistNodesData();

}

void edgeImport(Graph & myMap){
    string fname = "edge.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
            stringstream str(line);
            while(getline(str, word, ',')){
                row.push_back(word);
            }
            content.push_back(row);
        }
    }
    else cout << "Cannot open " << fname << endl;

    for(int i=1;i<content.size();i++){
		myMap.addEdge(stoi(content[i][1]), stoi(content[i][2]), stoi(content[i][0]), true);
	}

    //myMap.printlistEdgesData();

}

