// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 10
// Date: 11/08/23

#ifndef __P10_H
#define __P10_H

#include "iq.h"
#include "p8.h"

int min(int x, int y); // returns the minimum between x and y
int max(int x, int y); // returns the greater of x and y

class Graph {
    private:
        int **a; // The pointer for the array of the graph
        intList *labels; // A pointer to the list that will store the labels
        int n; // Memorializes the dimensions of the graph matrix
        int vCount; // Tracks the number of vertices in the graph
        int eCount; // Tracks the number of edges in the graph
        bool directed; // Keeps track of whether the graph is directed or not

        int labelToVid(int label) const; // Converts a label to a virtual id

        //p9b functions
        int vidToLabel(int vid) const; // Converts a virtual id to a label
        iQ *q; // pointer to an iQ ADT
        void visit(int x) const;
    public:
        Graph(int n = 100, bool directed = true); // Graph constructor
        ~Graph(); // Graph destructor
        
        bool createV(int label); // Creates a vertex with the inputed label
        bool addEdge(int uLabel, int vLabel, int weight); // adds an edge 
        bool deleteEdge(int uLabel, int vLabel); // deletes an edge
        void clear(); // clears the graph
        bool isEdge(int uLabel, int vLabel) const; // checks if an edge exists
        bool isV(int label) const; // checks if a vertex with label exists
        int inDegree(int label) const; // Returns the indegree of a node
        int outDegree(int label) const; // returns the outdegree of a node
        int sizeV() const; // returns the size of one edge of the graph matrix
        int sizeUsedV() const; // returns the number of current vertices
        int sizeE() const; // returns the number of edges in the graph
        void printIt() const; // Prints the graph

        //p9b functions
        void bfPrint(int label) const;
        bool isPath(int ulabel, int vlabel) const;
        void printPaths() const;

        //p10 
        bool dijkstra(int sLabel, int dLabel, int &distance);   // this will return true if sLabel and dLabel are both valid labels of
                                                                // real nodes. It will also return the distance from node sLabel
                                                                // to node dLabel. If either label is not a valid node, distance
                                                                // will be set to -1.
        int *lambda; // This will be an array of size n that will hold distances used in performing Dijkstra
        int *set; // This will be an array of size n to track which set, X or Y, that a given node is in.
        int const INFINITE = 1000000;
        int const X = 0; // Used with “set”, this will mark a node in set X
        int const Y = 1; // Used with “set”, this will mark a node in set Y
        void dijkstra(int s);   // will populate lambda with the distances from node 
                                // s to all other nodes; note that s is an index, not a label
        bool minLambdaY(int &minV); // If at least one node is in Y,
                                    // this will return true with minV set to the index of a node in Y
                                    // that has minimum value of all nodes in Y. If no node is in Y,
                                    // minLambdaY returns false with minV set to -1
};  

#endif
