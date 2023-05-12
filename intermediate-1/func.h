#ifndef _func_h
#define _func_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//change int to typedefs later!
typedef int edgeIdx;
typedef int nodeIdx;


/********** Edge **********/

class Edge{
    private:
        int startNodeID;
        int endNodeID;
        int edgeID;
        bool oneDir;
        double length;
    public:
        Edge(int sid, int eid, int id, bool oneway);
        ~Edge();

        pair<int,int> getStartEndNodeID();

        void printEdgeData();
        int getID();
        void setLength(double len);
};

/********** Edge Features Classes **********/

class Road: public Edge{
    private:
        string Type;
    public:
        Road(int sid, int eid, int id, bool oneway, string tp);
        ~Road();
};

class Rail: public Edge{
    private:
        string Type;
    public:
        Rail(int sid, int eid, int id, bool oneway, string tp);
        ~Rail();
};

/********** Node **********/

class Node{
    private:
        double xCoord;
        double yCoord;
        int nodeID;
        vector<int> connectedEdgeList;
    public:
        Node(double x, double y, int id); 
        ~Node();

        pair<double,double> getXY();
        int getID();

        void printNodeData();

        void addInitEdgeID(int edid);
        
};

/********** Node Feature Class **********/

class NodeFeature: public Node{
    private:
        string Type;
    public:
        NodeFeature(double x, double y, int id, string tp);
        ~NodeFeature();
};


/********** Graph **********/

class Graph{
    private:
        vector<Node *> listNodes;
        vector<Edge *> listEdges;
    public:
        Graph();
        ~Graph();
        void addNode(double x, double y, int id);
        void addEdge(int sid, int eid, int id, bool oneway);
        vector<Node *> getlistNodes();
        vector<Edge *> getlistEdges();
        void printlistNodesData();
        void printlistEdgesData();

        int checkNode(int nID);
        int checkEdge(int eID);

        Node * findNode(int idx);
        Edge * findEdge(int idx);

};

/********** Functions **********/
void nodeImport(Graph & myMap);
void edgeImport(Graph & myMap);

//Todo
// Seems like graph is working now
// 1) Import edge and node data from csv files
// 2) Add object-oriented stuff - more features to node and edge


#endif