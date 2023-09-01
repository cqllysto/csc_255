//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#ifndef __P2_H
#define __P2_H

#include <string>

class stringLinkedList;

class node {
    private:
	node(std::string text = "", node *p = NULL);	
	std::string text;
	node *next;
	friend class stringLinkedList;
};

class stringLinkedList {
    private:
	node *first, *last;
	int listCount;
	int getIndex(std::string text, node *p, int index) const;
	void printIt(node *p, int index) const;
	void clear(node *p);

    public:
        stringLinkedList(); //constructor
        ~stringLinkedList(); //destructor

        bool insert(std::string text); //inserts a text into beginning of list
        bool add(std::string text); //adds a text to the end of the list
        bool insertAt(int index, std::string text); //inserts text at given index
        bool deleteAt(int index, std::string &text); //deletes text at given index
        bool readAt(int index, std::string &text) const; //reads the text at given index
        void clear();

	int getIndex(std::string text) const;
	void printIt() const;
	int count() const; //counts the the size of the list
};

#endif

