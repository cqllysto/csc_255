//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 3
//Date: 09/11/23

#ifndef __P3_H
#define __P3_H

#include <string>
//******************************************************************************
class cStringList {
    private:
	// These are the private variables of the class
	std::string *a; // creates the array that points to the list
	int listCapacity; // sets the capacity of the list
	int listCount; // keeps track of the number of things in the list
	int first; // is indexed to the first thing in the list
	int last; // is indexed to the last thing in the list

	// These are the private functions of the class
	// increments values and wraps around the date line
	void incVal(int &value); 
	// decrements values and wraps around the date line
	void decVal(int &value);

    public:
	// These are the constructor and destructor of the class
	cStringList(int capacity = 100);
	~cStringList();

	// These are the modifying and non-modifying functions
	// inserts a text to the beginning of the list
	bool insert(std::string text);
	// adds a text to the end of the list
	bool add(std::string text);
	// inserts a text at the given index in the list
	bool insertAt(int index, std::string text);
	// deletes a text at the given index in the list
	bool deleteAt(int index, std::string &text);
	// reads a text at the given index in the list
	bool readAt(int index, std::string &text);
	// deletes the first thing on the list
	bool deleteFirst(std::string &text);
	// deletes the last thing on the list
	bool deleteLast(std::string &text);
	// empties the list
	void clear();
	// counts the number of things in the list
	int count() const;
	// gets the index of the given string
	int getIndex(std::string text) const;
	// prints the list's contents
	void printIt() const;
};

#endif
