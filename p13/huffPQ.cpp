// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 13
// Date: 12/04/23

#include <iostream>   // gets cin, cout, cerr
#include <cmath>
#include "p13.h"

using namespace std;



//******************************************************************************
// Aidan Wright

huffNode::huffNode(char val, int key, huffNode *left, huffNode *right) {
    // Instructor provided
    this->val = val;
    this->key = key;
    this->left = left;
    this->right = right;
}


//******************************************************************************
// Aidan Wright

huffPQ::huffPQ(int n) {
    entries = new huffNode *[n];
    qCount = 0;
    pqSize = n;
}

//******************************************************************************
// Aidan Wright

huffPQ::~huffPQ() {
    if(entries) {
        delete [] entries;
    }
}

//******************************************************************************
// Andrew Chapuis

// Finds the parent index of an index
int huffPQ::parent(int index) const {
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
int huffPQ::left(int index) const {
    int ind = index * 2 + 1;
    return ind;
}

//******************************************************************************
// Aidan Wright

// Returns the right child of an index
int huffPQ::right(int index) const {
    int ind = (index + 1) * 2;
    return ind;
}


//******************************************************************************
// Aidan Wright

// Creates a helper function to swap two integers with each other
void huffPQ::swap(huffNode *&x, huffNode *&y) {
    // Create a temporary variable to hold the value of x while they are swapped
    huffNode temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************
// Aidan Wright

// A private function that will move a value up the tree when it is inserted
void huffPQ::bubbleUp(int index) {
    int per = parent(index);
    // If the passed index's value is greater than it's parent's value
    // their values will be swapped and then the value will be compared to it's 
    // new parent's value. It will keep swapping until a parent is greater or 
    // the value reaches the top of the queue
    while ((entries[per]->key > entries[index]->key)) {
        swap(entries[index], entries[per]);
        index = per;
        per = parent(index);
    }
}

//******************************************************************************
// Andrew Chapuis

// A private function that will push a value down the queue if it is smaller
// than it's children
void huffPQ::heapify(int index) {
    int l = left(index);
    int r = right(index);
    // Create a variable 'largest' that will keep track of the index with the
    // largest value among a parent and its childre
    int largest = index;
    if (l < qCount) {
        // If the left child has a larger value than its parent, largest will
        // equal the index of the left child
        if (entries[l]->key > entries[largest]->key) {
            largest = l;
        }
    }
    if (r < qCount) {
        // if the right child has a larger value than the larger of the left 
        // child or the parent, largest will equal the index of the right child
        if (entries[r]->key > entries[largest]->key) {
            largest = r;		    
        }
    }
    
    // If the index does not have the largest value, it will swap it with the 
    // child with the largest value and recall the function to check again
    if (largest != index) {
        swap(entries[largest], entries[index]);
        index = largest;
        heapify(index);
    }
}


//******************************************************************************
// Aidan Wright

bool huffPQ::enq(huffNode *v ) {
    bool rc = false;
    if (qCount < pqSize) {
        // Insert the value at the end of the array
        entries[qCount] = v;
        // Push the value up the heap if it is less than its parent
        bubbleUp(qCount);
        qCount++;
        rc = true;
    }
    return rc;
}

//******************************************************************************
// Andrew Chapuis

// Dequeues the greatest value in the queue
bool huffPQ::deq(huffNode *&v) {
    bool rc = false;
    if (qCount) {
        rc = true;
        qCount--;
        // Sets v to the highest value in the queue
        v = entries[0];
        // Moves the last entry in the array to the top and then heapifies it
        // so that the queue gets updated
        entries[0] = entries[qCount];
        heapify(0);
    }
    return rc;
}

//******************************************************************************
// Aidan Wright

// Clears the queue by setting qCount to 0
void huffPQ::clear() {
    qCount = 0;
}

//******************************************************************************
// Andrew Chapuis

// Returns the number of entries in the list
int huffPQ::count() const {
    return qCount;
}



void huffPQ::printIt(int ind, int count) const {
    // create a local variable to account for indices
    int ind2;
    // create a local variable level that will account for the level being
    // printed
    int level = log2(ind + 1);
    cout << "level[" << level << "]->";
    
    // Print each value on the level 
    for (int i = ind; count > 0 && i < qCount; count--) {
        cout << entries[i] << " ";
        i++;
        ind2 = i;
    }
    
    cout << endl;
    
    // If there are more levels to be printed, call printIt again
    if (level < log2(qCount) - 1) {
        printIt(ind2, pow(2, (level + 1)));
    }
} 

// Public function that calls the private printIt to print the queue
void huffPQ::printIt2() const {
    printIt(0, 1);
}
