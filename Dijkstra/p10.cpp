// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9b
// Date: 11/08/23

#include <iostream>   // gets cin, cout, cerr
#include "p8.h"
#include "p10.h"

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
            eCount++;
            rc = true;
        }
    }
    return(rc);
}


//******************************************************************************
// Andrew Chapuis

// Deletes an edge from the graph matrix
bool Graph::deleteEdge(int uLabel, int vLabel) {
    bool rc = false;
    // If the edge exists, then it will be deleted
    if (isEdge(uLabel, vLabel)) {
        a[labelToVid(uLabel)][labelToVid(vLabel)] = 0;
        eCount--;
        rc = true;
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
    if (isV(label)) {
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
    if (isV(label)) {
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
            cout << " " << a[r][c];
        }
        cout << endl;
    }

    cout << "Degree table (in, out)\n";
    
    // Prints the degree of each vertex
    for (r = 0; r < vCount; r++) {
        labels->readAt(r, key);
        cout << "  Node(" << r << "," << key << "):";
        cout << " " << inDegree(key) << ", " << outDegree(key) << endl;
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
        q->clear();
        q->enq(root);
        int count = 0;
	
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
            cout << "       Item " << count << " is (" << dq << "," << 
                        vidToLabel(dq) << ")" << endl;
            if (dq == -1) {
                break;
            }
	        // This will enqueue and print every neighbor of a root
            for (int i = 0; i < vCount; i++) {
                if (!sally[i] && isEdge(vidToLabel(dq), vidToLabel(i))) {
                    q->enq(i);
                    sally[i] = true;
                    count++;
                }
            }
        }
	// Delete Sally after done
        delete[] sally;
    }
}

// //******************************************************************************
// // Andrew Chapuis

// // Returns true if a path can be found from ulabel to vlabel
// bool Graph::isPath(int ulabel, int vlabel) const {
//     bool rc = false;
//     int root = labelToVid(ulabel);
//     if (root != -1) {
//         q->enq(root);
	
// 	// Create Sally to keep track of whether a vertex has been visited
//         bool *sally = new bool[vCount];
//         for (int i = 0; i < vCount; i++) {
//             sally[i] = false;
//         }
//         sally[root] = true;
	
// 	// Starting at root, each neighbor will be searched and if vLabel is 
// 	// found, the function will return true
//         while (true) {
//             int dq = 0;
//             q->deq(dq);
//             if (dq == -1) {
//                 break;
//             } else if (dq == labelToVid(vlabel)) {
// 		rc = true;
// 		break;
// 	    }
//             for (int i = 0; i < vCount; i++) {
//                 if (!sally[i] && isEdge(vidToLabel(dq), vidToLabel(i))) {
//                     q->enq(i);
//                     sally[i] = true;
//                 }
//             }
//         }
// 	// Delete Sally once the function is finished
//         delete[] sally;
//     }
//     return(rc);
// }

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
// Aidan Wright

bool Graph::isPath(int ulabel, int vlabel) const {
    bool rc = false;
    if(isV(ulabel) && isV(vlabel)) {
        int uV = labelToVid(ulabel);
        int vV = labelToVid(vlabel);
        bool *sally = new bool[vCount];
        for (int i = 0; i < vCount; i++) {
            sally[i] = false;
        }
        q->clear();
        q->enq(uV); //mark uV as visited in bfprint but not is path
        int wV;
        rc = true;
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
        rc = sally[vV];
        delete [] sally;
    }
    return rc;
}
