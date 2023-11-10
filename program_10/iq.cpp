// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9b
// Date: 11/08/23

#include <iostream>   // gets cin, cout, cerr
#include "iq.h"
#include "cil.h"

//******************************************************************************
// Andrew Chapuis
iQ::iQ(int n) {
    j = new cIntList(n);
};


//******************************************************************************
// Aidan Wright
iQ::~iQ() {
    if(j) {
        delete j;
    }
};


//******************************************************************************
// Aidan Wright
bool iQ::enq(int v) {
    return(j->add(v));
};


//******************************************************************************
// Andrew Chapuis
bool iQ::deq(int &v) {
    bool rc = false;
    v = -1;
    if (j->count()) { // fix this
        j->deleteFirst(v);
        rc = true;
    }    
    return(rc);
}; 


//******************************************************************************
// Aidan Wright
void iQ::clear() {
    j->clear();
};


//******************************************************************************
// Andrew Chapuis
int iQ::count() const {
    return(j->count());
};


//******************************************************************************
// Aidan Wright
void iQ::printIt() const {
    j->printIt();
};