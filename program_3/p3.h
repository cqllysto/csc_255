//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 3
//Date: 09/11/23

#ifndef __P3_H
#define __P3_H

#include <string>

class cStringList {
    private:
	//These are the private variables of the class
	std::string *a;
	int listCapacity;
	int listCount;
	int first;
	int last;

	//These are the private functions of the class
	void incVal(int &value);
	void decVal(int &value);

    public:
	//These are the constructor and destructor of the class
	cStringList(int capacity = 100);
	~cStringList();

	//These are the modifying and non-modifying functions
	bool insert(std::string text);
	bool add(std::string text);
	bool insertAt(int index, std::string text);
	bool readAt(int index, std::string &text);
	bool deleteFirst(std::string &text);
	bool deleteLast(std::string &text);
	void clear();
	int count() const;
	int getIndex(std:string text) const;
	void printIt() const;
};

#endif
