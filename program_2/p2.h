//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#ifndef __P2_H
#define __P2_H

#include <string>

//******************************************************************************

class stringLinkedList;

//******************************************************************************

class node {
    private:
	node(std::string text, node *pn);

	std::string text;
	node *next;
}

//******************************************************************************

class stringLinkedList {
    private:
	node *first, *last;

