//Name: Andrew Chapuis and Aidan Wright
//Course: CSC 255
//Program 4
//Date: 09/18/23

#ifndef __P4_H
#define __P4_H

#include <string>

class sNode {
    private:
	sNode(std::string text = "");

	std::string text;
	int h;
	sNode *left, *right;

    friend sBST;
};

#endif
