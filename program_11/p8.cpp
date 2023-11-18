// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 8
// Date: 10/25/23

#include <iostream>   // gets cin, cout, cerr
#include "p8.h"

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

// Creates a helper function to swap two integers with each other
void intList::swap(int &x, int &y) {
    // Create a temporary variable to hold the value of x while they are swapped
    int temp = x;
    x = y;
    y = temp;
}

//******************************************************************************
// Andrew Chapuis

// Insert function: First shifts all entries right, then inserts the inputted 
// key into the beginning of the list
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

// *****************************************************************************
// Aidan Wright

// Add function: inserts the given key at the end of the list
bool intList::add(int key){
    bool rc = false;
    // If there is space for another entry to be added, it will be
    if (listSize < listCapacity) {
        a[listSize] = key; 
        rc = true;
        listSize++;
    }
    return(rc);
}

// *****************************************************************************
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

// This will delete an entry from the array by shifting the remaining 
// data to the left and will return the key that was in the deleted index
// unless the index given is outside the bounds of the list created
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

// This function will search the list until it finds the first instance of the
// key given or it reaches the end of the list.
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
// Andrew Chapuis

// Sorts the list by moving the maximum key in the array to the rightmost index
// and then decreasing the amount of the array that is being looked at by 1 
// each time
void intList::bubbleSort() {
    // As i is decreased, the maximum values that have already been sorted are
    // not compared
    for (int i = listSize - 1; i > 0 ; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

//******************************************************************************
// Aidan Wright

// Sorts the array by finding the index with the minimum key in the array 
// and then swapping that index with the leftmost index that has not been sorted
void intList::selectionSort() {
    for (int i = 0; i < listSize - 1; i++) {
        // Initialize minIndex to i each time the loop reiterates
        int minIndex = i;
	// All the keys in the array will be compared with minIndex to find 
	// the index with the minimum value
        for (int j = i + 1; j < listSize; j++) {
            // If a smaller key was found, minIndex will be set to the index 
	    // being compared
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
	// If i is not the minIndex swap the values in the array
        if (minIndex != i) {
            swap(a[minIndex], a[i]);
        }
    }
}

//******************************************************************************
// Andrew Chapuis

// Sorts the list by slowly increasing the size of the sorted subarray. This is
// accomplished by inserting the next index into the subarray and then swapping
// that key with the index to the left's key if it is less than the key. Once it
// is sorted, the subarray will add the next index
void intList::insertionSort() {
    // i keeps track of the sorted subarray
    for (int i = 0; i < listSize - 1; i++) {
	// j is initialized at the index being inserted into the subarray
	for (int j = i + 1; j > 0; j--) {
	    // The inserted index is swapped until it is in its sorted place 
	    if (a[j - 1] > a[j]) {
		swap(a[j - 1], a[j]);
	    } else {
		break;
	    }
	}
    }
}

//******************************************************************************
// Aidan Wright

// Prints a specific number of items on the list unless the passed in number is
// greater than the size of the list
void intList::printIt(int n) const {
    // Print the list size and capacity
    cout << "printIt with list size: " << listSize << " capacity: " << 
	listCapacity << "\n";
    // Print the entire list if n is greater than or equal to listSize
    if (n >= listSize) {
        for (int i = 0; i < listSize; i++) {
	    cout << "At pos " << i << " there is " << a[i] << "\n";
        }
    // Only n items will be printed from the list and then the last entry in the
    // list will also be printed
    } else {
        for (int i = 0; i < n; i++) {
	    cout << "At pos " << i << " there is " << a[i] << "\n";
            // After the nth entry is printed, print the last entry on the list
	    if (i == n - 1) {
                cout << "At pos " << listSize - 1 << " there is " 
		    << a[listSize - 1] << "\n";
            }
        }
    }
}

//******************************************************************************
// Aidan Wright

// Returns the capacity of the list
int intList::capacity() {
    return(listCapacity);
}

//******************************************************************************
// Andrew Chapuis

// returns true if the list is sorted in ascending order
// otherwise, it returns false 
// If it fails, print the index where the failure occurs
bool intList::isSorted() const {
    bool rc = true;
    for (int i = 0; i < listSize - 1; i++) {
	// If an index's key is greater than the index + 1's key, then the index
	// will be printed and the function will return false.
        if (a[i] > a[i + 1]) {
            rc = false;
	    cout << "Is not sorted at index " << i << "\n";
	    break;
        }
    }
    return rc;
}


//******************************************************************************
// Aidan Wright

// Sorts the list by creating a heap and then sorting it
void intList::heapSort(){
    // Sort the array into a heap
    buildHeap();
    // The top of the heap will be swapped with the last index in the heap
    // After that, the index at the top is heapified
    while (heapSize > 1) {
        heapSize--;
        swap(a[0], a[heapSize]);
	// Deacerasing heapSize ensures that the already sorted indices are not
	// placed back in the heap.
        heapify(0);
    }
}


//******************************************************************************
// Andrew Chapuis

// Turns an array into a heap by heapifying every parent into the correct index
void intList::buildHeap() {
    // When the heap is built, set the heapSize equal to the listSize
    heapSize = listSize;
    // Starting at the last parent, each parent will be heapified into their 
    // correct index to become a heap
    for(int i = heapSize/2-1; i >= 0; i--) {
        heapify(i);
    }
}



//******************************************************************************
// Andrew Chapuis


void intList::heapify(int index) {
    int l = left(index);
    int r = right(index);
    // Create a variable 'largest' that will keep track of the index with the
    // largest value among a parent and its children
    int largest = index;
    if (l < heapSize) {
        // If the left child has a larger value than its parent, largest will
        // equal the index of the left child
        if (a[l] > a[largest]) {
            largest = l;
        }
    }
    if (r < heapSize) {
        // if the right child has a larger value than the larger of the left 
        // child or the parent, largest will equal the index of the right child
        if (a[r] > a[largest]) {
            largest = r;		    
        }
    }
    
    // If the index does not have the largest value, it will swap it with the 
    // child with the largest value and recall the function to check again
    if (largest != index) {
        swap(a[largest], a[index]);
        index = largest;
        heapify(index);
    }
}


//******************************************************************************
// Aidan Wright

// Returns the left child of an index
int intList::left(int index) const {
    int ind = index * 2 + 1;
    return ind;
}

//******************************************************************************
// Andrew Chapuis

// Returns the right child of an index
int intList::right(int index) const {
    int ind = (index + 1) * 2;
    return ind;
}
