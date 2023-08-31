//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/2023

#include <iostream>
#include "p2.h"

using namespace std;

//******************************************************************************
// Aidan Wright

stringLinkedList::stringLinkedList(){
    *first = NULL;
    *last = NULL;
    int listCount = 0;
}

node::node(string text, node *next){
    this->text = text;
    this->next = next;
};

bool stringLinkedList::insert(string text){
    //allocate new node and assign data
    //then make *next point to the first/head of the linked list
    //change the *first/head pointer to point to the new node
    bool rc = false;
    
    node *p = new node;
    node(text){
    
    };

    new_node->text = text;
    new_node->*next = *first;
    *first = *new_node;
    
    if (*first->text = text){
	rc = true;
    }
    
    return(rc)
};

bool stringLinkedList::add(string text){
    // make new node, then assign *next of previous node to 
    // current node instead of null
    // update *last to point to added node
    
    node *p = new node(text);
    if (listCount) {
	last->next = p;
    } else {
	first = p;
    };

    last = p;
    bool rc = false;
};

// add: creates a new node and adds it onto the end of the list
// all cases: adding to a list containing at least one node,
// adding to an empty list
bool stringLinkedList::add(string text){
    bool rc = TRUE;
    // assign a pointer that points to the new node
    node *p = new node(text);
    if (listCount){
	// change the last node's pointer to point to the new node
	// instead of pointing to null
	last->next = p;
    } else {
	// assign the first pointer to point to the new node
	first = p;
    };
    // change the last pointer to now point to the new node
    last = p;
    return (rc)


};

void stringLinkedList::clear(){
    listCount = 0;
};
