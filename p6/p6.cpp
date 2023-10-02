// Name: Andrew Chapuis and Aidan Wright
// Course: CSC 255
// Program 6
// Date: 10/02/23

#include <iostream>  
#include <cmath>
#include "p6.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Priority Queue Constructor
iPQ::iPQ(int qCapacity) {
    // Initialize qCount and create an array with the passed in qCapacity or 100
    // if no qCapacity was given.
    qCount = 0;
    this->qCapacity = qCapacity;
    values = new int[qCapacity];
}

//******************************************************************************
// Aidan Wright

// Priority Queue Destructor
iPQ::~iPQ() {
    // If the array exists, delete the array and set values to NULL.
    if(values) {
        delete [] values;
        values = NULL;
    }
}

//******************************************************************************
// Andrew Chapuis

// Finds the parent index of an index
int iPQ::parent(int index) const {
    // If index is greater than 0, it will perform the operation to find its
    // parent; otherwise, the function returns 0
    int ind = 0;
    if (index > 0) {
        ind = (index - 1) / 2;
    }
    return ind;
}

//******************************************************************************
// Aidan Wright

// Returns the left child of an index
int iPQ::left(int index) const {
    int ind = index * 2 + 1;
    return ind;
}

//******************************************************************************
// Aidan Wright

// Returns the right child of an index
int iPQ::right(int index) const {
    int ind = (index + 1) * 2;
    return ind;
}

//******************************************************************************
// Aidan Wright

void iPQ::printIt(int ind, int count) const {
    // create a local variable to account for indices
    int ind2;
    // create a local variable level that will account for the level being
    // printed
    int level = log2(ind + 1);
    cout << "level[" << level << "]->";
    
    // Print each value on the level 
    for (int i = ind; count > 0 && i < qCount; count--) {
        cout << values[i] << " ";
        i++;
        ind2 = i;
    }
    
    cout << endl;
    
    // If there are more levels to be printed, call printIt again
    if (level < log2(qCount) - 1) {
        printIt(ind2, pow(2, (level + 1)));
    }
} 

//******************************************************************************
// Aidan Wright

// Creates a helper function to swap two integers with each other
void iPQ::swap(int *x, int *y) {
    // Create a temporary variable to hold the value of x while they are swapped
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************
// Aidan Wright

// A private function that will move a value up the tree when it is inserted
void iPQ::bubbleUp(int index) {
    int per = parent(index);
    // If the passed index's value is greater than it's parent's value
    // their values will be swapped and then the value will be compared to it's 
    // new parent's value. It will keep swapping until a parent is greater or 
    // the value reaches the top of the queue
    while ((values[per] < values[index]) && (per != index)) {
        swap(&values[index], &values[per]);
        index = per;
        per = parent(index);
    }
}

//******************************************************************************
// Andrew Chapuis

// A private function that will push a value down the queue if it is smaller
// than it's children
void iPQ::heapify(int index) {
    int l = left(index);
    int r = right(index);
    // Create a variable 'largest' that will keep track of the index with the
    // largest value among a parent and its childre
    int largest = index;
    if (l < qCount) {
        // If the left child has a larger value than its parent, largest will
        // equal the index of the left child
        if (values[l] > values[largest]) {
            largest = l;
        }
    }
    if (r < qCount) {
        // if the right child has a larger value than the larger of the left 
        // child or the parent, largest will equal the index of the right child
        if (values[r] > values[largest]) {
            largest = r;		    
        }
    }
    
    // If the index does not have the largest value, it will swap it with the 
    // child with the largest value and recall the function to check again
    if (largest != index) {
        swap(&values[largest], &values[index]);
        index = largest;
        heapify(index);
    }
}

//******************************************************************************
// Aidan Wright

// Inserts a value into the queue and bubbles it up the heap
bool iPQ::enq(int v) {
    bool rc = false;
    if (qCount < qCapacity) {
        // Insert the value at the end of the array
        values[qCount] = v;
        // Push the value up the heap if it is greater than its parent
        bubbleUp(qCount);
        qCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Andrew Chapuis

// Dequeues the greatest value in the queue
bool iPQ::deq(int &v) {
    bool rc = false;
    if (qCount) {
        rc = true;
        qCount--;
        // Sets v to the highest value in the queue
        v = values[0];
        // Moves the last entry in the array to the top and then heapifies it
        // so that the queue gets updated
        values[0] = values[qCount];
        heapify(0);
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

// Public function that calls the private printIt to print the queue
void iPQ::printIt() const {
    printIt(0, 1);
}

//******************************************************************************
// Aidan Wright

// Clears the queue by setting qCount to 0
void iPQ::clear() {
    qCount = 0;
}

//******************************************************************************
// Andrew Chapuis

// Returns the number of entries in the list
int iPQ::count() const {
    return qCount;
}
