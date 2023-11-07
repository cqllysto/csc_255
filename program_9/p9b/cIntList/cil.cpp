// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9b
// Date: 

#include <iostream>   // gets cin, cout, cerr
#include "cil.h"


//******************************************************************************
// Andrew Chapuis

// cIntList constructor, with default capacity set to 100
cIntList::cIntList(int capacity) {
    listCapacity = capacity;
    listCount = first = last = 0;
    a = new int[listCapacity];
}

//******************************************************************************
// Andrew Chapuis

// cIntList destructor
cIntList::~cIntList() {
    if (a) {
	delete [] a;
	a = NULL;
    }
}

//******************************************************************************
// Aidan Wright

// increments the given value by one and wraps it to zero
// if it equals the list capacity
void cIntList::incVal(int &value) {
    value = (value + 1) % listCapacity;
}

//******************************************************************************
// Aidan Wright

// decrements the given value by one and wraps it
// to list capacity - 1 if it goes below zero
void cIntList::decVal(int &value) {
    value = (value - 1 + listCapacity) % listCapacity;
}

//******************************************************************************
// Andrew Chapuis

// private helper function that will convert a virtual index passed by 
// into the physical index that it represents in our circular array
int cIntList::vToP(int value) const {
    return((value + first) % listCapacity);
}

//******************************************************************************
// Andrew Chapuis

// inserts a text at the index before the beginning of the list
// and changes the first index to point to it
bool cIntList::insert(int text) {
    bool rc = false;
    // Verify the list is not full
    if (listCount < listCapacity) {
	// if the list has at least one entry, then decrease first one index,
	// otherwise first and last will still equal the same index.
	// Last is not affected as the value is being inserted before the list
	// and there is no shifting happening.
	if (listCount) {
	    decVal(first);
	}
	// inputs the given text into the new first location 
	a[first] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// adds the given int to the end of the list
bool cIntList::add(int text) {
    bool rc = false;
    // Verify the list is not full
    if (listCount < listCapacity) {
	// if the list has at least one entry, then increase first one index,
	// otherwise first and last will still equal the same index
	// First is not affected as the value is being added after the list
	// and there is no shifting happening.
	if (listCount) {
	    incVal(last);
	}
	// insert the given text into the location of the new last index
	a[last] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// insert a given text at a given index in the list
bool cIntList::insertAt(int index, int text) {
    bool rc = false;
    // check to make sure the index is within bounds and the list is not full
    if ((index <= listCount) && (listCount < listCapacity) && (index >=0)) {
	// move everything after the given index back one index 
	// to make room for the new text
	for (int i = listCount; i > index; i--) {
	    // make sure that the index is being translated to the physical
	    // location
	    a[vToP(i)] = a[vToP(i - 1)]; 
	}
	// if the list count is empty, then last does not need to be updated,
	// however if the list has items, then last does need to be updated
	if (listCount != 0) {
	    last++;
	}
	// set the text to the physical location of the given index
	a[vToP(index)] = text;
	listCount++;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// delete the contents of the given index and return the deleted text
bool cIntList::deleteAt(int index, int &text) {
    bool rc = false;
    // if the index is within the correct bounds
    if ((index >= 0) && (index < listCount)) {
	// set text to the int that needs to be returned
	text = a[vToP(index)];
	// beginning at the index to be deleted, shift everything behind it
	// up one index, taking care to translate the virtual to physical 
	for(int i = index; i < listCount - 1; i++) {
	    a[vToP(i)] = a[vToP(i + 1)];
	}
	// if the list only has one thing, then last can stay where it is
	// otherwise, last has to move down one index
	if (listCount != 1) {
	    last--;
	}
	listCount--;
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// read the int at the given index
bool cIntList::readAt(int index, int &text) {
    bool rc = false;
    // if the index is within the bounds of our list
    if ((index >= 0) && (index < listCount)) {
	// the text to be returned is set to contents of the given location
	// taking care to translate the virtual index to the physical one
	text = a[vToP(index)];
	rc = true;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// deletes the first thing on the list and moves the first index up one index
bool cIntList::deleteFirst(int &text) {
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
bool cIntList::deleteLast(int &text) {
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
void cIntList::clear() {
    listCount = 0;
    // first and last need to be set equal to each other to allow for accurate
    // readdition to the list after clearing
    first = last;
}

//******************************************************************************
// Aidan Wright

// how many things are in the list
int cIntList::count() const {
    return(listCount);
}

//******************************************************************************
// Andrew Chapuis

// Checks the array for the given text and returns the index where the text is
// found
int cIntList::getIndex(int text) const {
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
void cIntList::printIt() const {
    // This integer will be incremented to print the list
    int ind = first;
    for (int i = 0; i < listCount; i++ ) {
	// i is used to keep track of the virtual index while ind is what is 
	// being used for the physical index of the array
	std::cout << "At pos " << i << " there is " << a[ind] << "\n";
	// makes sure the ind wraps around the dateline
	ind = (ind + 1) % listCapacity;
    }
}

