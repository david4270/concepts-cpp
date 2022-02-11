#ifndef _func_h
#define _func_h

#include <iostream>
#include <vector>

using namespace std;


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
    public:
        Node(double x, double y, int id); 
        ~Node();

        //input nodeID, output xCoord and yCoord pair
        
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
    int numNodes;

};

/********** Functions **********/

#endif