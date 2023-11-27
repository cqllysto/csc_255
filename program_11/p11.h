// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 11
// Date: 11/27/23

#ifndef __P11_H
#define __P11_H

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
        int *lambda; // Array that will hold the distances used
        int *set; // Array that follows whether a node is in set X or set Y
        int const INFINITE = 1000000;
        int const X = 0; // Used with "set"
        int const Y = 1; // Used with "set" 

        int labelToVid(int label) const; // Converts a label to a virtual id

        int vidToLabel(int vid) const; // Converts a virtual id to a label
        iQ *q; // pointer to an iQ ADT
        
        void dijkstra(int s); // Will populate lambda with the distances
        bool minLambdaY(int &minV); // Finds the minimum value in Y

        // Functions that will check whether an undirected or directed graph
        // is cyclic
        bool isCyclicUndirected();
        bool isCyclicDirected();


    public:
        Graph(int n = 100, bool directed = true); // Graph constructor
        ~Graph(); // Graph destructor
        
        bool createV(int label); // Creates a vertex with the inputed label
        bool addEdge(int uLabel, int vLabel, int weight); // adds an edge 
        bool deleteEdge(int uLabel, int vLabel, int &weight); // deletes an edge
        void clear(); // clears the graph
        bool isEdge(int uLabel, int vLabel) const; // checks if an edge exists
        bool isV(int label) const; // checks if a vertex with label exists
        int inDegree(int label) const; // Returns the indegree of a node
        int outDegree(int label) const; // returns the outdegree of a node
        int sizeV() const; // returns the size of one edge of the graph matrix
        int sizeUsedV() const; // returns the number of current vertices
        int sizeE() const; // returns the number of edges in the graph
        void printIt() const; // Prints the graph

        // Prints each item found in a breadth-first search
        void bfPrint(int label) const;
        // Returns true if a path can be found from a node to a node
        bool isPath(int ulabel, int vlabel) const;
        // Prints whether there is a path from each node to each node
        void printPaths() const; 
        
        // Returns true if both nodes exist and changes distance
        bool dijkstra(int sLabel, int dLabel, int &distance);

        // Returns the degree for an undirected graph
        int degree(int label) const;
        // Calls the private function for either a directed or undirected graph
        bool isCyclic();
        
};

#endif
