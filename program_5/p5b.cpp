// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 5
// Date: 09/25/23

#include <iostream>   // gets cin, cout, cerr
#include "p5.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Constructor for the nodes to be inserted on the BST
sNode::sNode(string txt) {
    text = txt;
    left = right = NULL;
    h = 1;
}

//******************************************************************************
// Andrew Chapuis

// Constructor for the BST
sAVL::sAVL() {
    treeCount = 0;
    root = NULL;
}

//******************************************************************************
// Andrew Chapuis

// Destructor for the BST. All that required is to call clear, which will
// delete the entire tree
sAVL::~sAVL() {
    clear(root);
}

//******************************************************************************
// Andrew Chapuis

// Will return the maximum between two integers
int sAVL::max(int a, int b) const {
    return(a > b ? a : b);
}

//******************************************************************************
// Andrew Chapuis

// A private function that will find the minimum value in the BST.
string sAVL::findMin(sNode *ptr) {
    string rc;
    // According to the rules, as long as there is a left child, there is 
    // a node with a value less than the current node. If there is no left
    // child, then the minimum has been found
    if (ptr->left) {
	rc = findMin(ptr->left);
    } else {
	rc = ptr->text;
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

// A private insert function that will recursively check whether the text to 
// be inserted is greater or less than the value of the node.
bool sAVL::insert(string text, sNode *&p) {
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
	// Check whether the nodes will need balanced after the new one is 
	// inserted
    // If the node does not exist, then a new node can be allocated with the 
    // text that was passed in.
    } else {
	p = new sNode(text);
	rc = true;
	treeCount++;
    }
    bal(p);
    return(rc);
}

//******************************************************************************
// Aidan Wright

// A private function that will delete a node from the BST.
bool sAVL::remove(string text, sNode *&p) {
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
    bal(p);
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

// A private function that will search the list for the given text.
bool sAVL::isIn(string text, sNode *p) const {
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
void sAVL::printIt(sNode *p, int &index) const {
    // Starting with the passed node, the entire tree will be printed by first
    // printing all the left children, then printing the text in its own node,
    // and finishing by printing all the right children.
    if (p) {
	printIt(p->left, index);
	cout << "At " << index << " the string is " << p->text << ": height = "
	    << p->h << "\n";
	index++;
	printIt(p->right, index);
    }
}

//******************************************************************************
// Aidan Wright

// A private function that will delete all the nodes in a tree
void sAVL::clear(sNode *&p) {
    // If the node exists, the function will first be called for the children
    // nodes, before deleting the passed node and setting its pointer to NULL.
    if (p) {
	clear(p->left);
	clear(p->right);
	delete p;
    }
}

//******************************************************************************
// Andrew Chapuis

// Rotates a tree to the left around its root
void sAVL::rotateLeft(sNode *&p1) {
    // create a new pointer to get a handle on the middle node 
    // of a right heavy subtree
    sNode *p2 = p1->right;
    // set the right child of the first node to be the left child of the
    // middle node
    p1->right = p2->left;
    // set the left child of the middle node to be the first node
    p2->left = p1;
    p1->h = calcHeight(p1);
    // make the middle node take the place of the top node
    p1 = p2;
    p1->h = calcHeight(p1);
}

//******************************************************************************
// Andrew Chapuis

// Rotates a tree to the left around its root
void sAVL::rotateRight(sNode *&p1) {
    // create a new pointer to get a handle on the middle node 
    // of a left heavy subtree
    sNode *p2 = p1->left;
    // set the left child of the first node to be the right child of the
    // middle node
    p1->left = p2->right;
    // set the right child of the middle node to be the first node
    p2->right = p1;
    p1->h = calcHeight(p1);
    // make the middle node take the place of the top node
    p1 = p2;
    p1->h = calcHeight(p1);
}

//******************************************************************************
// Aidan Wright

void sAVL::bal(sNode *&p) {
    // determine the height difference between the left child and right child
    int diff = height(p->left) - height(p->right);
    // if the tree is left heavy, there is an imbalance
    if (diff == 2) {
	// calculate the difference in height between the left child's 
	// children to determine if the tree is left left heavy or 
	// left right heavy
	int childDiff = height(p->left->left) - height(p->left->right);
	if (childDiff < 0) {
	    // if the subtree is left right heavy, rotate the subtree
	    // to the left around the middle node rather than the root
	    // of the subtree making it left left heavy
	    rotateLeft(p->left);
	}
	// the tree is left left heavy, and is rotated to the right
	// around the root of the tree
	rotateRight(p);
    // if the tree is right heavy, there is an imbalance
    } else if (diff == -2) {
	// calculate the difference in height between the right child's 
	// children to determine if the tree is right right heavy or 
	// right left heavy
	int childDiff = height(p->right->left) - height(p->right->right);
	if (childDiff > 0) {
	    // if the subtree is right left heavy, rotate the subtree
	    // to the right around the middle node rather than the root
	    // of the subtree making it right right heavy
	    rotateRight(p->right);
	}
	// the tree is right right heavy, and is rotated to the left
	// around the root of the tree
	rotateLeft(p);
    } else {
	// if there is not an imbalance, calculate the height of the root
	p->h = calcHeight(p);
    }
}

//******************************************************************************
// Andrew Chapuis

int sAVL::height(sNode *p) const {
    int rc = 0;
    // the node exists then set the return condition to the height of the node
    if (p) {
	rc = p->h;
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

int sAVL::calcHeight(sNode *p) {
    // set the height of the subtree root to the max height of either of 
    // its children plus one
    return(max(height(p->left), height(p->right)) + 1);
}

//******************************************************************************
// Aidan Wright

// Public version of insert that calls the private function at the root
bool sAVL::insert(string text) {
    return(insert(text, root));
}

//******************************************************************************
// Aidan Wright

// Public version of remove that calls the private function at the root
bool sAVL::remove(string text) {
    return(remove(text, root));
}

//******************************************************************************
// Andrew Chapuis

// Public version of isIn that calls the private function at the root
bool sAVL::isIn(string text) const {
    return(isIn(text, root));
}

//******************************************************************************
// Andrew Chapuis

// Public version of print that calls the private function at the root
void sAVL::printIt() const {
    // Create a variable that will track which index is being printed.
    int index = 0;
    printIt(root, index);
}

//******************************************************************************
// Andrew Chapuis

// Returns the number of nodes that have been inserted into the BST 
int sAVL::count() const {
    return(treeCount);
}

//******************************************************************************
// Andrew Chapuis

// Public version of clear that calls the private function at the root and 
// resets treeCount for reinsertion
void sAVL::clear() {
    clear(root);
    treeCount = 0;
    root = NULL;
}

