// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 11
// Date: 11/27/23

#include <iomanip>
#include <iostream>   // gets cin, cout, cerr
#include "p8.h"
#include "p11.h"

using namespace std;

//******************************************************************************
// Andrew Chapuis

// Constructor for the Graph class
Graph::Graph(int n, bool directed) {
    // Set a as a new pointer to an array of pointers
    a = new int *[n];
    // Make b an array at the correct length
    int *b = new int[n * n];
    // Sets the different indices of a as pointers to different sections of b
    for (int i = 0; i < n; i++) {
        a[i] = &(b[i * n]);
        // Initialize every value as 0
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    
    q = new iQ(n);
    // Create an array to keep track of the labels of the vertices
    labels = new intList(n);
    this->n = n;
    // Initialize vCount and eCount to zero
    vCount = eCount = 0;
    this->directed = directed;
    lambda = new int[n];
    set = new int[n];
}

//******************************************************************************
// Andrew Chapuis

// Destructor of the Graph
Graph::~Graph() {
    // delete the both a and labels
    for (int i = 0; i < n; i++) {
        //delete a[i];
    }
    if (a) {
        delete [] a;
        a = NULL;
    }
    if (q) {
        delete q;
        q = NULL;
    }
    if (labels) {
        delete labels;
        labels = NULL;
    }
}

//******************************************************************************
// Aidan Wright

// Finds the virtual ID of a given label
int Graph::labelToVid( int label) const {
    return(labels->getIndex(label));
}

//******************************************************************************
// Andrew Chapuis

// Creates a vertex
bool Graph::createV(int label) {
    bool rc = false;
    // If there is space and it is not already a vertex, a new vertex will be 
    // created
    if ((vCount < n) && !isV(label)) {
        rc = true;
        // Add the label to the labels array
        labels->add(label);
        vCount++;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// Adds an edge, and the vertices if they do not exist, to the graph 
// unless one of the conditions cannot be met. 
bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    // An edge will not be added if there is already an edge there or the weight
    // is non-positive
    if ((weight > 0) && !isEdge(uLabel, vLabel)) {
        // An edge will not be added if uLabel and vLabel do not exist and there
        // is not enough room to be created
        int count = 0;
        if (!isV(uLabel)) {
            count ++;
        }
        if (!isV(vLabel)) {
            count ++;
        }
        if (count <= n - vCount) {
            createV(uLabel);
            createV(vLabel);
            a[labelToVid(uLabel)][labelToVid(vLabel)] = weight;
            // If the graph is undirected, whenever one edge is created, it's 
            // mirror edge will also be created
            if (!directed) {
                a[labelToVid(vLabel)][labelToVid(uLabel)] = weight;
            }
            eCount++;
            rc = true;
        }
    }
    return(rc);
}


//******************************************************************************
// Andrew Chapuis

// Deletes an edge from the graph matrix
bool Graph::deleteEdge(int uLabel, int vLabel, int &weight) {
    bool rc = false;
    // If the edge exists, then it will be deleted
    if (isEdge(uLabel, vLabel)) {
        weight = a[labelToVid(uLabel)][labelToVid(vLabel)];
        a[labelToVid(uLabel)][labelToVid(vLabel)] = 0;
        // If the graph is undirected, whenever one edge is deleted, it's 
        // mirror edge will also be deleted
        if (!directed) {
            a[labelToVid(vLabel)][labelToVid(uLabel)] = weight;
        }
        eCount--;
        rc = true;
    } else {
        weight = -1;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// Clears the graph matrix
void Graph::clear() {
    // vCount and eCount are both set to zero, and then all the indices of the 
    // graph matrix and labels array are set to zero
    vCount = eCount = 0;
    labels->clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

//******************************************************************************
// Aidan Wright

// Checks to see if an edge already exists
bool Graph::isEdge(int uLabel, int vLabel) const {
    bool rc = false;
    // Find the index of the labels and if both of the vertices exist
    // and there is a non-zero number in the graph matrix, the function returns
    // true
    int uIndex = labelToVid(uLabel);
    int vIndex = labelToVid(vLabel);
    if ((uIndex != -1) && (vIndex != -1)) {
        if (a[uIndex][vIndex]) {
            rc = true;
        }
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

// Checks to see if a vertex already exists
bool Graph::isV(int label) const {
    bool rc = false;
    // Finds the index of a label, and if it exists, then the function returns
    // true
    int index = labelToVid(label);
    if (index != -1) {
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

// Returns the number of edges directed to a vertex
int Graph::inDegree(int label) const {
    int rc = -1;
    // If the node doesn't exist, the function will return -1, otherwise
    // it will calculate the inDegree of the vertex
    if ((directed) && (isV(label))) {      
        rc = 0;
        // The index of the label will stay constant as the matrix is searched
        int index = labelToVid(label);
        for (int i = 0; i < n; i++) {
            if (a[i][index]) {
                rc += 1;
            }
        }
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

int Graph::outDegree(int label) const {
    int rc = -1;
    // If the node doesn't exist, the function will return -1, otherwise
    // it will calculate the inDegree of the vertex
    if ((directed) && (isV(label))) {      
        rc = 0;
        // The index of the label will stay constant as the matrix is searched
        int index = labelToVid(label);
        for (int i = 0; i < n; i++) {
            if (a[index][i]) {
                rc += 1;
            }
        }
    }
    return rc;
}

//******************************************************************************
// Andrew Chapuis

// Returns the maximum number of vertices that the matrix can have
int Graph::sizeV() const {
    return(n);
}

//******************************************************************************
// Aidan Wright

// Returns the number of vertices currently in the graph
int Graph::sizeUsedV() const {
    return(vCount) ;
}

//******************************************************************************
// Andrew Chapuis

// Returns the number of edges in the graph
int Graph::sizeE() const {
    return(eCount);
}

//******************************************************************************
// Aidan Wright

// Prints the graph matrix
void Graph::printIt() const {
    int r, c;
    int key = 0;
    cout << "Graph info:\n";
    cout << "  Graph size = " << n << endl;
    cout << "  vCount = " << vCount << endl;
    cout << "  eCount = " << eCount << endl;
    cout << "\nGraph contents:\n";
    for (r = 0; r < vCount; r++) {
        // Prints the label associated with each index
        labels->readAt(r, key);
        cout << "  Node(" << r << "," << key << "):";
        // Prints each row of the graph matrix
        for (c = 0; c < vCount; c++) {
            cout << setw(3) << a[r][c];
        }
        cout << endl;
    }

    cout << "Degree table (normal, in, out)\n";
    
    // Prints the degree of each vertex
    for (r = 0; r < vCount; r++) {
        labels->readAt(r, key);
        cout << "  Node(" << r << "," << key << "):";
        cout << setw(6) << degree(key) << ", " << inDegree(key) << ", " 
            << outDegree(key) << endl;
    }
}

//******************************************************************************
// Andrew Chapuis

// Returns the minimum between two numbers
int min(int x, int y) {
    int rc = x;
    if (y < x) {
        rc = y;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// Returns the maximum between two numbers
int max(int x, int y) {
    int rc = x;
    if (y > x) {
        rc = y;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// Converts a virtual id to a label
int Graph::vidToLabel(int vid) const {
    int rc = -1;
    // Return the entry of labels at the virtual id
    labels->readAt(vid, rc);
    return rc;
} 

//******************************************************************************
// Aidan Wright

// Prints the graph through 
void Graph::bfPrint(int label) const {
    // Root is the beginning vertex which branches out from there
    int root = labelToVid(label);
    if (root != -1) {
        // Root is enqueued
        q->enq(root);
        int count = 0;
        cout << "       Item " << count << " is (" << root << 
        "," << vidToLabel(root) << ")" << endl;
        
        // Sally is an array that keeps track of whether a node has been visited
        bool *sally = new bool[vCount];
        for (int i = 0; i < vCount; i++) {
            sally[i] = false;
        }
        sally[root] = true;
        
        // Starting at root, each neighbor will be enqueued and marked as true
        // in Sally
        while (true) {
            int dq = 0;
            q->deq(dq);
            // When everything has been dequeued, the loop will break
            if (dq == -1) {
                break;
            }
            // This will enqueue and print every neighbor of a root
            for (int i = 0; i < vCount; i++) {
                if (!sally[i] && isEdge(vidToLabel(dq), vidToLabel(i))) {
                    q->enq(i);
                    sally[i] = true;
                    count++;
                    cout << "       Item " << count << " is (" << i << "," << 
                        vidToLabel(i) << ")" << endl;
                }
            }
        }
        // Delete Sally after done
        delete[] sally;
    }
}

//******************************************************************************
// Aidan Wright

// Returns true if a path can be found from ulabel to vlabel
bool Graph::isPath(int ulabel, int vlabel) const {
    bool rc = false;

    // if the vertices given exist, then try to find a path
    if(isV(ulabel) && isV(vlabel)) {
        int uV = labelToVid(ulabel);
        int vV = labelToVid(vlabel);
        // Create Sally to keep track of whether a vertex has been visited
        bool *sally = new bool[vCount];
        for (int i = 0; i < vCount; i++) {
            sally[i] = false;
        }
        q->clear();
        q->enq(uV); 
        int wV;
        // Starting at root, each neighbor will be searched and if vLabel is 
        // found, the function will return true
        while(q->deq(wV)) {
            for (int i = 0; i < vCount; i++) {
                if(!sally[i]){
                    if (isEdge(vidToLabel(wV),vidToLabel(i))) {
                        sally[i] = true;
                        q->enq(i);
                    }
                }
            }
        }
        // Delete Sally once the function is finished
        rc = sally[vV];
        delete [] sally;
    }
    return rc;
}

//******************************************************************************
// Andrew Chapuis

void Graph::printPaths() const {
    // Create variables to be used when labels is read
    int uNode;
    int vNode;
    // Go through every vertex and check whether there is a path
    for (int i = 0; i < vCount; i++) {
        labels->readAt(i, uNode);
        for (int j = 0; j < vCount; j++) {
            labels->readAt(j, vNode);
            cout << uNode << " does ";
            // If there is not a path, not will be added to the sentence
            if (!isPath(uNode, vNode)) {
                cout << "not ";
            }
            cout << "have a path to " << vNode << endl;
        }
    }
}

//******************************************************************************
// Andrew Chapuis

// Public method that will return true if both nodes exist or false if not
bool Graph::dijkstra(int sLabel, int dLabel, int &distance) {
    bool rc = false;
    // If the vertices do not exist, distance will be changed to -1
    distance = -1;
    if (isV(sLabel) && isV(dLabel)) {
        rc = true;
        // Call the private method to find the shortest paths from the starting
        // vertex
        dijkstra(labelToVid(sLabel));
        // Distance will be set to the lambda value of the destination vertex
        distance = lambda[labelToVid(dLabel)];
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

void Graph::dijkstra(int s) {
    // All of the set array will get initialized to Y
    for (int i = 0; i < vCount; i++) {
        set[i] = Y;
        lambda[i] = INFINITE;
    }
    // Set the starting vertex to X in set and 0 in lambda
    set[s] = X;
    lambda[s] = 0;
    // Create a variable that will follow which nodes get added to X
    int v = s;
    bool doit = true;
    while (doit) {
        // Change the current minimum to X
        set[v] = X;
        // Go through the lambda array and update their values with edges 
        // starting at v
        for (int i = 0; i < vCount; i++) {
            if ((set[i] == Y) && (isEdge(vidToLabel(v), vidToLabel(i)))) {
                // Lambda will be set to the minimum of the current lambda
                // or the lambda of the vertex just added and its weight edge
                lambda[i] = min(lambda[i], lambda[v] + a[v][i]);
            }
            }
        // If there are no more values in Y, do it will return false
        doit = minLambdaY(v);
    }
}

//******************************************************************************
// Andrew Chapuis

// Returns true if there are indices in Y and changes minV to the minimum value
bool Graph::minLambdaY(int &minV) {
    // 
    bool rc = false;
    minV = -1;
    // Go through set to find Y and compare the min index with each index to 
    // find the minimum value in Y
    for (int i = 0; i < vCount; i++) {
        // If the index is Y, it will change minV if it is equal to -1 
        // or it is smaller than the current minimum
        if ((set[i] == Y) && ((minV == -1) || (lambda[minV] > lambda[i]))) { 
            minV = i;
        }
    }
    if (minV != -1) {
        rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// Returns whether a directed graph is cyclic
bool Graph::isCyclicDirected() {
    bool rc = false;
    // At every vertex, search for a path back to itself and if one exists
    // the function will return true and break from the loop
    for (int i = 0; i < vCount; i++) {
        if(isPath(vidToLabel(i),vidToLabel(i))) {
            rc = true;
            break;
        }
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// Returns whether an undirected graph is cyclic
bool Graph::isCyclicUndirected() {
    bool rc = false;
    for (int i = 0; i < vCount; i++) {
        for (int j = 0; j < vCount; j++) {
            // Once an edge is found, the edge will be temporarily deleted so
            // a search for a different path back to the vertex exists
            if (isEdge(vidToLabel(i),vidToLabel(j))) {
                // w is a temporary variable to hold the weight of the edge
                int w = a[i][j];
                a[i][j] = 0;
                // If there is a path, the function will return true
                if (isPath(vidToLabel(i),vidToLabel(j))) {
                    rc = true;
                }
                a[i][j] = w;
            }
            // Break out of both loops once one cycle has been found
            if (rc) {
                break;
            }
        }
        if (rc) {
            break;
        }
    }
    return rc;
}

//******************************************************************************
// Andrew Chapuis

// Returns whether a graph is cyclic
bool Graph::isCyclic() {
    bool rc = false;
    // Will call the respective function for directed or undirected
    if (directed) {
        rc = isCyclicDirected();
    } else {
        rc = isCyclicUndirected();
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// Returns the degree of a vertex, or -1 if it doesn't exist or the graph is 
// undirected
int Graph::degree(int label) const {
    int rc = -1;
    // If the graph is undirected and the label exists
    if (!directed && isV(label)) {
        rc = 0;
        // The index of the label will stay constant as the matrix is searched
        int index = labelToVid(label);
        // Goes through each row counting the number of edges
        for (int i = 0; i < n; i++) {
            if (a[index][i]) {
                rc += 1;
            }
        }
    }
    return(rc);
}
