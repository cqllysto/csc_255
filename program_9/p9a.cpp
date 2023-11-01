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

int min(int x, int y) {
    int rc = x;
    if (y < x) {
	rc = y;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

int max(int x, int y) {
    int rc = x;
    if (y > x) {
	rc = y;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

Graph::Graph(int n, bool directed) {
    int** a = new int*[n];
    // int *a[n];
    int *b = new int[n * n];
    for (int i = 0; i < n; i++) {
	    a[i] = &(b[i * n]);
    }
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
    int rc = -1;
    int key = 0;
    for (int i = 0; i < vCount; i++) {
        labels->readAt(i, key);
        if (key == label) {
            rc = i;
            break;
        }
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool Graph::createV(int label) {
    bool rc = false;
    if ((vCount < n) && !isV(label)) {
        rc = true;
        labels[vCount] = label;
        vCount++;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// Use labels->add(label) to add a new vertex to the Graph
// To Use labels->getIndex(label) to get the vid number of the vertex with that label; it will return -1 if the
// labeled vertex is not in the graph.
// To Use labels->readAt(vid, label) to get the label of the given vid.


bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    if (weight > 0) {
        if ((isV(uLabel) && isV(vLabel))) {
            if (a[labelToVid(uLabel)][labelToVid(vLabel)] == 0) {
                a[labelToVid(uLabel)][labelToVid(vLabel)] = weight;
                eCount++;
            }
        } else if (isV(uLabel) && vCount < n) {
            createV(vLabel);
            addEdge(uLabel, vLabel, weight);
        } else if (isV(vLabel) && vCount < n) {
            createV(uLabel);
            addEdge(uLabel, vLabel, weight);
        }
        rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright
void Graph::clear(){
    vCount = eCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

//******************************************************************************
// Aidan Wright
bool Graph::isEdge(int uLabel, int vLabel) const {
    bool rc = -1;
    int uIndex = labelToVid(uLabel);
    int vIndex = labelToVid(vLabel);
    if (a[uIndex][vIndex]) {
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Aidan Wright
bool Graph::isV(int label) const {
    bool rc = -1;
    int index = labelToVid(label);
    if (a[index]) {
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Aidan Wright
int Graph::inDegree(int label) const {
    int rc = 0;
    int index = labelToVid(label);
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
    int index = labelToVid(label);
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[index][j]) {
                rc += 1;
            }
        }
    }
    return rc;
}

//******************************************************************************
// Aidan Wright
int Graph::sizeV() const {
    int rc = n*n;
    return rc;
}

//******************************************************************************
// Aidan Wright
int Graph::sizeUsedV() const {
    int rc = vCount;
    return rc;
}

//******************************************************************************
// Aidan Wright
int Graph::sizeE() const {
    int rc = eCount;
    return rc;
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