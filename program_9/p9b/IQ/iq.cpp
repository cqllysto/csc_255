// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9b
// Date: 

#include <iostream>   // gets cin, cout, cerr
#include "iq.h"
#include "../cIntList/cil.h"

//******************************************************************************
// Andrew Chapuis
iQ::iQ(int n) {
    j = new cIntList(n);
};


//******************************************************************************
// Andrew Chapuis
iQ::~iQ() {
    if(j) {
        delete [] j;
        j = NULL;
    }
};


//******************************************************************************
// Andrew Chapuis
bool iQ::enq(int v) {
    return(j->add(v));
};


//******************************************************************************
// Andrew Chapuis
bool iQ::deq(int &v) {
    bool rc = false;
    if (j) {
        int a = j->count();
        v = j->getIndex(a);
        j->deleteLast(a);
    }    
    return(rc);
}; 


//******************************************************************************
// Andrew Chapuis 
void iQ::clear() {
    j->clear();
};


//******************************************************************************
// Andrew Chapuis
int iQ::count() const {
    return(j->count());
};


//******************************************************************************
// Andrew Chapuis 
void iQ::printIt() const {};








