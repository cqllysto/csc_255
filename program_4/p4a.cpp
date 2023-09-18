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
    left = right = NULL;
}


//******************************************************************************
// Aidan Wright

// BST Constructor
sBST::sBST() {
    root = NULL;
    treeCount = 0;
}


//******************************************************************************
// Aidan Wright

// BST Destructor
sBST::~sBST() {
    clear();
}


//******************************************************************************
// Aidan Wright
// public insert
bool sBST::insert(string text) {
    return(insert(text, root));
}


//******************************************************************************
// Aidan Wright
// private insert
bool insert(string text, sNode *&p) {
    rc = false;
    if(p) {
	if(p->text > text) {
	    rc = ins(text, p->left);
	} else if(p->text < text) {
	    rc = ins(text, p->right);
	}
    } else {
	p = new sNode(text);
	rc = true;
	treeCount++;
    }

    return(rc);
}



//******************************************************************************
// Aidan Wright
// public remove
bool sBST::remove(string text) {
    return(remove(text, root));
}


//******************************************************************************
// Aidan Wright
// private remove
bool sBST::remove(string text, sNode &p) {
    if (p) {
	if (p->text > text) {
	    rc = remove(text, p->left);
	} else if (p->text < text) {
	    rc = remove(text, p->right);
	} else {
	    if ((!p->left) && (!p->right)) {
		delete p;
		p = NULL;
		treeCount--;
	    } else if (!p->right) {
		sNode *p2 = p->left;
		delete p;
		p = p2
		treeCount--;
	    } else {
		p->text = findMin(p->right);
		remove(p->text, p->right);
	    }
	}
    }
    return(rc);
}

