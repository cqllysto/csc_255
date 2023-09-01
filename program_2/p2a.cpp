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
    int rc = -1;
    if (pn) {
	if (pn->text != text) {
	    rc = getIndex(text, pn->next, index + 1);
	} else {
	    rc = index;
	}
    }
    return(rc);
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
	pn = NULL;
    }
}

//******************************************************************************
//Andrew Chapuis

bool stringLinkedList::insert(string text) {
    bool rc = false;
    first = new node(text, first);
    if (listCount == 0) {
	last = first;
    }
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

bool stringLinkedList::insertAt(int index, string text){
    bool rc = false;
    node *p = new node(text, NULL);
    
    if ((index >= 0) && (index <= listCount)) {
	// case 1: index is set to the middle
	if ((listCount) && (index < listCount) && (index > 0)) {
	    node *q;
	    q = first;
	    
	    for (int ind = 0; ind < index - 1, ind++;) {
		q = q->next;
	    }
	    p->next = q->next;
	    q->next = p;
	} else if ((index == 0) && (listCount)) {
	    p->next = first;
	    first = p;
	} else if (index == listCount){
	    last->next = p;
	    last = p;
	} else {
	    first = p;
	    last = p;
	}
	rc = true;
	listCount++;
    }
    return(rc);
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
    return(getIndex(text, first, 0));
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
