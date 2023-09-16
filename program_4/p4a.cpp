// Name: Andrew Chapuis and Aidan Wright
// Course: CSC 255
// Program 4
// Team 3
// Date: 09/01/23

#include <iostream>
#include "p4.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Node Constructor
sNode::sNode(string text) {
    this->text = text;

}


//******************************************************************************
// Aidan Wright

// BST Constructor
sBST::sBST() {
    right = left = NULL;
    treeCount = 0;
}



// BST Destructor
sBST::~sBST() {
    clear();
}

// public insert
bool sBST::insert(string text) {
    return(insert(text, &root));
}

// private insert
bool insert(string text, sNode *root) {
    rc = false;
    if(root) {
	if(root->text > text) {
	    rc = ins(text, root->left);
	} else if(root->text < text) {
	    rc = ins(text, root->right);
	}
    } else {
	root = new sNode(text);
	rc = true;
	treeCount++;
    }

    return(rc);
}



// public remove
bool sBST::remove(string text) {
    return(remove(text, &root));
}


// private remove
bool sBST::remove(string text, sNode *root) {
    if (root) {
	if (root->text > text) {
	    rc = remove(text, root->left);
	} else if (root->text < text) {
	    rc = remove(text, root->right);
	} else {
	    if ((!root->left) && (!root->right)) {
		delete root;
		root = NULL;
		treeCount--;
	    } else if (!root->right) {
		sNode *p2 = root->left;
		delete root;
		root = p2
		treeCount--;
	    } else {
		root->text = findMin(root->right);
		remove(root->text, root->right);
	    }
	}
    }
    return(rc);
}

