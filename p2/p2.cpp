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

bool stringLinkedList::insert(string text){
    //allocate new node and assign date
    //then make *next point to the first/head of the linked list
    //change the *first/head pointer to point to the new node
    bool rc = false;
    
    node new_node;
    new_node.text = text;
    new_node.next = *first;
    *first = *new_node;
    
    if (a[0] = text){
	rc = true;
    }
    
    return(rc)
};

bool stringLinkedList::add(string text){
    bool rc = false;

    // make new node, then assign *next of previous node to 
    // current node instead of null
    // update *last to point to added node
    node a;
    a.next = NULL;
    a[count - 1].next = *a;
    *last = *a;`
};

void stringLinkedList::clear(){
    listCount = 0;
};
