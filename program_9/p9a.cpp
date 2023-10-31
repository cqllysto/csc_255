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
    int *b = new int *[n];
    a = new int[n * n];
    for (i = 0; i < n; i++) {
	b[i] = &(a[i * n]);
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


