// Name: Andrew Chapuis and Aidan Wright
// Course: CSC 255
// Program 3
// Date: 09/11/2023

#ifndef __P3_H
#define __P2_H

#include <string>

class cStringList {
    private:
	std::string *a;
	int listCapacity;
	int listCount;
	int first
	int last

	void incVal(int &value);
	void decVal(int &value);

    public:
	cStringList(int listCapacity = 100);
	~cStringList();

	bool insert(std::string text);
	bool add(std::string text);
	bool insertAt(int index, std::string &text);
	bool deleteAt(int index, std::string &text);
	bool readAt(int index, std::string &text);
	bool deleteFirst(std::string &text);
	bool deleteLast(std::string &text);
	void clear();
	int count();
	int getIndex(std::string text) const;
	void printIt() const;
}

#endif
