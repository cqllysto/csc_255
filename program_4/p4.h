//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 4
//Date: 09/18/23

#ifndef __P4_H
#define __P4_H

#include <string>

class sBST;

class sNode {
    private:
	sNode(std::string text = "");

	std::string text;
	int h;
	sNode *left, *right;

	friend class sBST;
};

class sBST {
    private:
	int treeCount;
	sNode *root;

	std::string findMin(sNode *p);
	bool insert(std::string text, sNode *&p);
	bool remove(std::string text, sNode *&p);
	bool isIn(std::string text, sNode *p) const;
	void printIt(sNode *p) const;
	void clear(sNode *&p);
	
    public:
	sBST();
	~sBST();
	bool insert(std::string text);
	bool remove(std::string text);
	bool isIn(std::string text) const;
	void printIt() const;
	int count() const;
	void clear();
};

#endif
