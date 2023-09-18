// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 4
// Date: 09/18/23

#include <iostream>   // gets cin, cout, cerr
#include "p4.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Constructor for the nodes to be inserted on the BST
sNode::sNode(string txt) {
    text = txt;
    left = right = NULL;
    h = 0;
}

//******************************************************************************
// Andrew Chapuis

// Constructor for the BST
sBST::sBST() {
    treeCount = 0;
    root = NULL;
}

//******************************************************************************
// Andrew Chapuis

// Destructor for the BST. All that required is to call clear, which will
// delete the entire tree
sBST::~sBST() {
    clear(root);
}

//******************************************************************************
// Andrew Chapuis

// A private function that will find the minimum value in the BST.
string sBST::findMin(sNode *ptr) {
    string rc;
    // According to the rules, as long as there is a left child, there is 
    // a node with a value less than the current node. If there is no left
    // child, then the minimum has been found
    if (ptr) {
	if (ptr->left) {
	    rc = findMin(ptr->left);
	} else {
	    rc = ptr->text;
	}
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// A private insert function that will recursively check whether the text to 
// be inserted is greater or less than the value of the node.
bool sBST::insert(string text, sNode *&p) {
    bool rc = false;
    // If the node exists, then the passed text needs to be compared with 
    // the node's text. If it is not equal, then the function will be called 
    // again with a child node. If it is equal, then the function will end and 
    // return false.
    if (p) {
	if (p->text > text) {
	    rc = insert(text, p->left);
	} else if (p->text < text) {
	    rc = insert(text, p->right);
	}
    // If the node does not exist, then a new node can be allocated with the 
    // text that was passed in.
    } else {
	p = new sNode(text);
	rc = true;
	treeCount++;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// A private function that will delete a node from the BST.
bool sBST::remove(string text, sNode *&p) {
    bool rc = false;
    if (p) {
	// First, the desired node must be found to be deleted, so if the text 
	// does not equal the passed text, the function will be called again 
	// with a child node
	if (p->text > text) {
	    rc = remove(text, p->left);
	} else if (p->text < text) {
	    rc = remove(text, p->right);
	// Once the correct node is found, it will be deleted in one of two ways
	} else {
	    rc = true;
	    // If it is a leaf, then it can be deleted
	    if (!p->left && !p->right) {
		delete p;
		p = NULL;
		treeCount--;
	    // If it only has a left child, then the path can be subverted so
	    // that the parent will point to the child after the node is deleted
	    } else if (!p->right) {
		sNode *p2 = p->left;
		delete p;
		p = p2;
		treeCount--;
	    // If it has a right child, it will take the text of the minimum 
	    // of its right subtree and call the function to remove that text
	    } else {
		p->text = findMin(p->right);
		remove(p->text, p->right);
	    }
	}
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// A private function that will search the list for the given text.
bool sBST::isIn(string text, sNode *p) const {
    bool rc = false;
    // If the node exists, the the text will be compared with the node's text.
    // If the text is less than the node's, the function will be called again 
    // with the left child. If it is greater than, then the function will be
    // called again with the right child. If it is equal, then the function
    // will return true
    if (p) {
    	if (p->text > text) {
    	    rc = isIn(text, p->left);
    	} else if (p->text < text) {
    	    rc = isIn(text, p->right);
    	} else {
    	    rc = true;
    	}
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// Private function that will print the tree
void sBST::printIt(sNode *p) const {
    // Starting with the passed node, the entire tree will be printed by first
    // printing all the left children, then printing the text in its own node,
    // and finishing by printing all the right children.
    if (p) {
	printIt(p->left);
	cout << p->text << "\n";
	printIt(p->right);
    }
}

//******************************************************************************
// Aidan Wright

// A private function that will delete all the nodes in a tree
void sBST::clear(sNode *&p) {
    // If the node exists, the function will first be called for the children
    // nodes, before deleting the passed node and setting its pointer to NULL.
    if (p) {
	clear(p->left);
	clear(p->right);
	delete p;
	p = NULL;
    }
}

//******************************************************************************
// Aidan Wright

// Public version of insert that calls the private function at the root
bool sBST::insert(string text) {
    return(insert(text, root));
}

//******************************************************************************
// Aidan Wright

// Public version of remove that calls the private function at the root
bool sBST::remove(string text) {
    return(remove(text, root));
}

//******************************************************************************
// Andrew Chapuis

// Public version of isIn that calls the private function at the root
bool sBST::isIn(string text) const {
    return(isIn(text, root));
}

//******************************************************************************
// Andrew Chapuis

// Public version of print that calls the private function at the root
void sBST::printIt() const {
    printIt(root);
}

//******************************************************************************
// Andrew Chapuis

// Returns the number of nodes that have been inserted into the BST 
int sBST::count() const {
    return(treeCount);
}

//******************************************************************************
// Andrew Chapuis

// Public version of clear that calls the private function at the root and 
// resets treeCount for reinsertion
void sBST::clear() {
    clear(root);
    treeCount = 0;
}
