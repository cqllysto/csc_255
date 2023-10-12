//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 7
//Date: 10/17/23

#include <iostream>   // gets cin, cout, cerr
#include "p7.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Constructor: causes the array to be sized at "listCapacity" entries
// with a default size of 100
intList::intList(int listCapacity) {
    this->listCapacity = listCapacity;
    listSize = 0;
    a = new int[listCapacity];
}

//******************************************************************************
// Aidan Wright

// Destructor: makes sure that any dynamically allocated memory
// is deleted, in this case, the array "a"
intList::~intList() {
    if(a) {
        delete [] a;
    }
}

//******************************************************************************
// Andrew Chapuis

// Insert function: First shifts all entries right, then inserts the inputted 
// key into the beginning of the int
bool intList::insert(int key) {
    bool rc = false;
    // shifts list entries to the right
    if (listSize < listCapacity) {
        for (int i = listSize; i > 0; i--) {  
            a[i] = a[i - 1];
        }
        // sets the inserted key to the beginning of the int
        // and increments the listSize
        a[0] = key;
        listSize++;
        rc = true;
    }
    return(rc);
}

// ******************************************************************************
// Aidan Wright

// Add function: inserts the given key at the end of the list
bool intList::add(int key){
    bool rc = false;
    if (listSize < listCapacity) {
        a[listSize] = key; 
        rc = true;
        listSize++;
    }
    return(rc);
}

// ******************************************************************************
// Andrew Chapuis

// insertAt function: inserts a given key at the given index of the int
// and shifts any following entries to the right
bool intList::insertAt(int index, int key) {
    bool rc = false;
    // shifts all entries from the given index to the end of the list
    // to the right, and increments the listSize
    if ((index >=0) && (index <= listSize) && (listSize < listCapacity)) {
        for (int i = listSize; i > index; i--) {
            a[i] = a[i - 1];
        }
        // sets the given key to the given index in the int
        a[index] = key;
        listSize++;
        rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// this is a p1b.cpp problem :)
bool intList::deleteAt(int index, int &key) {
    bool rc = false;
    if ((index >= 0) && (index < listSize)) {
        key = a[index]; 
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
void intList::clear() {
    listSize = 0;
}

//******************************************************************************
// Andrew Chapuis


int intList::getIndex(int key) const {
    int rc = -1;
    for (int i = 0; i < listSize; i++) {
        if (a[i] == key) {
            rc = i;
            break;
        }
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// returns the entry in the list at the given index
bool intList::readAt(int index, int &key) const {
    bool rc = false;
    if ((index >= 0) && (index < listSize)) {
        key = a[index];
	    rc = true;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// returns the size of the list
int intList::count() const {
   return(listSize);
}

//******************************************************************************
// Aidan Wright


void intList::bubbleSort() {
    for (int i = 0; i < listSize; i++) {
        for (int j = 0; j < listSize; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


//******************************************************************************
// Aidan Wright

// these probably wont work yet lol
void intList::selectionSort() {
    int min;
    for (int i = 0; i < listSize; i++) {
        min = i;
        for (int j = i + 1; j < listSize; j++) {
            if (a[j] < a[min]){
                min = j;
            }
        }
        if (min != i) {
            swap (a[min], a[i]);
        }
    }
}

void intList::insertionSort() {
    for (int i = 1; i < listSize; i++) {
        int key = a[i];
        int j = i - 1;
        while (j > 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
