// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 4
// Date: 09/18/23

#ifndef __P4_H
#define __P4_H

#include <string>

//******************************************************************************
// Both

// Declaration so that the class can be friended
class sBST;

//******************************************************************************
// Both

class sNode {
    private:
	// Constructor for the node class	
	sNode(std::string text = "");

	// The variables that are associated with each node
	std::string text;
	int h;
	sNode *left, *right;

	friend class sBST;
};

//******************************************************************************
// Both

class sBST {
    private:
	// Tracks the number of nodes in the BST
	int treeCount;
	// Points to the root of the entire tree
	sNode *root;

	// Private function that finds the minimum value of a tree
	std::string findMin(sNode *p);
	// Private functions to be called by their public counterparts
	// Inserts a node into the tree
	bool insert(std::string text, sNode *&p);
	// Removes a node from the tree
	bool remove(std::string text, sNode *&p);
	// Checks to see if text is in the BST
	bool isIn(std::string text, sNode *p) const;
	// Prints the tree from least to greatest
	void printIt(sNode *p) const;
	// Clears the tree
	void clear(sNode *&p);
	
    public:
	// Constructor and destructor for the BST
	sBST();
	~sBST();

	// Public functions that will call their private functions at the 
	// root of the tree
	bool insert(std::string text);
	bool remove(std::string text);
	bool isIn(std::string text) const;
	void printIt() const;
	void clear();
	// Returns the number of nodes in the BST
	int count() const;
};

#endif
