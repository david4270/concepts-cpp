#ifndef _func_h
#define _func_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>

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

        void addInitEdgeID(int eid);

        //input nodeID, output xCoord and yCoord pair
        //pair<double,double> returnCoord(int id); //Should it be located inside or outside of class?
        
};

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
        vector<Node> listNodes;
        vector<Edge> listEdges;
    public:
        Graph();
        ~Graph();
        void addNode(double x, double y, int id);
        void addEdge(int sid, int eid, int id, bool oneway);
        vector<Node> getlistNodes();
        vector<Edge> getlistEdges();
        void printlistNodesData();
        void printlistEdgesData();

        Node findNode(int nID);
        Edge findEdge(int eID);

};

/********** Functions **********/

//Load map - set up graph


// Close map - clean up data structure


#endif