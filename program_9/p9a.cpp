// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9
// Date: 11/1/23

#include <iostream>   // gets cin, cout, cerr
#include "p8.h"
#include "p9.h"

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
    a = new int *[n];
    int *b = new int[n * n];
    for (i = 0; i < n; i++) {
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
	a = NULL
    }
}

//******************************************************************************
// Andrew Chapuis

int Graph::labelToVid( int label) const {
    int rc = -1;
    for (int i = 0; i < vCount; i++) {
	if (labels[i] == label) {
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

bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    if (weight > 0) {
	if ((isV(uLabel) && isV(vLabel)) {
	    if (a[labelToVid(uLabel)][labelToVid(vLabel)] == 0) {
		a[labelToVid(uLabel)][labelToVid(vLabel)] = weight
		eCount++;
	    }
	} else if (isV(ulabel) && vCount < n) {
	    createV(vLabel);
	    addEdge(uLabel, vLabel, weight);
	} else if (
    }
    return(rc);
}
