// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 7
// Date: 10/18/23

#ifndef __P7_H
#define __P7_H


class intList {
    private:
        int *a; // Pointer to the list
        int listCapacity; // The capacity of the list
        int listSize; // An integer to track the number of entries on the list
	void swap(int *x, int *y); //swaps two integers with each other

    public:
	intList(int listCapacity = 100); //constructor
	~intList(); //destructor
	
        bool insert(int key); //inserts a key into beginning of list
        bool add(int key); //adds a key to the end of the list
        bool insertAt(int index, int key); //inserts key at given index
        bool deleteAt(int index, int &key); //deletes key at given index
        void clear(); //empties the list
        void printIt(int n) const;  // print the first n entries of the list 
        int getIndex(int key) const; //gets the index of a key
        bool readAt(int index, int &key) const; //reads the key at given index
        int count() const; //counts the size of the list
        int capacity(); // returns the capacity of the list

	// Sorting functions that will be used and compared
        void bubbleSort();
        void selectionSort();
        void insertionSort();

	// Returns true if the list is sorted and false if not
        bool isSorted() const; 
};

#endif
