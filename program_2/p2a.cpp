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
    this -> text = text;
    this -> pn = pn;
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
    int ind = 0;
    if (pn.text != text) {
	getIndex(text, pn -> next);
	ind++;
    }
    index = ind;
    return index;
}
