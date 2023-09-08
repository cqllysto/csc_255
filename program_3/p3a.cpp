//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 3
//Date: 09/11/23

#include <iostream>   // gets cin, cout, cerr
#include "p3.h"

using namespace std;

//******************************************************************************
// Andrew Chapuis

cStringList::cStringList(int capacity) {
    listCapacity = capacity;
    listCount = first = last = 0;
    a = new string[listCapacity];
}

//******************************************************************************
// Andrew Chapuis

cStringList::~cStringList() {
    if (a) {
	delete [] a;
	a = NULL;
    }
}

//******************************************************************************
// Andrew Chapuis

void cStringList::incVal(int &value) {
    value = (value + 1) % listCapacity;
}

//******************************************************************************
// Andrew Chapuis

void cStringList::decVal(int &value) {
    value = (value - 1 + listCapacity) % listCapacity;
}

//******************************************************************************
// Andrew Chapuis

bool cStringList::insert(string text) {
    bool rc = false;
    if (listCount < listCapacity) {
	if (listCount) {
	    decVal(first);
	}
	a[first] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool cStringList::add(string text) {
    bool rc = false;
    if (listCount < listCapacity) {
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

bool cStringList::insertAt(int index, string text) {
    bool rc = false;
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool cStringList::deleteAt(int index, string &text) {
    bool rc = false;
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool cStringList::readAt(int index, string &text) {
    bool rc = false;
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool cStringList::deleteFirst(string &text) {
    bool rc = false;
    if (listCount) {
	text = a[first];
	if (listCount != 1) {
	    incVal(first);
	}
	listCount--;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool cStringList::deleteLast(string &text) {
    bool rc = false;
    if (listCount) {
	text = a[last];
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

void cStringList::clear() {
    listCount = 0;
    first = last;
}

//******************************************************************************
// Andrew Chapuis

int cStringList::count() const {
    return(listCount);
}

//******************************************************************************
// Andrew Chapuis

int cStringList::getIndex(string text) const {
    int rc = -1;
    return (rc);
}

//******************************************************************************
// Andrew Chapuis

void cStringList::printIt() const {
    // This integer will be incremented to print the list
    int ind = first;
    for (int i = 0; i < listCount; i++ ) {
	cout << "At pos " << i << " there is " << a[ind] << "\n";
	ind = (ind + 1) % listCapacity;
    }
}
