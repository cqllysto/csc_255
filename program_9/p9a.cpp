// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9
// Date: 11/1/23

#include <iostream>   // gets cin, cout, cerr
#include "p8.h"
#include "p9a.h"

using namespace std;

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
// Andrew Chapuis

// Returns the maximum between two numbers
int max(int x, int y) {
    int rc = x;
    if (y > x) {
	rc = y;
    }
    return(rc);
}

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
    
    // Create an array to keep track of the labels of the vertices
    labels = new intList(n);
    this->n = n;
    vCount = eCount = 0;
    this->directed = directed;
}

//******************************************************************************
// Andrew Chapuis

Graph::~Graph() {
    if (a) {
        delete [] a;
        a = NULL;
    }
}

//******************************************************************************
// Andrew Chapuis

int Graph::labelToVid( int label) const {
    return(labels->getIndex(label));
}

//******************************************************************************
// Andrew Chapuis

// Creates a vertex
bool Graph::createV(int label) {
    bool rc = isV(label);
    if ((vCount < n) && !rc) {
        rc = true;
        labels->add(label);
        vCount++;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    if ((weight > 0) && !isEdge(uLabel, vLabel)) {
        if (!isV(uLabel) && !isV(vLabel) && (vCount < (n - 1))) {
	    createV(uLabel);
	    createV(vLabel);
	    a[labelToVid(uLabel)][labelToVid(vLabel)] = weight;
	    eCount++;
	    rc = true;
        } else if (isV(uLabel) && !isV(vLabel) && (vCount < n)) {
            createV(vLabel);
	    a[labelToVid(uLabel)][labelToVid(vLabel)] = weight;
	    eCount++;
	    rc = true;
        } else if (!isV(uLabel) && isV(vLabel) && (vCount < n)) {
            createV(uLabel);
	    a[labelToVid(uLabel)][labelToVid(vLabel)] = weight;
	    eCount++;
	    rc = true;
	} else if (isV(uLabel) && isV(vLabel)) {
	    a[labelToVid(uLabel)][labelToVid(vLabel)] = weight;
	    eCount++;
	    rc = true;
	}
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright
void Graph::clear(){
    vCount = eCount = 0;
    for (int i = 0; i < n; i++) {
        labels->clear();
	for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

//******************************************************************************
// Aidan Wright

bool Graph::isEdge(int uLabel, int vLabel) const {
    bool rc = false;
    if (isV(uLabel) && isV(vLabel)) {
	int uIndex = labelToVid(uLabel);
	int vIndex = labelToVid(vLabel);
	if (a[uIndex][vIndex]) {
	    rc = true;
	}
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

bool Graph::isV(int label) const {
    bool rc = false;
    int index = labelToVid(label);
    if (index != -1) {
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

int Graph::inDegree(int label) const {
    int rc = 0;
    if (isV(label)) {
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
    int rc = 0;
    if (isV(label)) {
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
int Graph::sizeV() const {
    return(n * n);
}

//******************************************************************************
// Aidan Wright
int Graph::sizeUsedV() const {
    return(vCount) ;
}

//******************************************************************************
// Andrew Chapuis

int Graph::sizeE() const {
    return(eCount);
}

//******************************************************************************
// Aidan Wright

void Graph::printIt() const {
    int r, c;
    int key = 0;
    cout << "Graph info:\n";
    cout << "  Graph size = " << n << endl;
    cout << "  vCount = " << vCount << endl;
    cout << "  eCount = " << eCount << endl;
    cout << "\nGraph contents:\n";
    for (r = 0; r < vCount; r++) {
        labels->readAt(r, key);
	    cout << "  Node(" << r << "," << key << "):";
	for (c = 0; c < vCount; c++) {
	    cout << " " << a[r][c];
	}
	cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (r = 0; r < vCount; r++) {
        labels->readAt(r, key);
        cout << "  Node(" << r << "," << key << "):";
        cout << " " << inDegree(key) << ", " << outDegree(key) << endl;
    }
}
