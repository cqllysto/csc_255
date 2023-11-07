// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 9b
// Date: 11/08/23

#ifndef __CIL_H
#define __CIL_H

//******************************************************************************
class cIntList {
    private:
	// These are the private variables of the class
	int *a; // creates the array that points to the list
	int listCapacity; // sets the capacity of the list
	int listCount; // keeps track of the number of things in the list
	int first; // is indexed to the first thing in the list
	int last; // is indexed to the last thing in the list

	// These are the private functions of the class
	// increments values and wraps around the date line
	void incVal(int &value); 
	// decrements values and wraps around the date line
	void decVal(int &value);
	// Helper function that converts a virtual index into physical
	int vToP(int value) const;

    public:
	// These are the constructor and destructor of the class
	cIntList(int capacity = 100);
	~cIntList();

	// These are the modifying and non-modifying functions
	// inserts a text to the beginning of the list
	bool insert(int text);
	// adds a text to the end of the list
	bool add(int text);
	// inserts a text at the given index in the list
	bool insertAt(int index, int text);
	// deletes a text at the given index in the list
	bool deleteAt(int index, int &text);
	// reads a text at the given index in the list
	bool readAt(int index, int &text);
	// deletes the first thing on the list
	bool deleteFirst(int &text);
	// deletes the last thing on the list
	bool deleteLast(int &text);
	// empties the list
	void clear();
	// counts the number of things in the list
	int count() const;
	// gets the index of the given string
	int getIndex(int text) const;
	// prints the list's contents
	void printIt() const;
};

#endif
