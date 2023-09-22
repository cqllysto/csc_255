// Name: Andrew Chapuis and Aidan Wright
// Course: CSC 255
// Program 4
// Team 3
// Date: 09/22/23

#include <iostream>
#include "p4.h"

using namespace std;

//******************************************************************************
// Aidan Wright

// Node Constructor
sNode::sNode(string text) {
    this->text = text;
    left = right = NULL;
    h = 0;
}


//******************************************************************************
// Aidan Wright

// BST Constructor
sBST::sBST() {
    treeCount = 0;
    root = NULL;
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
bool sBST::insert(string text, sNode *&p) {
    bool rc = false;
    if(p) {
	if(p->text > text) {
	    rc = insert(text, p->left);
	} else if(p->text < text) {
	    rc = insert(text, p->right);
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
bool sBST::remove(string text, sNode *&p) {
    bool rc = false;
    if (p) {
	if (p->text > text) {
	    rc = remove(text, p->left);
	} else if (p->text < text) {
	    rc = remove(text, p->right);
	} else {
	    rc = true;
	    if ((!p->left) && (!p->right)) {
		delete p;
		p = NULL;
		treeCount--;
	    } else if (!p->right) {
		sNode *p2 = p->left;
		delete p;
		p = p2;
		treeCount--;
	    } else {
		p->text = findMin(p->right);
		remove(p->text, p->right);
	    }
	}
    }
    return(rc);
}


// findMin

string sBST::findMin(sNode *p) {
    string rc;
    if (p->left) {
    	rc = findMin(p->left);
    } else {
    rc = p->text;
    }
    return(rc);
}



//******************************************************************************
// Aidan Wright

bool sBST::isIn(string text) const {
    return(isIn(text, root));
}


bool sBST::isIn(string text, sNode *p) const {
    bool rc = false;
    if (p) {
	if (p->text < text) {
	    rc = isIn(text, p->right);
	} else if (p->text > text) {
	    rc = isIn(text, p->left);
	} else {
	    rc = true;
	}
    }
    return(rc);
}

//******************************************************************************
// Aidan Wright

void sBST::clear() {
    clear(root);
    treeCount = 0;
}

void sBST::clear(sNode *&p) {
    if (p) {
	clear(p->right);
	clear(p->left);
	delete p;
	p = NULL;
    }
}

//******************************************************************************
// Aidan Wright

// printIt public
void sBST::printIt() const {
    printIt(root);
}

// print private

void sBST::printIt(sNode *p) const {
    if (p) {
	if (p->left != NULL) {
	    printIt(p->left);
	}
	cout << p->text << "\n";
	if (p->right != NULL) {
	    printIt(p->right);
	}
    }
}

// Aidan Wright
// count
int sBST::count() const {
    return(treeCount);
}
