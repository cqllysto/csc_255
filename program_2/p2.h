//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#ifndef __P2_H
#define __P2_H

#include <string>

//******************************************************************************
// Aidan Wright
class stringLinkedList; // Creates an empty class to be friended in the
			// node class and defined later


//******************************************************************************
// Aidan Wright
// class definition of a node containing a pointer called next and a string
class node {
    private:
	node(std::string text = "", node *pn = NULL);

	std::string text;
	node *next;
	
	// friending the stringLinkedList class so it can call the node
	friend class stringLinkedList;
};

//******************************************************************************
// Andrew Chapuis

// stringLinkedList class creates a linked list that uses nodes and has the 
// following functions
class stringLinkedList {
    private:
	// creates two pointers that point to the beginning and end of the 
	// list respectively
	node *first, *last;
	int listCount; // integer to keep track of the size of the list
	
	// helper function for getIndex
	int getIndex(std::string text, node *pn, int index) const;
	// helper function for printIt
	void printIt(node *pn, int index) const;
	// helper function for clear
	void clear(node *pn);
    public:
	stringLinkedList(); // linked list constructor
	~stringLinkedList(); // linked list deconstructor

	//Modifying Functions
	// inserts a text at the beginning of the list
	bool insert(std::string text); 
	// adds a text at the end of the list
	bool add(std::string text); 
	// inserts the text in a node at the given index within the list
	bool insertAt(int index, std::string text); 
	// deletes a node at the given index and returns the text it had
	bool deleteAt(int index, std::string &text);
	// clears the entire list
	void clear();

	//Non-modifying Functions
	// returns the text at the given index
	bool readAt(int index, std::string &text) const;
	// gets the index of a given string
	int getIndex(std::string text) const;
	// prints the entire list
	void printIt() const;
	// counts the number of nodes in the list
	int count() const;
};

#endif
