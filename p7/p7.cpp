//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 7
//Date: 10/18/23

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

// Creates a helper function to swap two integers with each other
void intList::swap(int *x, int *y) {
    // Create a temporary variable to hold the value of x while they are swapped
    int temp = *x;
    *x = *y;
    *y = temp;
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
                swap(&a[j], &a[j + 1]);
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
            swap(&a[minIndex], &a[i]);
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
		swap(&a[j - 1], &a[j]);
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
