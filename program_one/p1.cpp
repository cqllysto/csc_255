//Name:Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 1
//Date: 08/28/23

#include <iostream>   // gets cin, cout, cerr
#include <fstream>    // gets file functions of open and close
#include <string.h>   // gets the string type, which is part of std namespace

#include "p1.h"

using namespace std;



//******************************************************************************
//Aidan Wright

// Constructor
stringList::stringList(int listCapacity){
    this->listCapacity = listCapacity;
    a = new string[listSize];
}

//******************************************************************************
//Aidan Wright

// Destructor
stringList::~stringList(){
    if(a){
        delete []a;
	a = NULL;
    }
}


//******************************************************************************
//Aidan Wright

bool stringList::readAt(int index, string &text){
    bool rc = FALSE;
    if (index >= 0) && (index < listSize){
        text = a[index];
	rc = TRUE;
    }
    return(rc);
}

//******************************************************************************
//Aidan Wright

int stringList::count(){
   return(listSize)
}


//******************************************************************************
//Aidan Wright

bool stringList::add(string text){
    bool rc = FALSE;    
    a[listSize] = text; 
    if (a[listSize] == text){
        rc = TRUE;
	listSize++;
    }
    return(rc);
}

