// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9b
// Date: 

#ifndef __IQ_H
#define __IQ_H

#include "../cIntList/cil.h"

class iQ {
    private:
        cIntList *theList;
    public:
        // These are the constructor and destructor of the class
        iQ(int n = 100);
        ~iQ();
        bool enq(int v);
        bool deq(int &v); 
        void clear(); // removes all items in the iQ, resulting in the iQ being empty
        int count() const; // returns the number of items in the iQ
        void printiIt() const; // prints the contents of the iQ
};

#endif