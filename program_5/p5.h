// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 5
// Date: 10/04/23

#ifndef __P5_H
#define __P5_H

#include <string>

//******************************************************************************
// Both

// Declaration so that the class can be friended
class sAVL;

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

	friend class sAVL;
};

//******************************************************************************
// Both

class sAVL {
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
	void printIt(sNode *p, int &index) const;
	// Clears the tree
	void clear(sNode *&p);
	
	// Finds the max of two integers
	int max(int a, int b) const;
	// Rotates the tree to the left around the node
	void rotateLeft(sNode *&p1);
	// Rotates the tree to the right around the node
	void rotateRight(sNode *&p1);
	// Balances the tree if it is unbalanced
	void bal(sNode *&p);
	// Returns the height of a node
	int height(sNode *p) const;
	// Calculates the height of a node
	int calcHeight(sNode *p);

    public:
	// Constructor and destructor for the BST
	sAVL();
	~sAVL();

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

