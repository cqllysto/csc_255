//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/2023

#include <iostream>
#include "p2.h"

using namespace std;

//******************************************************************************
// stringLinkedList constructor
stringLinkedList::stringLinkedList(){
    first = NULL;
    last = NULL;
    listCount = 0;
}

//******************************************************************************
// node constructor
node::node(string text, node *next){
    this->text = text;
    this->next = next;
}

//******************************************************************************
// stringLinkedList destructor
stringLinkedList::~stringLinkedList(){
    clear(first);
}

//******************************************************************************
bool stringLinkedList::insert(string text){
    //allocate new node and assign data
    //then make *next point to the first/head of the linked list
    //change the *first/head pointer to point to the new node
    // corner cases: if list is empty, if list contains >= 1 node
    bool rc = true;
    first = new node(text, first);
    
    if (listCount == 0) {
	last = first;
    }

    listCount++;
    return(rc);
}


//******************************************************************************
// add: creates a new node and adds it onto the end of the list
// all cases: adding to a list containing at least one node,
// adding to an empty list, if list is full
bool stringLinkedList::add(string text){
    bool rc = true;
    // assign a pointer that points to the new node
    node *p = new node(text);
    if (listCount){
	// change the last node's pointer to point to the new node
	// instead of pointing to null
	last->next = p;
    } else {
	// assign the first pointer to point to the new node
	first = p;
    }
    // change the last pointer to now point to the new node
    last = p;
    listCount++;
    return (rc);
}

//******************************************************************************
// insertAt: inserts the string at index and returns true
// cases: 
// index is invalid (out of bounds of listCount)
// list is empty
// index is set to the beginning
// index is set to the end
// index is set to the middle
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
	} else if ((index = 0) && (listCount)) {
	    p->next = first;
	    first = p;
	} else if (index = listCount){
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
// public
void stringLinkedList::printIt() const{
    printIt(first, 0);
}

//******************************************************************************
// private
void stringLinkedList::printIt(node *p, int index) const{
    if(p){
	cout << "At pos " << index << " there is " << p->text << "\n";
	printIt(p->next, index + 1);
    }
}

//******************************************************************************
int stringLinkedList::count() const{
    return(listCount);
}

//******************************************************************************
// public clear
void stringLinkedList::clear(){
    clear(first);
    last = first = NULL;
    listCount = 0;
}

//******************************************************************************
// private clear
void stringLinkedList::clear(node *p){
    if (p) {
	clear(p->next);
	delete p;
	p = NULL;
    }
}


//******************************************************************************
int stringLinkedList::getIndex(string text) const{
    return(getIndex(text, first, 0));
}

//******************************************************************************
int stringLinkedList::getIndex(string text, node *p, int index) const {
    int rc = -1;
    if(p) {
	if (p->text == text){
	    rc = index;
	} else {
	    rc = getIndex(text, p->next, index + 1);
	}
    }
    return(rc);
}

//******************************************************************************
// p2b problems
bool stringLinkedList::deleteAt(int index, string &text){
    return(false);
}

//******************************************************************************
bool stringLinkedList::readAt(int index, string &text) const {
    return(false);
}
