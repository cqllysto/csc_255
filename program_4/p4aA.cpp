// Name: Andrew Chapuis and Aidan Wright
// Team 3
// Course: CSC 255
// Program 4
// Date: 09/18/23

#include <iostream>   // gets cin, cout, cerr
#include "p4.h"

using namespace std;

//******************************************************************************
// Andrew Chapuis

sNode::sNode(string txt) {
    text = txt;
    left = right = NULL;
    h = 0;
}

//******************************************************************************
// Andrew Chapuis

sBST::sBST() {
    treeCount = 0;
    root = NULL;
}

//******************************************************************************
// Andrew Chapuis

sBST::~sBST() {
    clear(root);
}

//******************************************************************************
// Andrew Chapuis

string sBST::findMin(sNode *ptr) {
    string rc;
    if (ptr) {
	if (ptr->left) {
	    findMin(ptr->left);
	} else {
	    rc = ptr->text;
	}
    }
    return(rc);
}

//******************************************************************************
// Andrew Chapuis

bool sBST::insert(string text, sNode *p) {
    bool rc = false;
    if (p) {
	if (p->text > text) {
	    rc = insert(text, p->left);
	} else if (p->text < text) {
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
// Andrew Chapuis

bool sBST::remove(string text, sNode *p) {
    bool rc = false;
    if (p) {
	if (p->text > text) {
	    rc = remove(text, p->left);
	} else if (p->text < text) {
	    rc = remove(text, p->right);
	} else {
	    rc = true;
	    if (!p->left && !p->right) {
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

//******************************************************************************
// Andrew Chapuis

bool sBST::isIn(string text, sNode *p) const {
    bool rc = false;
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

void sBST::printIt(sNode *p) const {
     if (p) {
	printIt(p->left);
	cout << p->text << "\n";
	printIt(p->right);
     }
}

//******************************************************************************
// Andrew Chapuis

void sBST::clear(sNode *p) {
    if (p) {
	clear(p->left);
	clear(p->right);
	delete p;
	p = NULL;
    }
}

//******************************************************************************
// Andrew Chapuis

bool sBST::insert(string text) {
    return(insert(text, root));
}

//******************************************************************************
// Andrew Chapuis

bool sBST::remove(string text) {
    return(remove(text, root));
}

//******************************************************************************
// Andrew Chapuis

bool sBST::isIn(string text) const {
    return(isIn(text, root));
}

//******************************************************************************
// Andrew Chapuis

void sBST::printIt() const {
    printIt(root);
}

//******************************************************************************
// Andrew Chapuis

int sBST::count() const {
    return(treeCount);
}

//******************************************************************************
// Andrew Chapuis

void sBST::clear() {
    clear(root);
    treeCount = 0;
}
