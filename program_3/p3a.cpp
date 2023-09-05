//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 3
//Date: 09/11/23

#include <iostream>   // gets cin, cout, cerr
#include "p3.h"

using namespace std;

//******************************************************************************
//Andrew Chapuis

cStringList::cStringList(int capacity) {
    listCapacity = capacity;
    listCount = first = last = 0;
    a = new string[listCapacity];
}

