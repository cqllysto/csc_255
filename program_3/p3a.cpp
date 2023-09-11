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
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// p3b problem
bool cStringList::deleteAt(int index, string &text) {
    bool rc = false;
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// p3b problem
bool cStringList::readAt(int index, string &text) {
    bool rc = false;
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
	// if the list has more than one thing, increment first to index to 
	// the second thing on the list
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
    // if there is something in the list
    if (listCount) {
	text = a[last];
	// and the list is more than one thing
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

// p3b problem
int cStringList::getIndex(string text) const {
    int rc = -1;
    return (rc);
}

//******************************************************************************
// Andrew Chapuis

// prints the contents of the list
void cStringList::printIt() const {
    // This integer will be incremented to print the list
    int ind = first;
    for (int i = 0; i < listCount; i++ ) {
	cout << "At pos " << i << " there is " << a[ind] << "\n";
	// makes sure the ind wraps around the dateline
	ind = (ind + 1) % listCapacity;
    }
}
