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
    next = pn;
}

//******************************************************************************
//Andrew Chapuis

stringLinkedList::stringLinkedList() {
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
//Andrew Chapuis

stringLinkedList::~stringLinkedList() {
    clear(first);
}

//******************************************************************************
//Andrew Chapuis

int stringLinkedList::getIndex(string text, node *pn, int index) const {
    if (pn) {
	if (pn->text != text) {
	    index = getIndex(text, pn->next, index + 1);
	}
    }
    return index;
}

//******************************************************************************
//Andrew Chapuis

void stringLinkedList::printIt(node *pn, int index) const {
    if (pn) {
	cout << "At pos " << index << " there is " << pn->text << "\n";
	printIt(pn->next, index + 1);
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

bool stringLinkedList::add(string text) {
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

bool stringLinkedList::insertAt(int index, string text) {
    return(false);
}

//******************************************************************************
//Andrew Chapuis

bool stringLinkedList::deleteAt(int index, string &text) {
    return(false);
}

//******************************************************************************
//Andrew Chapuis

bool stringLinkedList::readAt(int index, string &text) const {
    return(false);
}

//******************************************************************************
//Andrew Chapuis

void stringLinkedList::clear() {
    clear(first);
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
//Andrew Chapuis

int stringLinkedList::getIndex(string text) const {
    return(-1);
}

//******************************************************************************
//Andrew Chapuis

void stringLinkedList::printIt() const {
    printIt(first, 0);
}

//******************************************************************************
//Andrew Chapuis

int stringLinkedList::count() const {
    return(listCount);
}
