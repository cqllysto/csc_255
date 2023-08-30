//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#include <iostream>   // gets cin, cout, cerr
#include "p2.h"

using namespace std;

//******************************************************************************
//Andrew Chapuis

node::node(string text, node *pn) {
    this->text = text;
    this->pn = pn;
}

//******************************************************************************
//Andrew Chapuis

stringLinkedList::stringLinkedList() {
    *first = NULL;
    *last = NULL;
    listCount = 0;
}

//******************************************************************************
//Andrew Chapuis

~stringLinkedList::stringLinkedList() {
    clear(first);
}

//******************************************************************************
//Andrew Chapuis

int stringLinkedList::getIndex(string text, node *pn, int index) const {
    if (pn.text != text) {
	index = getIndex(text, pn->next, index++);
    }
    return index;
}

//******************************************************************************
//Andrew Chapuis

void stringLinkedList::printIt(node *pn, int index) const {
    if (pn) {
	cout << "At pos " << index << " there is " << pn.text << "\n";
	printIt(pn->next, index++);
    }
}

//******************************************************************************
//Andrew Chapuis

void stringLinkedList::clear(node *pn) {
    if (pn) {
	clear(pn->next);
	delete pn;
    }
}

//******************************************************************************
//Andrew Chapuis

bool stringLinkedList::insert(string text) {
    bool rc = false;
    node *p = new node(text, first);
    if (listCount == 0) {
	last = p;
    }
    first = p;
    listCount++;
    rc = true;
    return(rc);
}

//******************************************************************************
//Andrew Chapuis

bool add(string text) {
    bool rc = false;
    node *p = new node(text);
    if (listCount == 0) {
	first = p;
    } else {
	last->next = p;
    }
    last = p;
    listCount++;
    rc = true;
    return(rc);
}

//******************************************************************************
//Andrew Chapuis

bool insertAt(int index, string text) {

}

//******************************************************************************
//Andrew Chapuis

bool deleteAt(int index, string &text) {
    return(false);
}

//******************************************************************************
//Andrew Chapuis

bool readAt(int index, string &text) const {
    return(false);
}

//******************************************************************************
//Andrew Chapuis

void clear() {
    clear(first);
    first = NULL;
    last = NULL;
    listCount = 0;
}
