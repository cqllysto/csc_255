//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 1
//Date: 08/28/23

#include <iostream>   // gets cin, cout, cerr

#include "p1.h"

using namespace std;

//******************************************************************************
//Aidan Wright

// Constructor
stringList::stringList(int listCapacity) {
    this->listCapacity = listCapacity;
    listSize = 0;
    a = new string[listCapacity];
}

//******************************************************************************
//Aidan Wright

// Destructor
stringList::~stringList() {
    if(a) {
        delete [] a;
    }
}

//******************************************************************************
//Andrew Chapuis

bool stringList::insert(string text) {
    bool rc = false;
    if (listSize < listCapacity) {
	for (int i = listSize; i > 0; i--) {
	    a[i] = a[i - 1];
	}
	a[0] = text;
	listSize++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
//Aidan Wright

bool stringList::add(string text){
    bool rc = false;
    if (listSize < listCapacity) {
	a[listSize] = text; 
	rc = true;
	listSize++;
    }
	return(rc);
}

//******************************************************************************
//Andrew Chapuis

bool stringList::insertAt(int index, string text) {
    bool rc = false;
    if ((index >=0) && (index < listSize) && (listSize < listCapacity)) {
	for (int i = listSize; i > index; i--) {
	    a[i] = a[i - 1];
	}
	a[index] = text;
	listSize++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
//Andrew Chapuis

bool stringList::deleteAt(int index, string &text) {
    return(false);
}

//******************************************************************************
//Andrew Chapuis

void stringList::clear() {
    listSize = 0;
}

//******************************************************************************
//Andrew Chapuis

void stringList::printIt() const {
    for (int i = 0; i < listSize; i++) {
	cout << a[i] << "\n";
    }
}

//******************************************************************************
//Andrew Chapuis

int stringList::getIndex(string text) const {
    return(-1);
}

//******************************************************************************
//Aidan Wright

bool stringList::readAt(int index, string &text) const {
    bool rc = false;
    if ((index >= 0) && (index < listSize)) {
        text = a[index];
	rc = true;
    }
    return(rc);
}

//******************************************************************************
//Aidan Wright

int stringList::count() const {
   return(listSize);
}
