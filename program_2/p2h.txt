//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#ifndef __P2_H
#define __P2_H

#include <string>

//******************************************************************************
//Aidan Wright
class stringLinkedList;

//******************************************************************************
//Aidan Wright
class node {
    private:
	node(std::string text = "", node *pn = NULL);

	std::string text;
	node *next;

	friend class stringLinkedList;
};

//******************************************************************************
//Andrew Chapuis
class stringLinkedList {
    private:
	node *first, *last;
	int listCount;
	
	int getIndex(std::string text, node *pn, int index) const;
	void printIt(node *pn, int index) const;
	void clear(node *pn);
    public:
	stringLinkedList();
	~stringLinkedList();

	//Modifying Functions
	bool insert(std::string text);
	bool add(std::string text);
	bool insertAt(int index, std::string text);
	bool deleteAt(int index, std::string &text);
	bool readAt(int index, std::string &text) const;
	void clear();

	//Non-modifying Functions
	int getIndex(std::string text) const;
	void printIt() const;
	int count() const;
};

#endif
