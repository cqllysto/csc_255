// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9
// Date: 11/1/23

#ifndef __P9B_H
#define __P9B_H

#include "../p9b/IQ/iq.h"
#include "../p8.h"

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
};

#endif
