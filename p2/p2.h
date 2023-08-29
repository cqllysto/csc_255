//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 2
//Date: 09/01/23

#ifndef __P1H
#define __P1H

#include <string>

class sLL;

class node {
    private:
	std::string *text;
	node *next;
	node(string text = “”, node *pn = NULL);	
    friend class sLL;
}

class stringLinkedList {
    private:
	node *first;
	node *last;
	int listCount();
	int getIndex(std::string text, node *pn, int index) const;
	void printIt(node *pn, int index) const;
	void clear(node *pn);

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
	void printIT() const;
	int count() const; //counts the the size of the list
};

#endif

