#ifndef _func_h
#define _func_h

#include <iostream>
#include <vector>

using namespace std;


/********** Edge **********/

class Edge{
    private:
        Node* start;
        Node* end;
        int edgeID;

        
    public:
        Edge();
        Edge(Node * st, Node * ed, int id);
        ~Edge();

};

class Road: public Edge{
    private:
        string Type;
    public:
        Road();
        Road(Node * st, Node * ed, int id, string tp);
        ~Road();
};

class Rail: public Edge{
    private:
        string Type;
    public:
        Rail();
        Rail(Node * st, Node * ed, int id, string tp);
        ~Rail();
};

/********** Node **********/

class Node{
    private:
        double xCoord;
        double yCoord;
        int nodeID;
    public:
        Node();
        Node(double x, double y, int id); 
        ~Node();
};

class NodeFeature: public Node{
    private:
        string Type;
    public:
        NodeFeature();
        NodeFeature(double x, double y, int id, string tp);
        ~NodeFeature();
};


/********** Graph **********/

class Graph{
    int numNodes;

};

#endif