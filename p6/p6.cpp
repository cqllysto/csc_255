// Name: Andrew Chapuis and Aidan Wright
// Course: CSC 255
// Program 6
// Date: 10/02/23

#include <iostream>  
#include <cmath>
#include "p6.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Priority Queue Constructor
iPQ::iPQ(int qCapacity) {
    qCount = 0;
    this->qCapacity = qCapacity;
    values = new int[qCapacity];
}

//******************************************************************************
// Aidan Wright

// Priority Queue Destructor
iPQ::~iPQ() {
    if(values) {
        delete [] values;
        values = NULL;
    }
}

//******************************************************************************
// Aidan Wright

int iPQ::parent(int index) const {
    int ind = NULL;
    if ((index >= 0) && (index < qCount))
        int ind = 0;
        if (index != 0) {
            int ind = (index - 1) / 2;
        }
    return ind;
}

//******************************************************************************
// Aidan Wright

int iPQ::left(int index) const {
    int ind = NULL;
    if ((index >= 0) && (index < qCount))
        ind = index * 2 + 1;
    return ind;
}

//******************************************************************************
// Aidan Wright

int iPQ::right(int index) const {
    int ind = NULL;
    if ((index >= 0) && (index < qCount))
        ind = (index + 1) * 2;
    return ind;
}

//******************************************************************************
// Aidan Wright

int iPQ::right(int index) const {
    int ind = NULL;
    if ((index >= 0) && (index < qCount))
        ind = (index + 1) * 2;
    return ind;
}

//******************************************************************************
// Aidan Wright

void iPQ::printIt(int ind, int count) const {
    // ind = 0, count = 6

    cout << "level[" << ind << "]->";

    int level;
    for (int i = ind; count > 0; count--, i++) {
        level = log(ind + 1);
        cout << "level[" << level << "]" << "->" << values[i];
    }
} 

//******************************************************************************
// Aidan Wright

void iPQ::swap(int *x, int *y) {

}

//******************************************************************************
// Aidan Wright

//CHECK BOUNDS
void iPQ::bubbleUp(int index) {
    int per = parent(index);
    while (values[per] < values[index] && index != 0) {
        swap(&values[per], &values[index]);
        index = per;
        per = parent(index);
    }
}

//******************************************************************************
// Aidan Wright

void iPQ::heapify(int index) {
    int bigChild = max(left(index), right(index));
    while (values[bigChild] > values[index] && index < qCount) {
        swap(&values[bigChild], &values[index]);
        index = bigChild;
        bigChild = max(left(index), right(index));
    }

}

//******************************************************************************
// Aidan Wright

bool iPQ::enq(int v) {
    bool rc = false;
    if (qCapacity < qCount) {
        values[qCount] = v;
        bubbleUp(qCount);
        qCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

bool iPQ::deq(int &v) {
    bool rc = false;
    if (qCount) {
        bool rc = true;
        for (int i = 0; i < qCount; i++) {
	        if (values[i] == v) {
                values[i] = values[qCount];
	            break;
	        }
        }
        qCount++;
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

void iPQ::printIt() const {

}

//******************************************************************************
// Aidan Wright

void iPQ::clear() {
    qCount = 0;
}

//******************************************************************************
// Aidan Wright

int iPQ::count() const {
    return qCount;
}



