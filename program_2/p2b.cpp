//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#include <iostream>   // gets cin, cout, cerr
#include "p2.h"

using namespace std;

//******************************************************************************
//Aidan Wright

//constructor for the node class
node::node(string text, node *pn) {
    this->text = text;
    next = pn;
}

//******************************************************************************
//Andrew Chapuis

//constructor for the stringLinkedList class
stringLinkedList::stringLinkedList() {
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
//Andrew Chapuis

//destructor for the stringLinkedList
stringLinkedList::~stringLinkedList() {
    clear(first);
}

//******************************************************************************
//Andrew Chapuis

//private method that will be used in a public getIndex method
//returns the location of the given text
int stringLinkedList::getIndex(string text, node *pn, int index) const {
    int rc = -1;
    if (pn) {
	//checks if the current text is equal to the given text, if not
	//goes to the next index
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

//private method that will be used in a public printIt method
//prints the entire list, one index at a time
void stringLinkedList::printIt(node *pn, int index) const {
    if (pn) {
	cout << "At pos " << index << " there is " << pn->text << "\n";
	printIt(pn->next, index + 1);
    }
}

//******************************************************************************
//Aidan Wright

//clears the entire list
void stringLinkedList::clear(node *pn) {
    if (pn) {
	clear(pn->next);
	delete pn;
	pn = NULL;
    }
}

//******************************************************************************
//Aidan Wright

//inserts a new node into the beginning of the list
bool stringLinkedList::insert(string text) {
    bool rc = false;
    first = new node(text, first);
    //in case the list is empty:
    if (listCount == 0) {
	last = first;
    }
    listCount++;
    rc = true;
    return(rc);
}

//******************************************************************************
//Andrew Chapuis

//adds a new node to the end of the list
bool stringLinkedList::add(string text) {
    bool rc = false;
    node *p = new node(text);
    //in case the list is empty
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
//Aidan Wright

//inserts a new node at the given index into the list
bool stringLinkedList::insertAt(int index, string text){
    bool rc = false;
    node *p = new node(text, NULL);
    //checks whether the index is out of bounds:
    if ((index >= 0) && (index <= listCount)) {
	//case: index is set to the middle
	if ((listCount) && (index < listCount) && (index > 0)) {
	    node *q;
	    q = first;
	    //make a new pointer called q and travese it through the list
	    //to point to the node just before the node at the index
	    for (int ind = 0; ind < index - 1; ind++) {
		q = q->next;
	    }
	    p->next = q->next;
	    q->next = p;
	//case: inserting at the beginning and there is a list
	} else if ((index == 0) && (listCount)) {
	    p->next = first;
	    first = p;
	//case: inserting at the end
	} else if (index == listCount){
	    last->next = p;
	    last = p;
	//case: the list is empty
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
//Aidan Wright


// cases:
// if index is out of bounds
// 	list is empty (nothing to delete)
// 	if list has one thing (no need to reassign first and last)
// 	if list has multiple nodes:
// 		delete the first node (reassign first to next)
// 		delete a middle node
// 		delete the last node (reassign last to previous)
bool stringLinkedList::deleteAt(int index, string &text) {
    bool rc = false;
    if ((index < listCount) && (index >= 0)) {
	rc = true;
	listCount--;
	// if the list has multiple nodes
	if (listCount > 1) {
	    // if deleting a node in the middle of the list
	    node *q;
	    q = first;
	    if ((index > 0) && (index < listCount - 1)) {
		node *r;
		for (int ind = 0; ind < index - 1; ind++) {
		    q = q->next;
		}
		r = q->next;
		q->next = q->next->next;
		text = r->text;
		delete r;
		r = NULL;
	    } else if (index == listCount - 1) { // deleting the last node
		for (int ind = 0; ind < index - 1; ind++) {
		    q = q->next;
		}
		last = q;
		text = q->text;
		delete q->next;
		q->next = NULL;
	    } else { // deleting the first node
		first = first->next;
		text = q->text;
		delete q;
		q = NULL;
	    }
	} else { // list has one node
	    text = first->text;
	    delete first;
	    first = last = NULL;
	}
    }
   return(rc);
}

//******************************************************************************
//Aidan Wright

//reads the text in the node at the given index
bool stringLinkedList::readAt(int index, string &text) const {
    bool rc = false;

    if ((index >= 0) && (index < listCount)) {
	rc = true;
	node *q;
	q = first;
	for (int ind = 0; ind < index; ind++) {
	    q = q->next;
	}
	text = q->text;
    }
    return(rc);
}

//******************************************************************************
//Andrew Chapuis

//recursively deletes the nodes from the list and resets the list variables
void stringLinkedList::clear() {
    clear(first);
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
//Andrew Chapuis

//public method of getIndex which recursively looks which node a text is in
int stringLinkedList::getIndex(string text) const {
    return(getIndex(text, first, 0));
}

//******************************************************************************
//Andrew Chapuis

//public method of printIt which will print the entire list
void stringLinkedList::printIt() const {
    printIt(first, 0);
}

//******************************************************************************
//Andrew Chapuis

//returns the number of nodes in the list
int stringLinkedList::count() const {
    return(listCount);
}

