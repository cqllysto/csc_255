//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 1
//Date: 08/28/23

#ifndef __P1H
#define __P1H

#include <string>

class stringList {
    private:
	std::string *a; // A pointer to the array into which the list values will be stored
	int listCapacity; // Memorialize the capacity of the list
	int listSize; // An integer to track the number of entries on the list

    public:
	stringList(int listCapacity = 100); //constructor
	~stringList(); //destructor
	
	bool insert(std::string text); //inserts a text into beginning of list
	bool add(std::string text); //adds a text to the end of the list
	bool insertAt(int index, std::string text); //inserts text at given index
	bool deleteAt(int index, std::string &text); //deletes text at given index
	void clear(); //empties the list
	void printIt() const; //prints the whole list and each index entry
	int getIndex(std::string text) const; //gets the index of a text
	bool readAt(int index, std::string &text) const; //reads the text at given index
	int count() const; //counts the size of the list
};

#endif

