//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 1
//Date: 08/28/23

#include <iostream>   // gets cin, cout, cerr
#include "p1.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Constructor: causes the array to be sized at "listCapacity" entries
// with a default size of 100
stringList::stringList(int listCapacity) {
    this->listCapacity = listCapacity;
    listSize = 0;
    a = new string[listCapacity];
}

//******************************************************************************
// Aidan Wright

// Destructor: makes sure that any dynamically allocated memory
// is deleted, in this case, the array "a"
stringList::~stringList() {
    if(a) {
        delete [] a;
    }
}

//******************************************************************************
// Andrew Chapuis

// Insert function: First shifts all entries right, then inserts the inputted 
// text into the beginning of the string
bool stringList::insert(string text) {
    bool rc = false;
    // shifts list entries to the right
    if (listSize < listCapacity) {
	for (int i = listSize; i > 0; i--) {  
	    a[i] = a[i - 1];
	}
    // sets the inserted text to the beginning of the string
    // and increments the listSize
	a[0] = text;
	listSize++;
	rc = true;
    }
    return(rc);
}

// ******************************************************************************
// Aidan Wright

// Add function: inserts the given text at the end of the list
bool stringList::add(string text){
    bool rc = false;
    if (listSize < listCapacity) {
	a[listSize] = text; 
	rc = true;
	listSize++;
    }
    return(rc);
}

// ******************************************************************************
// Andrew Chapuis

// insertAt function: inserts a given text at the given index of the string
// and shifts any following entries to the right
bool stringList::insertAt(int index, string text) {
    bool rc = false;
    // shifts all entries from the given index to the end of the list
    // to the right, and increments the listSize
    if ((index >=0) && (index <= listSize) && (listSize < listCapacity)) {
	for (int i = listSize; i > index; i--) {
	    a[i] = a[i - 1];
	}
	// sets the given text to the given index in the string
	a[index] = text;
	listSize++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// this is a p1b.cpp problem :)
bool stringList::deleteAt(int index, string &text) {
    bool rc = false;
    if ((index >= 0) && (index < listSize)) {
	text = a[index]; 
	for (int i = index; i < listSize; i++) {
	    a[i] = a[i + 1];
	}
	listSize--;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// empties the list
void stringList::clear() {
    listSize = 0;
}

//******************************************************************************
// Andrew Chapuis

// prints the whole list and the respective indexes
void stringList::printIt() const {
    for (int i = 0; i < listSize; i++) {
	    cout << "At pos " << i << " there is " << a[i] << "\n";
    }
}

//******************************************************************************
// Andrew Chapuis

// this is a p1b.cpp problem :)
int stringList::getIndex(string text) const {
    int rc = -1;
    for (int i = 0; i < listSize; i++) {
	if (a[i] == text) {
	    rc = i;
	    break;
	}
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// returns the entry in the list at the given index
bool stringList::readAt(int index, string &text) const {
    bool rc = false;
    if ((index >= 0) && (index < listSize)) {
        text = a[index];
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// returns the size of the list
int stringList::count() const {
   return(listSize);
}
