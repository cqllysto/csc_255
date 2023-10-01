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
    int ind = 0;
    if (index > 0) {
        int ind = (index - 1) / 2;
    }
    return ind;
}

//******************************************************************************
// Aidan Wright

int iPQ::left(int index) const {
    int ind = index * 2 + 1;
    return ind;
}

//******************************************************************************
// Aidan Wright

int iPQ::right(int index) const {
    int ind = (index + 1) * 2;
    return ind;
}

//******************************************************************************
// Aidan Wright

void iPQ::printIt(int ind, int count) const {
    // ind = 0, count = 6
    int ind2;

    int level = log2(ind + 1);
    cout << "level[" << level << "]->";

    for (int i = ind; count > 0 && i < qCount; count--) {
        cout << values[i] << " ";
        i++;
        ind2 = i;
    }
    
    cout << endl;

    if (level < log2(qCount) - 1) {
        printIt(ind2, pow(2, (level + 1)));
    }
} 

//******************************************************************************
// Aidan Wright

void iPQ::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************
// Aidan Wright

void iPQ::bubbleUp(int index) {
    int per = parent(index);
    if ((values[per] < values[index]) && (per != index)) {
        swap(&values[index], &values[per]);
        bubbleUp(per);
    }
}

//******************************************************************************
// Aidan Wright

void iPQ::heapify(int index) {
    int l = left(index);
    int r = right(index);
    int bigChild = 0;
    if ((l < qCount && values[l]) > (values[index])) {
        bigChild = l;
    } else if ((r < qCount) && (values[r] > values[index])) {
        bigChild = r;
    }
    
    while (values[bigChild] > values[index]) {
        swap(&values[bigChild], &values[index]);
        index = bigChild;
        bigChild = max(left(index), right(index));
    }
}

//******************************************************************************
// Aidan Wright

bool iPQ::enq(int v) {
    bool rc = false;
    if (qCount < qCapacity) {
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
        rc = true;
        qCount--;
        v = values[0];
        values[0] = values[qCount];
        heapify(0);
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

void iPQ::printIt() const {
    printIt(0, 1);
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



