//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 3
//Date: 09/11/23

#include <iostream>   // gets cin, cout, cerr
#include "p3.h"

using namespace std;

//******************************************************************************
// Andrew Chapuis

// cStringList constructor, with default capacity set to 100
cStringList::cStringList(int capacity) {
    listCapacity = capacity;
    listCount = first = last = 0;
    a = new string[listCapacity];
}

//******************************************************************************
// Andrew Chapuis

// cStringList destructor
cStringList::~cStringList() {
    if (a) {
	delete [] a;
	a = NULL;
    }
}

//******************************************************************************
// Aidan Wright

// increments the given value by one and wraps it to zero
// if it exceeds the list capacity
void cStringList::incVal(int &value) {
    value = (value + 1) % listCapacity;
}

//******************************************************************************
// Aidan Wright

// decrements the given value by one and wraps it
// to list capacity - 1 if it goes below zero
void cStringList::decVal(int &value) {
    value = (value - 1 + listCapacity) % listCapacity;
}

//******************************************************************************
// Andrew Chapuis

// private helper function that will convert a virtual index passed by 
// into the physical index that it represents in our circular array
int cStringList::vToP(int value) const {
    return((value + first) % listCapacity);
}

//******************************************************************************
// Andrew Chapuis

// inserts a text at the index before the beginning of the list
// and changes the first index to point to it
bool cStringList::insert(string text) {
    bool rc = false;
    // if the list is not full
    if (listCount < listCapacity) {
	// if the list is not empty
	if (listCount) {
	    // move first back one index
	    decVal(first);
	}
	a[first] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// adds the given string to the end of the list
bool cStringList::add(string text) {
    bool rc = false;
    // if the list is not full
    if (listCount < listCapacity) {
	// if the list is not empty
	if (listCount) {
	    incVal(last);
	}
	a[last] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// p3b problem
bool cStringList::insertAt(int index, string text) {
    bool rc = false;
    if ((index <= listCount) && (listCount < listCapacity) && (index >=0)) {
	for (int i = listCount; i > index; i--) {
	    a[vToP(i)] = a[vToP(i - 1)]; 
	}
	a[vToP(index)] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// p3b problem
bool cStringList::deleteAt(int index, string &text) {
    bool rc = false;
    if ((index >= 0) && (index < listCount)) {
	text = a[vToP(index)];
	for(int i = index; i < listCount; i++) {
	    a[vToP(i)] = a[vToP(i + 1)];
	}
	listCount--;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// p3b problem
bool cStringList::readAt(int index, string &text) {
    bool rc = false;
    if ((index >= 0) && (index < listCount)) {
	text = a[vToP(index)];
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// deletes the first thing on the list and moves the first index up one index
bool cStringList::deleteFirst(string &text) {
    bool rc = false;
    // if the list is not empty
    if (listCount) {
	text = a[first];
	// If there is only one item on the list, first and last are equal and 
	// so last does not need to be adjusted, only listCount
	if (listCount != 1) {
	    incVal(first);
	}
	listCount--;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// deletes the last thing on the list
bool cStringList::deleteLast(string &text) {
    bool rc = false;
    // Makes sure that the list is not empty
    if (listCount) {
	text = a[last];
	// If there is only one item on the list, first and last are equal and 
	// so last does not need to be adjusted, only listCount
	if (listCount != 1) {
	    decVal(last);
	}
	listCount--;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// empty the list
void cStringList::clear() {
    listCount = 0;
    first = last;
}

//******************************************************************************
// Aidan Wright

// how many things are in the list
int cStringList::count() const {
    return(listCount);
}

//******************************************************************************
// Andrew Chapuis

// Checks the array for the given text and returns the index where the text is
// found
int cStringList::getIndex(string text) const {
    int rc = -1;
    // Each index is compared to the text and if there is an equality, it will
    // break and return the first index it was found in.
    for (int i = 0; i < listCount; i++) {
	if (a[vToP(i)] == text) {
	    rc = i;
	    break;
	}
    }
    return (rc);
}

//******************************************************************************
// Andrew Chapuis

// prints the contents of the list
void cStringList::printIt() const {
    // This integer will be incremented to print the list
    int ind = first;
    for (int i = 0; i < listCount; i++ ) {
	// i is used to keep track of the virtual index while ind is what is 
	// being used for the physical index of the array
	cout << "At pos " << i << " there is " << a[ind] << "\n";
	// makes sure the ind wraps around the dateline
	ind = (ind + 1) % listCapacity;
    }
}

